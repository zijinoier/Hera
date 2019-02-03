#include "log_slider.h"
#include <QDebug>
#include <QDir>


LogSlider::LogSlider() {

}

void LogSlider::loadFile(QString filename) {
    m_currentFrame = 0;

//    QDir myDir(QDir::currentPath());

//    qDebug() << myDir;
//    filename = myDir.absolutePath() + "/2018-06-21_14-09_ZJUNlict-vs-CM.log.gz";
    filename = "2018-06-21_14-09_ZJUNlict-vs-CM.log.gz";
//    qDebug() << filename;
    int maxFrame;
    double duration;

    if (m_player.load(filename, maxFrame, duration)) {
        m_player.start(m_currentFrame);
    }
}

