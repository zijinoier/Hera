#include <QCoreApplication>
#include <iostream>
#include <QCommandLineParser>
#include <QDir>
#include <QFileInfoList>
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

    QCommandLineOption inputOption(QStringList() << "i" << "I", "", "inputoption", "lr");
    QCommandLineOption logFileName("if", "", "logfilename", "");
    QCommandLineOption logFileDir("id", "", "logfiledir", "");
    QCommandLineOption outputOption(QStringList() << "o" << "O", "", "outputoption", "lw");
    QCommandLineOption outFileDir("od", "", "outfiledir", "");

    QCommandLineOption visionPort("p", "", "visionport", "10020");

    QCommandLineParser parser;
    parser.addOption(inputOption);
    parser.addOption(logFileName);
    parser.addOption(logFileDir);
    parser.addOption(outputOption);
    parser.addOption(outFileDir);
    parser.addOption(visionPort);

    parser.process(a);

//    qDebug() << parser.value(inputOption);
//    qDebug() << parser.value(logFileName);
//    qDebug() << parser.value(outputOption);
//    qDebug() << parser.value(outFileName);
//    qDebug() << parser.value(cameraNumber);

    VisionModule vm;
    if(parser.value(inputOption) == "nr") qDebug() << "Vision port is" << parser.value(visionPort).toInt();
    vm.vision_port = parser.value(visionPort).toInt();

    if (parser.value(outputOption) == "lw") {
        qDebug() << "The output device is logwriter.";
        vm.flag = 0;
//        vm.lw_v.setFileName(parser.value(outFileName));
//        vm.lw_rfb.setFileName(parser.value(outFileName).append("rfb"));
    } else if (parser.value(outputOption) == "ns") {
        qDebug() << "The output device is netsend.";
        vm.flag = 1;
    } else {
        qDebug() << "Unknown command. You can get more imformation from README.md";
    }

    if (parser.value(inputOption) == "lr") {
        qDebug() << "The input device is logreader.";
        LogSlider ls;

        //判断是否需要批量操作
        int cycle = 1;
        QStringList m_logfile;
        if (parser.value(logFileDir) == NULL) {
            m_logfile.append(parser.value(logFileName));
        } else {
            QDir inputDir;
            inputDir.setPath(parser.value(logFileDir));
            inputDir.setFilter(QDir::Files);
            QFileInfoList logList = inputDir.entryInfoList();
            for (int k = 0; k<logList.size(); k++) m_logfile.append(parser.value(logFileDir).append("/") + logList.at(k).fileName());
            cycle = logList.size();
        }
        for(int i=0; i<cycle; i++) {
            if (ls.loadFile(m_logfile.at(i))) {
                qDebug() << "Load success! The log file is" << m_logfile.at(i);
                if (vm.flag == 0) {
                    QString outFileName = m_logfile.at(i);
                    outFileName.replace(parser.value(logFileDir), parser.value(outFileDir));
                    vm.lw_v.setFileName(outFileName.replace("log.gz", "zlog"));
                    vm.lw_rfb.setFileName(outFileName.replace(".zlog","_rfb.zlog"));
                }
            } else {
                qDebug() << "Load failed! Please check your DIR or FILENAME.";
                break;
            }
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
                    if (parser.value(outputOption) != "ns") {
                        QByteArray buffer;
                        buffer.append(packet->time);
                        buffer.append(packet->data.data());
                        vm.lw_rfb.write(buffer);
                    }
                } else {
                    std::cout << "Error unsupported message type found in log file!" << std::endl;
                }
                if (parser.value(outputOption) == "ns") {
                    Sleep(1000/60);
                }
                std::cout << m_currentFrame + 1 << "/" << size << "\r";
            }
            std::cout << "\nfinished" << std::endl;
        }
        qDebug() << "All tasks finished, please find results in" << parser.value(outFileDir);
    } else if (parser.value(inputOption) == "nr") {
        qDebug() << "The input device is netreceive.";
        NetReceive nr;
        //UDP can't work with dll, so force cycle SLOT function.
        while (true) {
            nr.storeData();
            while (!nr.datagrams.isEmpty()) {
                QByteArray datagram = nr.datagrams.dequeue();
                vm.parse((void*)datagram.data(), datagram.size());
                std::cout << "Some data was gotten from UDP." << "\r";
            }
            Sleep(5);
            std::cout << "Nothing from UDP" << "\r";
        }
    } else {
        qDebug() << "Unknown command. You can get more imformation from README.md";
    }

//    return a.exec();

    a.exit(0);
}



