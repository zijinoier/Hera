#include <QCoreApplication>
#include <iostream>
#include <QCommandLineParser>
#include "visionmodule.h"
#include "log_slider.h"
#include "logreader_global.h"
#include "netreceive.h"
#include "netreceive_global.h"
#include "Windows.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCommandLineOption inputOption(QStringList() << "i" << "I", "", "inputoption", "lr");
    QCommandLineOption logFileName("if", "", "logfilename", "");
    QCommandLineOption outputOption(QStringList() << "o" << "O", "", "outputoption", "lw");
    QCommandLineOption outFileName("of", "", "outfilename", "test.zlog");
    QCommandLineOption cameraNumber("cn", "", "cameranumber", "8");

    QCommandLineParser parser;
    parser.addOption(inputOption);
    parser.addOption(logFileName);
    parser.addOption(outputOption);
    parser.addOption(outFileName);
    parser.addOption(cameraNumber);
    parser.process(a);

//    qDebug() << parser.value(inputOption);
//    qDebug() << parser.value(logFileName);
//    qDebug() << parser.value(outputOption);
//    qDebug() << parser.value(outFileName);
//    qDebug() << parser.value(cameraNumber);

    if (parser.value(cameraNumber) == "4") {
        qDebug() << "Camera number now is 4";
    } else if (parser.value(cameraNumber) == "8") {
        qDebug() << "Camera number now is 8";
    } else {
        qDebug() << "Unavailable camera number";
    }

    VisionModule vm;

    if (parser.value(outputOption) == "lw") {
        qDebug() << "The output device is logwriter. The out file name is" << parser.value(outFileName);
        vm.flag = 0;
        vm.lw_v.setFileName(parser.value(outFileName));
        vm.lw_rfb.setFileName(parser.value(outFileName).append("rfb"));
    } else if (parser.value(outputOption) == "ns") {
        qDebug() << "The output device is netsend.";
        vm.flag = 1;
    } else {
        qDebug() << "Unknown command";
    }
    if (parser.value(inputOption) == "lr") {
        qDebug() << "The input device is logreader. The log file name is" << parser.value(logFileName);
        LogSlider ls;
        ls.loadFile(parser.value(logFileName));
        int m_currentFrame = 0;
        int size = ls.m_player.packets.size();
        while (++m_currentFrame < size) {
            Frame* packet = ls.m_player.packets.at(m_currentFrame);
            if (packet->type == MESSAGE_BLANK) {
                // ignore
            } else if (packet->type == MESSAGE_UNKNOWN) {
                std::cout << "Error unsupported or corrupt packet found in log file!" << std::endl;
            } else if (packet->type == MESSAGE_SSL_VISION_2010 || packet->type == MESSAGE_SSL_VISION_2014) {
                vm.parse((void *)packet->data.data(), packet->data.size());
            } else if (packet->type == MESSAGE_SSL_REFBOX_2013) {
                QByteArray buffer;
                buffer.append(packet->time);
                buffer.append(packet->data.data());
                vm.lw_rfb.write(buffer);
            } else {
                std::cout << "Error unsupported message type found in log file!" << std::endl;
            }
            std::cout << m_currentFrame + 1 << "/" << size << "\r";
        }
    } else if (parser.value(inputOption) == "nr") {
        qDebug() << "The input device is netreceive.";
        NetReceive nr;
        while (true) {
            nr.storeData();
//            qDebug() << "main" <<nr.datagrams.isEmpty();
            while (!nr.datagrams.isEmpty()) {
//                qDebug() << "Ah! There is something catched by me.";
                QByteArray datagram = nr.datagrams.dequeue();
                vm.parse((void*)datagram.data(), datagram.size());
            }
            Sleep(5);
        }
    } else {
        qDebug() << "Unknown command";
    }

//    return a.exec();

    a.exit(0);
}



