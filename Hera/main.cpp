#include <QCoreApplication>
#include <iostream>
#include <QCommandLineParser>
#include <QDir>
#include <QFileInfoList>
#include <QStringList>
#include "parammanager.h"
#include "visionmodule.h"
#include "log_slider.h"
#include "logreader_global.h"
#include "netreceive.h"
#include "netreceive_global.h"
#include "Windows.h"
#include "staticparams.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCommandLineOption logFileName("if", "", "logfilename", "");
    QCommandLineOption logFileDir("id", "", "logfiledir", "");
    QCommandLineOption outFileName("of", "", "outfilename", "test.zlog");
    QCommandLineOption outFileDir("od", "", "outfiledir", "../bin/");

    QCommandLineParser parser;
    parser.addOption(logFileName);
    parser.addOption(logFileDir);
    parser.addOption(outFileName);
    parser.addOption(outFileDir);

    parser.process(a);

//    qDebug() << parser.value(inputOption);
//    qDebug() << parser.value(logFileName);
//    qDebug() << parser.value(outputOption);
//    qDebug() << parser.value(outFileName);
//    qDebug() << parser.value(cameraNumber);

    VisionModule vm;

    //input
    qDebug() << "The input device is logreader.";
    LogSlider ls;

    //判断读取log文件的方式
    int cycle1 = 1;
    QStringList m_logfile;
    if (parser.value(logFileDir) == NULL) {//单个log文件读取
        m_logfile.append(parser.value(logFileName));
    } else {//log批量读取
        QDir inputDir;
        inputDir.setPath(parser.value(logFileDir));
        inputDir.setFilter(QDir::Files);
        QFileInfoList logList = inputDir.entryInfoList();
        for (int k = 0; k<logList.size(); k++)
            m_logfile.append(parser.value(logFileDir).append("/") + logList.at(k).fileName());
        cycle1 = logList.size();
    }

    //读取文件
    for(int i=0; i<cycle1; i++) {
        QString m_realLogfile = m_logfile.at(i);
        if (ls.loadFile(m_realLogfile)) {
            qDebug() << "Load success! The log file is" << m_logfile.at(i);
        } else {
            qDebug() << "Load failed! Please check your DIR or FILENAME.";
            break;
        }
        QString outFileName = m_logfile.at(i);
        int a = outFileName.lastIndexOf("/");
        outFileName.replace(0, a+1, parser.value(outFileDir) + "/");


//        vm.filename = outFileName.replace(".log.gz", "_end_0.zlog");
        vm.lw_v.setFileName(outFileName.replace(".log.gz","_pass.zlog"));
        vm.passCount = 0;

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
//                if (vm.flag == 0) {
//                    QByteArray buffer;
//                    buffer.append(packet->time);
//                    buffer.append(packet->data.data());
//                    vm.lw_rfb.write(buffer);
//                }
            } else {
                std::cout << "Error unsupported message type found in log file!" << std::endl;
            }
            std::cout << m_currentFrame + 1 << "/" << size << "\r";
        }
        std::cout << "\nfinished" << std::endl;
    }
    qDebug() << "All tasks finished, please find results in" << parser.value(outFileDir);


//    return a.exec();

    a.exit(0);
}
