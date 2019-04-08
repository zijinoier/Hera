#ifndef __VISIONMODULE_H__
#define __VISIONMODULE_H__

#include <QObject>
#include <QUdpSocket>
#include "dataqueue.hpp"
#include "singleton.hpp"
#include "ballrecords.h"
#include "vision_detection.pb.h"
#include "passpackage4RL.pb.h"
#include "staticparams.h"
#include "messageformat.h"
#include "globalsettings.h"
#include "dealball.h"
#include "dealrobot.h"
#include "maintain.h"
#include "logwriter.h"
#include "logwriter_global.h"
#include "netsend.h"
#include "netsend_global.h"
#include "ballstate.h"

enum ballState {received,
                touched,
                kicked,
                struggle,
                chip_pass,
                flat_pass};

class VisionModule : public QObject {
    Q_OBJECT
  public:
    VisionModule(QObject *parent = 0);
    bool parse(void *, int);

    QString filename;
    int flag = 0;
    int vision_port;

    LogWriter lw_v;
    LogWriter lw_rfb;
    NetSend ns;
    int passCount;

    //暂时先作为public处理
    DataQueue<ReceiveVisionMessage> camera[PARAM::CAMERA];
    DataQueue<ReceiveVisionMessage> maintain = 600;
    DataQueue<ReceiveVisionMessage> processBall;
    DataQueue<ReceiveVisionMessage> processRobot;
    DataQueue<BallRecord> ballrecords;
    DataQueue<ReceiveVisionMessage> chipJudge ;
    SingleCamera cameraMatrix[PARAM::CAMERA];
    ballState ballStateMachine;
    bool cameraUpdate[PARAM::CAMERA] = {false, false, true, true, true, true, true, true};
    int lastTouch;
    double lastPossible, currentPossible;

    PassPackages4RL packages4RL;

  private:
    bool collectNewVision();
    bool dealWithData();
    CGlobalSettings globalsetting;

    PassPackage4RL* package4RL;
    Vision_DetectionFrame* passBegin;
    Vision_DetectionFrame* passEnd;
    Vision_DetectionBall* detectionBall;
//    Vision_DetectionBall* detectionBallBegin;
//    Vision_DetectionBall* detectionBallEnd;
    Vision_DetectionRobot* detectionRobot[2][PARAM::ROBOTMAXID];

    QString pBallState;
    QString lastpBallState;
    bool needNewFile;
    bool writebegin;
    bool writeend;
    Ballstate ballState4Log;


    void setCameraMatrix();
    bool toProtobuf();

    CDealBall dealBall;
    CDealRobot dealRobot;
    CMaintain cmaintain;
};
#endif // __VISIONMODULE_H__
