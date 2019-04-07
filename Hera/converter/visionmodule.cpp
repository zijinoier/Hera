#include "visionmodule.h"
#include "montage.h"
#include "maintain.h"
#include "dealball.h"
#include "dealrobot.h"
#include "messages_robocup_ssl_wrapper.pb.h"
#include "parammanager.h"
#include <QElapsedTimer>
#include <QtDebug>

/**
 * @brief VisionModule consturctor
 * @param parent
 */
VisionModule::VisionModule(QObject *parent)
    : QObject(parent)
    , dealBall(this)
    , dealRobot(this)
    , cmaintain(this)
    , ballState4Log(this)
    , lastTouch(0)
    , passCount(0)
    , lastpBallState("other")
    , needNewFile(true)
    , writebegin(false)
    , writeend(false)
{

//    detectionBall   = detectionFrame.mutable_balls();
    setCameraMatrix();
}

bool VisionModule::dealWithData() {
    dealBall.run();
    dealRobot.run();
    cmaintain.run();
    //根据maintain[-500]塞reward

    if (maintain.validSize()>500) {
        ballState4Log.run(maintain);
        if (ballState4Log.ballState == _pass)
            pBallState = "pass";
        else pBallState = "other";
        if (toProtobuf()) return true;
    } else {
        return false;
    }
    return false;
}

bool VisionModule::parse(void * ptr, int size) {
    static SSL_WrapperPacket packet;
    ReceiveVisionMessage message;
    packet.ParseFromArray(ptr, size);
    if (packet.has_detection()) {
        const SSL_DetectionFrame& detection = packet.detection();
        message.camID = detection.camera_id();
        int ballSize = detection.balls_size();
        int blueSize = detection.robots_blue_size();
        int yellowSize = detection.robots_yellow_size();
        for (int i = 0; i < ballSize; i++) {
            const SSL_DetectionBall& ball = detection.balls(i);
            if (globalsetting.inChosenArea(CGeoPoint(ball.x(), ball.y()))) {
                message.addBall(CGeoPoint(ball.x(), ball.y()));
            }
        }
        for (int i = 0; i < blueSize; i++) {
            const SSL_DetectionRobot& robot = detection.robots_blue(i);
            if (globalsetting.inChosenArea(CGeoPoint(robot.x(), robot.y()))
                    && robot.robot_id() < 12) {
                message.addRobot(BLUE, robot.robot_id(), CGeoPoint(robot.x(), robot.y()), robot.orientation());
            }
        }
        for (int i = 0; i < yellowSize; i++) {
            const SSL_DetectionRobot& robot = detection.robots_yellow(i);
            if (globalsetting.inChosenArea(CGeoPoint(robot.x(), robot.y()))
                    && robot.robot_id() < 12) {
                message.addRobot(YELLOW, robot.robot_id(), CGeoPoint(robot.x(), robot.y()), robot.orientation());
            }
        }
        camera[message.camID].push(message);
        cameraUpdate[message.camID] = true;
//        qDebug() << message.camID;
    }
    if (collectNewVision()) {
//        std::fill_n(cameraUpdate, PARAM::CAMERA, false);
        std::fill_n(cameraUpdate, PARAM::CAMERA - 4, false);//fix camera 4 for 2017 log
        if (dealWithData()) return true;
    }
    return false;
}

/**
 * @brief judge if all needed camera vision is collected
 * @return
 */
bool VisionModule::collectNewVision() {
    for (int i = 0; i < PARAM::CAMERA; i++) {
        if (!cameraUpdate[i])
            return false;
    }
    return true;
}

void VisionModule::setCameraMatrix() {
     cameraMatrix[0].fillCenter(CGeoPoint(-3000,2250));
     cameraMatrix[1].fillCenter(CGeoPoint(3000,2250));
     cameraMatrix[2].fillCenter(CGeoPoint(-3000,-2250));
     cameraMatrix[3].fillCenter(CGeoPoint(3000,-2250));
     for (int i=0; i<PARAM::CAMERA;i++){
         cameraMatrix[i].leftedge.min=cameraMatrix[i].campos.x()-3300;
         cameraMatrix[i].leftedge.max=cameraMatrix[i].campos.x()-3000;
         cameraMatrix[i].rightedge.min=cameraMatrix[i].campos.x()+3300;
         cameraMatrix[i].rightedge.max=cameraMatrix[i].campos.x()+3000;
         cameraMatrix[i].downedge.min=cameraMatrix[i].campos.y()-2550;
         cameraMatrix[i].downedge.max=cameraMatrix[i].campos.y()-2250;
         cameraMatrix[i].upedge.min=cameraMatrix[i].campos.y()+2550;
         cameraMatrix[i].upedge.max=cameraMatrix[i].campos.y()+2250;
        }
    }

bool VisionModule::toProtobuf(){
//    qDebug() << needNewFile << "the last state is " <<lastpBallState  <<"and the current state is "<<pBallState;

    if (pBallState == "pass" && needNewFile) {
        package4RL = packages4RL.add_package();
        needNewFile = false;
        passCount++;
        ReceiveVisionMessage result = maintain[-500];
        passBegin       = package4RL->mutable_beginframe();

        detectionBall = passBegin->mutable_balls();
        if (result.ballSize > 0) {
            detectionBall->set_x(result.ball[0].pos.x());
            if (result.ball[0].pos.y() == 0) detectionBall->set_y(float(0.1));
            else detectionBall->set_y(result.ball[0].pos.y());//to fix a role match bug 2018.6.15
            CVector TransferVel(result.ball[0].velocity.x(), result.ball[0].velocity.y());
            detectionBall->set_vel_x(TransferVel.x());
            detectionBall->set_vel_y(TransferVel.y());
            detectionBall->set_valid(dealBall.getValid());
            detectionBall->set_last_touch(lastTouch);
            detectionBall->set_ball_state(ballStateMachine);
        } else {
            detectionBall->set_x(-32767);
            detectionBall->set_y(-32767);
        }
        for (int i = 0; i < result.robotSize[PARAM::BLUE]; i++) {
            if (i == PARAM::SENDROBOTNUM) break; //for sending MAX 8 car possible
            detectionRobot[PARAM::BLUE][i] = passBegin->add_robots_blue();
//            detectionRobot[PARAM::BLUE][i] = detectionFrame.add_robots_blue();
            detectionRobot[PARAM::BLUE][i]->set_x(result.robot[PARAM::BLUE][i].pos.x());
            detectionRobot[PARAM::BLUE][i]->set_y(result.robot[PARAM::BLUE][i].pos.y());
            detectionRobot[PARAM::BLUE][i]->set_orientation(result.robot[PARAM::BLUE][i].angle);
            detectionRobot[PARAM::BLUE][i]->set_robot_id(result.robot[PARAM::BLUE][i].id);
            detectionRobot[PARAM::BLUE][i]->set_confidence(1);
            CVector TransferVel(result.robot[PARAM::BLUE][i].velocity.x(), result.robot[PARAM::BLUE][i].velocity.y());
            detectionRobot[PARAM::BLUE][i]->set_vel_x(TransferVel.x());
            detectionRobot[PARAM::BLUE][i]->set_vel_y(TransferVel.y());
            detectionRobot[PARAM::BLUE][i]->set_rotate_vel(result.robot[PARAM::BLUE][i].rotateVel);
        }
        for (int i = 0; i < result.robotSize[PARAM::YELLOW]; i++) {
            if (i == PARAM::SENDROBOTNUM) break;
//            detectionRobot[PARAM::YELLOW][i] = detectionFrame.add_robots_yellow();
            detectionRobot[PARAM::YELLOW][i] = passBegin->add_robots_yellow();
            detectionRobot[PARAM::YELLOW][i]->set_x(result.robot[PARAM::YELLOW][i].pos.x());
            detectionRobot[PARAM::YELLOW][i]->set_y(result.robot[PARAM::YELLOW][i].pos.y());
            detectionRobot[PARAM::YELLOW][i]->set_orientation(result.robot[PARAM::YELLOW][i].angle);
            detectionRobot[PARAM::YELLOW][i]->set_robot_id(result.robot[PARAM::YELLOW][i].id);
            detectionRobot[PARAM::YELLOW][i]->set_confidence(1);
            CVector TransferVel(result.robot[PARAM::YELLOW][i].velocity.x(), result.robot[PARAM::YELLOW][i].velocity.y());
            detectionRobot[PARAM::YELLOW][i]->set_vel_x(TransferVel.x());
            detectionRobot[PARAM::YELLOW][i]->set_vel_y(TransferVel.y());
            detectionRobot[PARAM::YELLOW][i]->set_rotate_vel(result.robot[PARAM::YELLOW][i].rotateVel);
        }
//        int size = detectionFrame.ByteSize();
//        int size = passBegin->ByteSize();
//        QByteArray buffer(size, 0);
////        detectionFrame.SerializeToArray(buffer.data(), buffer.size());
//        passBegin->SerializeToArray(buffer.data(), buffer.size());

//        //在这儿发送protubuf包
//        QString beginbegin = "_end_"+QString::number(passCount - 1)+".zlog";
////        lw_v.setFileName(filename.replace(beginbegin, "_pass_" + QString::number(passCount) + ".zlog"));
//        lw_v.write(buffer);

//        //发送完毕

//        passBegin->clear_robots_blue();
//        passBegin->clear_robots_yellow();
        lastpBallState = "pass";
        writebegin = true;
    } else if (lastpBallState == "pass" && pBallState != "pass") {
        needNewFile = true;
        ReceiveVisionMessage result = maintain[-500];
        passEnd         = package4RL->mutable_endframe();
        detectionBall = passEnd->mutable_balls();
        if (result.ballSize > 0) {
            detectionBall->set_x(result.ball[0].pos.x());
            if (result.ball[0].pos.y() == 0) detectionBall->set_y(float(0.1));
            else detectionBall->set_y(result.ball[0].pos.y());//to fix a role match bug 2018.6.15
            CVector TransferVel(result.ball[0].velocity.x(), result.ball[0].velocity.y());
            detectionBall->set_vel_x(TransferVel.x());
            detectionBall->set_vel_y(TransferVel.y());
            detectionBall->set_valid(dealBall.getValid());
            detectionBall->set_last_touch(lastTouch);
            detectionBall->set_ball_state(ballStateMachine);
        } else {
            detectionBall->set_x(-32767);
            detectionBall->set_y(-32767);
        }
        for (int i = 0; i < result.robotSize[PARAM::BLUE]; i++) {
            if (i == PARAM::SENDROBOTNUM) break; //for sending MAX 8 car possible
            detectionRobot[PARAM::BLUE][i] = passEnd->add_robots_blue();
//            detectionRobot[PARAM::BLUE][i] = detectionFrame.add_robots_blue();
            detectionRobot[PARAM::BLUE][i]->set_x(result.robot[PARAM::BLUE][i].pos.x());
            detectionRobot[PARAM::BLUE][i]->set_y(result.robot[PARAM::BLUE][i].pos.y());
            detectionRobot[PARAM::BLUE][i]->set_orientation(result.robot[PARAM::BLUE][i].angle);
            detectionRobot[PARAM::BLUE][i]->set_robot_id(result.robot[PARAM::BLUE][i].id);
            detectionRobot[PARAM::BLUE][i]->set_confidence(1);
            CVector TransferVel(result.robot[PARAM::BLUE][i].velocity.x(), result.robot[PARAM::BLUE][i].velocity.y());
            detectionRobot[PARAM::BLUE][i]->set_vel_x(TransferVel.x());
            detectionRobot[PARAM::BLUE][i]->set_vel_y(TransferVel.y());
            detectionRobot[PARAM::BLUE][i]->set_rotate_vel(result.robot[PARAM::BLUE][i].rotateVel);
        }
        for (int i = 0; i < result.robotSize[PARAM::YELLOW]; i++) {
            if (i == PARAM::SENDROBOTNUM) break;
//            detectionRobot[PARAM::YELLOW][i] = detectionFrame.add_robots_yellow();
            detectionRobot[PARAM::YELLOW][i] = passEnd->add_robots_yellow();
            detectionRobot[PARAM::YELLOW][i]->set_x(result.robot[PARAM::YELLOW][i].pos.x());
            detectionRobot[PARAM::YELLOW][i]->set_y(result.robot[PARAM::YELLOW][i].pos.y());
            detectionRobot[PARAM::YELLOW][i]->set_orientation(result.robot[PARAM::YELLOW][i].angle);
            detectionRobot[PARAM::YELLOW][i]->set_robot_id(result.robot[PARAM::YELLOW][i].id);
            detectionRobot[PARAM::YELLOW][i]->set_confidence(1);
            CVector TransferVel(result.robot[PARAM::YELLOW][i].velocity.x(), result.robot[PARAM::YELLOW][i].velocity.y());
            detectionRobot[PARAM::YELLOW][i]->set_vel_x(TransferVel.x());
            detectionRobot[PARAM::YELLOW][i]->set_vel_y(TransferVel.y());
            detectionRobot[PARAM::YELLOW][i]->set_rotate_vel(result.robot[PARAM::YELLOW][i].rotateVel);
        }
//        int size = detectionFrame.ByteSize();
//        int size = passEnd->ByteSize();
//        QByteArray buffer(size, 0);
////        detectionFrame.SerializeToArray(buffer.data(), buffer.size());
//        passEnd->SerializeToArray(buffer.data(), buffer.size());

//        //在这儿发送protubuf包
//        QString endend ="_pass_" + QString::number(passCount) + ".zlog";
////        lw_v.setFileName(filename.replace(endend, "_end_" + QString::number(passCount) + ".zlog"));
//        lw_v.write(buffer);

//        //发送完毕

//        passEnd->clear_robots_blue();
//        passEnd->clear_robots_yellow();
        lastpBallState = "other";
        writeend = true;
    } else if (pBallState != "pass") {
        lastpBallState = "other";
        return false;
    }

    if (writebegin && writeend) {
        writebegin = false;
        writeend = false;
        package4RL->set_reward(0);
        qDebug() <<"The begin frame is " <<  package4RL->beginframe().balls().x() << "The end frame is " << package4RL->endframe().balls().x();
        int size = packages4RL.ByteSize();
        QByteArray buffer(size, 0);
        packages4RL.SerializeToArray(buffer.data(), buffer.size());
//        qDebug() << buffer;
        lw_v.write(buffer);
//        package4RL.clear_beginframe();
//        package4RL.clear_endframe();
//        package4RL.clear_reward();
//        packages4RL.clear_package();
        return true;
    }
    return false;
}
