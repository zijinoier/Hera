#ifndef BALLSTATE_H
#define BALLSTATE_H
#include "cmath"
#include "dataqueue.hpp"
#include <iostream>
#include <string>
#include "statejudge.h"
#include "chipsolver.h"
#define CURRENT_FRAME -500
//#define pi 3.14159 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//near_rob
#define NEAR_DISTANCE 150
#define FIELD_WIDTH 12000
#define FIELD_HEIGHT 9000
#define TOUCH_DISTANCE 150
#define MAX_FRAME 500
#define touch_angle 0.36
#define max_touch_angle 0.46
#define touch_dist 120//大概写的，待修改数据！！！
//goal\shot
#define GOAL_WIDTH 1500
#define GOAL_DEPTH 200
//penalty
#define PENALTY_LENGTH 2400
#define PENALTY_WIDTH 1200
#define NEAR_LENGHTH 1000
enum Result {fail, success,undefined};
enum State {_touched, _shoot, _struggle, _pass, _dribble,_stop,_outoffied,_control,_undefine,_kicked,_chip_pass,_flat_pass,_error};
enum Information{Duration,Out_of_field,Touched,Stop,Struggle,Overtime,Goal,Shoot_not_on_goal,Pass_out_of_field,Shoot_intercepted_by_opposite,
                 Pass_intercepted_by_opposite,Control_ball,Pass_success,Pass_block_by_our_side,Dribble,Undefine,Read_future_continue,Flat_pass,Chip_pass,Pass_Blocked,Unknown_Situation};
enum command{HALT,STOP,NORMAL_START,FORCE_START,PREPARE_KICKOFF_YELLOW,PREPARE_KICKOFF_BLUE,PREPARE_PENALTY_YELLOW,
             PREPARE_PENALTY_BLUE,DIRECT_FREE_YELLOW,DIRECT_FREE_BLUE,INDIRECT_FREE_YELLOW,INDIRECT_FREE_BLUE,TIMEOUT_YELLOW,TIMEOUT_BLUE,GOAL_YELLOW,GOAL_BLUE,BALL_PLACEMENT_YELLOW,BALL_PLACEMENT_BLUE};
enum Judge{stopJudge = 24,struggleJudge=25};
enum Mod{LOG,LIVE};
const Mod ballstateMod = LOG;

class VisionModule;
class Ballstate{
public:
    Ballstate(VisionModule* vm);
    ~Ballstate();
    void dealInformation(Information information);
    void runChipsolver();//


    int get_ballstate();
    int get_touchteam();
    int get_id();
    int get_lockFrame();
    int get_nextnear();
    int get_judgeid();
    QString get_name();
    QString get_result();
    CGeoPoint chipPredict;
    DataQueue<ReceiveVisionMessage> maintain = 1000;
    void run(DataQueue<ReceiveVisionMessage> record);
    State ballState;

private:
    Robot lasttouch;
    Robot nearrob;

    int touchteam;
    int durationFrame;
    int dribbleFrame;
    int id;
    int next_id;
    Result result;
    int judgeID;
    bool usedInPenalty;
    StateJudge judgeTool;
    Chipsolver chipsolver;
    bool isShoot(int frame);
    bool touchJudge(int frame);
    bool nearRobot(int frame);
    const bool test = 0;

    VisionModule* vm;

    Information readLogFuture();
    Information readLogFrame();
    Information dealFutureFrame(int frame);
    Information dealFutureOut(int frame);
    Information dealFutureNear(int frame);

};
#endif // BALLSTATE_H
