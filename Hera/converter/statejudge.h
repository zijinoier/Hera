#ifndef STATEJUDGE_H
#define STATEJUDGE_H

#include "cmath"
//#include "globaldata.h"
#include "dataqueue.hpp"
#include "messageformat.h"
#include <iostream>
#include <string>
const int CURRENT_FRAME=-500;
const double PI = 3.14159;
//near_rob
const double NEAR_DISTANCE = 150;
//#define FIELD_WIDTH 13200
const double FIELD_WIDTH = 12000;
const double FIELD_HEIGHT = 9000;
const double TOUCH_DISTANCE = 150;
const double MAX_FRAME = 500;
//#define touch_angle 0.52
const double touch_angle = 0.36;
const double max_touch_angle = 0.46;
const double touch_dist = 120;//大概写的，待修改数据！！！
//goal\shot
//#define GOAL_WIDTH 1200
//#define GOAL_DEPTH 200
const double GOAL_WIDTH = 1500;
const double GOAL_DEPTH = 200;
//penalty
const double PENALTY_LENGTH = 2400;
const double PENALTY_WIDTH = 1200;
const double NEAR_LENGHTH = 1000;
//ballLineChange
const float angle_permit=40.0/180.0*3.14159;
//
const double distForballLineAcrossRob = 50;
//chip
const double velBoundary4chip = 2000.0;
const double angleBoundary4chip = 2.0/180.0*3.14159;
//pass
const double velBoundary = 1000.0;

class StateJudge{
public:
    StateJudge();
    bool isOnField(int frame);
    bool nearPenalty(int frame);
    bool inPenalty(int frame);
    bool robToBall(float rob_angle,CGeoPoint rob_pos,CGeoPoint ball_pos);
    bool ballLineChange (CGeoPoint before,CGeoPoint mid,CGeoPoint after,double angle = angle_permit);
    bool ballLineChange(int frame,double angle = angle_permit);
    bool angleToGoal(CGeoPoint rob_pos,CGeoPoint ball_pos,float boardLength);
    bool goal(int frame);
    bool ballLineAcrossRob(CGeoPoint lineStrat,CGeoPoint lineEnd,CGeoPoint rob);
    bool isTouched(float rob_angle,CGeoPoint rob_pos,CGeoPoint ball_pos);
    bool isDribble(int current_frame,Robot touchrobot,int team);

    DataQueue<ReceiveVisionMessage> maintain;
};

bool StateJudge::isDribble(int current_frame,Robot touchrobot,int team){
    int frame = current_frame;
    Robot robot;
    //std::cout<<lasttouch.id<<std::endl;
    for(int i=0;i<PARAM::ROBOTMAXID;i++){
        if(maintain[frame].robot[team][i].id==(touchrobot.id))
          {
            robot =  maintain[frame].robot[team][i];
            //std::cout<<"in"<<std::endl;
            break;
        }
//        std::cout<<"id::"<<maintain[frame].robot[touchteam][i].id<<std::endl;

    }
    //std::cout<<lasttouch.id<<std::endl;
        Ball ball = maintain[frame].ball[0];
    while(isTouched(robot.angle,robot.pos,ball.pos))
    {
        frame--;
        for(int i=0;i<PARAM::ROBOTMAXID;i++){
            if(maintain[frame].robot[team][i].id==(touchrobot.id))
              { robot =  maintain[frame].robot[team][i];
                //std::cout<<"in2"<<std::endl;
                break;
            }

        }
        ball = maintain[frame].ball[0];
    }
    frame = frame+1;
    for(int i=0;i<PARAM::ROBOTMAXID;i++){
        if(maintain[frame].robot[team][i].id==(touchrobot.id))
          { robot =  maintain[frame].robot[team][i];
            //std::cout<<"in3"<<std::endl;
            break;
        }

    }
    ball = maintain[frame].ball[0];
    //std::cout<<touchteam<<","<<lasttouch.id-touchteam*PARAM::ROBOTMAXID<<std::endl;
//   std::cout << frame <<std::endl;
//    std::cout << robot.pos.dist(lasttouch.pos) <<std::endl;
//    std::cout << robot.id<<std::endl;
//    std::cout << robot.pos << std::endl;
//    std::cout <<lasttouch.pos<<std::endl;
    if (frame==CURRENT_FRAME) return 0;
    else if((robot.pos.dist(touchrobot.pos)) > 1000.0) return 1;
    else return 0;


}


#endif // STATEJUDGE_H
