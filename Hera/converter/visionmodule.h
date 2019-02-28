#ifndef __VISIONMODULE_H__
#define __VISIONMODULE_H__

#include <QObject>
#include <QUdpSocket>
#include "dataqueue.hpp"
#include "singleton.hpp"
#include "ballrecords.h"
#include "vision_detection.pb.h"
#include "staticparams.h"
#include "messageformat.h"
#include "globaldata.h"
#include "globalsettings.h"
#include "dealball.h"
#include "dealrobot.h"
#include "maintain.h"
#include "logwriter.h"
#include "logwriter_global.h"
#include "netsend.h"
#include "netsend_global.h"

class VisionModule : public QObject {
    Q_OBJECT
  public:
    VisionModule(QObject *parent = 0);
    void parse(void *, int);

    QString filename;
    int flag = 0;

    LogWriter lw_v;
    LogWriter lw_rfb;
    NetSend ns;

    //暂时先作为public处理
    DataQueue<ReceiveVisionMessage> camera[PARAM::CAMERA];
    DataQueue<ReceiveVisionMessage> maintain;
    DataQueue<ReceiveVisionMessage> processBall;
    DataQueue<ReceiveVisionMessage> processRobot;
    DataQueue<BallRecord> ballrecords;
    SingleCamera cameraMatrix[PARAM::CAMERA];
    ballState ballStateMachine;
    bool cameraUpdate[PARAM::CAMERA];
    bool cameraControl[PARAM::CAMERA];
    int lastTouch;
    double lastPossible, currentPossible;

  private:
    QUdpSocket udpReceiveSocket, udpSendSocket;
    QHostAddress groupAddress;
    int interface;
    int vision_port, zeus_port;
    int saoAction;
    bool collectNewVision();
    bool dealWithData();
    CGlobalSettings globalsetting;
    Vision_DetectionFrame detectionFrame;
    Vision_DetectionBall* detectionBall;
    Vision_DetectionRobot* detectionRobot[2][PARAM::ROBOTMAXID];



    void setCameraMatrix();
    void toProtobuf();

    CDealBall dealBall;
    CDealRobot dealRobot;
    CMaintain cmaintain;
};
#endif // __VISIONMODULE_H__
