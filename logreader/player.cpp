#include "player.h"
#include "timer.h"
#include <iostream>
#include <QFileInfo>
#include <QtDebug>

Player::Player() {
//    // create referee socket
//    Q_ASSERT(m_referee == NULL);
//    m_referee = new Network(QHostAddress("224.5.23.1"), 0, 10003);
//    m_referee->connect();

//    // create vision socket
//    Q_ASSERT(m_vision == NULL);
//    m_vision = new Network(QHostAddress("224.5.23.2"), 0, 10006);
//    m_vision->connect();

//    // create legacy vision socket
//    Q_ASSERT(m_legacyVision == NULL);
//    m_legacyVision = new Network(QHostAddress("224.5.23.2"), 0, 10005);
//    m_legacyVision->connect();
}

Player::~Player() {
    stop();

    qDeleteAll(packets);
    packets.clear();
}

bool Player::load(const QString& filename, int& maxFrame, double& duration) {
    QFileInfo fileInfo(filename);

    bool compressed = false;

    if (fileInfo.suffix() == "gz") {
        compressed = true;
    }

    LogFile file(filename, compressed);

    if (!file.openRead()) {
        return false;
    }

    qDeleteAll(packets);
    packets.clear();

    for (;;) {

        Frame* packet = new Frame;

        if (!file.readMessage(packet->data, packet->time, packet->type) ||
                packet->time == 0 || packet->type == 0) {
            delete packet;
            break;
        }

        packets.append(packet);
        //qDebug() << packet->time <<" "<<packet->type<< endl;
    }

    maxFrame = packets.size() - 1;
    duration = packets.last()->time - packets.first()->time;
    return true;
}

bool Player::start(int position) {
    qDebug() << "im started!";
    if (position > packets.size() - 1) {
        return false;
    }

    m_currentFrame = position;

    m_mayRun = true;
    QThread::start();

    return true;
}

void Player::stop() {
    qDebug() << "im stopped!";
    m_mayRun = false;
    wait();
}

bool Player::good() {
    return packets.size() > 0;
}

void Player::sendMessage(const Frame* packet) {
    if (packet->type == MESSAGE_BLANK) {
        // ignore
    } else if (packet->type == MESSAGE_UNKNOWN) {
        std::cout << "Error unsupported or corrupt packet found in log file!" << std::endl;
    } else if (packet->type == MESSAGE_SSL_VISION_2010 || packet->type == MESSAGE_SSL_VISION_2014) {
        vm.parse((void *)packet->data.data(), packet->data.size());
//        VisionModule::instance()->parse((void *)packet->data.data(), packet->data.size());
    } else if (packet->type == MESSAGE_SSL_REFBOX_2013) {
        //这个不经过convert发给后面
    } else {
        std::cout << "Error unsupported message type found in log file!" << std::endl;
    }
}

void Player::run() {
    sendMessage(packets.at(m_currentFrame));
    qDebug() << packets.size();

    while (m_mayRun && ++m_currentFrame < packets.size() && this->isRunning()) {
        Frame* packet = packets.at(m_currentFrame);

        sendMessage(packet);

        qDebug() << m_currentFrame;
            qDebug() << this->isRunning();
    }

    emit finished();
}
