#include "ballstate.h"
#include "visionmodule.h"
#include <string>
Ballstate::Ballstate(VisionModule* vm):ballState(_stop),touchteam(-1),durationFrame(0),id(-1),next_id(-1),usedInPenalty(0),result(undefined),chipPredict(0,0),vm(vm),chipsolver(vm){
    judgeTool.maintain = maintain;
}
Ballstate::~Ballstate(){

}
/************************************************************************/
/*              辅助判断的bool条件函数                                    */
/************************************************************************/
bool Ballstate::touchJudge(int frame){
    int ourtouched = 0;
    int theirtouched = 0;
    int i;
    for(i=0 ; i<maintain[frame].robotSize[PARAM::BLUE] ; i++){
        float rob_angle=maintain[frame].robot[PARAM::BLUE][i].angle;
        CGeoPoint rob_pos=maintain[frame].robot[PARAM::BLUE][i].pos;
        CGeoPoint ball_pos=maintain[frame].ball[0].pos;
        if(judgeTool.isTouched(rob_angle,rob_pos,ball_pos)){
            ourtouched = 1;
            lasttouch = maintain[frame].robot[PARAM::BLUE][i];
            break;
        }
    }
    for(i=0 ; i<maintain[frame].robotSize[PARAM::YELLOW] ; i++){
        float rob_angle=maintain[frame].robot[PARAM::YELLOW][i].angle;
        CGeoPoint rob_pos=maintain[frame].robot[PARAM::YELLOW][i].pos;
        CGeoPoint ball_pos=maintain[frame].ball[0].pos;
        if(judgeTool.isTouched(rob_angle,rob_pos,ball_pos)){
            theirtouched = 1;
            lasttouch = maintain[frame].robot[PARAM::YELLOW][i];
            break;
        }
        //std::cout<<"id::"<<maintain[CURRENT_FRAME].robot[PARAM::YELLOW][i].id<<std::endl;
    }
    for(i=0 ; i<maintain[frame].robotSize[touchteam] ; i++){
        if(touchteam == -1) break;
        float rob_angle=maintain[frame].robot[touchteam][i].angle;
        CGeoPoint rob_pos=maintain[frame].robot[touchteam][i].pos;
        CGeoPoint ball_pos=maintain[frame].ball[0].pos;
        if(judgeTool.isTouched(rob_angle,rob_pos,ball_pos)){
            lasttouch = maintain[frame].robot[touchteam][i];
            break;
        }
        //std::cout<<"id::"<<maintain[CURRENT_FRAME].robot[PARAM::YELLOW][i].id<<std::endl;
    }
    if(ourtouched == 1 && theirtouched == 1){
        ballState = _struggle;
        judgeID = struggleJudge;
        return true;
    }else if(theirtouched == 1){
        ballState = _touched;
        judgeID = PARAM::YELLOW*PARAM::ROBOTMAXID+lasttouch.id;
        touchteam = PARAM::YELLOW;
        return true;
    }else if(ourtouched == 1){
        ballState = _touched;
        judgeID = PARAM::BLUE*PARAM::ROBOTMAXID+lasttouch.id;
        touchteam = PARAM::BLUE;
        return true;
    }else{
        //lasttouch.id = struggleJudge;
        return false;
    }
}
bool Ballstate::nearRobot(int frame){
    for(int i=0 ; i<maintain[frame].robotSize[PARAM::BLUE] ; i++){
        Robot temprobot = maintain[frame].robot[PARAM::BLUE][i];
        Ball tempball = maintain[frame].ball[0];
        if(tempball.pos.dist(temprobot.pos)<NEAR_DISTANCE){
            nearrob = temprobot;
            nearrob.id = PARAM::BLUE*PARAM::ROBOTMAXID+temprobot.id;
            return true;
        }
    }
    for(int i=0 ; i<maintain[frame].robotSize[PARAM::YELLOW] ; i++){
        Robot temprobot = maintain[frame].robot[PARAM::YELLOW][i];
        Ball tempball = maintain[frame].ball[0];
        if(tempball.pos.dist(temprobot.pos)<NEAR_DISTANCE){
            nearrob = temprobot;
            nearrob.id = PARAM::YELLOW*PARAM::ROBOTMAXID+temprobot.id;
            return true;
        }
    }
    return false;
}

bool Ballstate::isShoot(int frame){
    if (usedInPenalty){
        if (judgeTool.nearPenalty(frame) && judgeTool.angleToGoal(lasttouch.pos,maintain[frame].ball[0].pos,FIELD_HEIGHT)) return 1;
        else return 0;
    }
    else{
        if (judgeTool.nearPenalty(frame) && judgeTool.angleToGoal(lasttouch.pos,maintain[frame].ball[0].pos,PENALTY_LENGTH)) return 1;
        else return 0;
    }
}


/************************************************************************/
/*              处理数据                                           */
/************************************************************************/
void Ballstate::dealInformation(Information information){
    usedInPenalty = 0;
    switch (information){
        case Duration:
                durationFrame--;
                break;
        case Out_of_field :
                ballState = _outoffied;
                judgeID = stopJudge;
                next_id = -1;
                result = undefined;
                break;
        case Touched :
                id=lasttouch.id ;
                result = undefined;
                next_id =-1;
                dribbleFrame++;
                usedInPenalty = 0;
                break;
        case Stop:
                ballState=_stop;
                result = undefined;
                next_id = -1;
                judgeID = stopJudge;
                id = -1;
                break;
        case Struggle:
                ballState=_struggle;
                result = undefined;
                next_id = -1;
                break;
        case Overtime:
                ballState = _stop;
                judgeID = stopJudge;
                result = success;
                break;
        case Goal:
                ballState = _shoot;
                judgeID = stopJudge;
                next_id = -1;
                result = success;
                break;
        case Shoot_not_on_goal:
                ballState = _shoot;
                judgeID = stopJudge;
                result = fail;
                break;
        case Pass_out_of_field:
                ballState = _pass;
                judgeID = stopJudge;
                result = fail;
                break;
        case Shoot_intercepted_by_opposite:
                ballState = _shoot;
                judgeID = struggleJudge;
                result = fail;//球路改变，射门被对方车身挡出，进入争球
                next_id = nearrob.id;
                break;
        case Pass_intercepted_by_opposite:
                ballState = _pass;
                judgeID = struggleJudge;
                result = fail;//球路改变，传球被对方车身挡出，进入争球
                next_id = nearrob.id;
                break;
        case  Pass_success:
                ballState = _pass;
                result = success;
                next_id = nearrob.id;
                break;
        case Pass_block_by_our_side:
                ballState = _pass;
                judgeID = struggleJudge;
                result = fail;
                next_id = nearrob.id;
                break;
        case Control_ball:
                ballState = _control;
                result = undefined;
                break;
        case Dribble:
                ballState = _dribble;
                result = undefined;
                break;
        case Undefine:
                ballState = _undefine;
                result = undefined;
                judgeID = stopJudge;
                id = -1;
                break;
        case Chip_pass:
                ballState = _chip_pass;
                result = undefined;
                break;
        case Flat_pass:
                ballState = _flat_pass;
                result = undefined;
                break;
        case Pass_Blocked:
                ballState = _flat_pass;
                result = undefined;
                break;
    }
}

void Ballstate::runChipsolver(){
    chipsolver.setrecord();
    vm->chipJudge.push(maintain[0]);
    //chipsolver
    switch (ballState) {
    case _touched:
    case _shoot:
    case _struggle:
    case _dribble:
    case _stop:
    case _outoffied:
    case _control:
    case _undefine:
        if(vm->ballrecords.validSize() > 0) {
            chipsolver.reset();
            vm->chipJudge.clear();
            chipsolver.resetConfidence();
            chipPredict.setX(0);
            chipPredict.setY(0);
        }
        break;
    case _pass:
    case _flat_pass:
        break;
    default:
        chipPredict=chipsolver.dealresult();
    }
}
/************************************************************************/
/*             给interation传信息用（不重要）                              */
/************************************************************************/
int Ballstate::get_judgeid(){
    return judgeID;
}
int Ballstate::get_ballstate(){
    return ballState;
}
int Ballstate::get_touchteam(){
    return touchteam;
}
int Ballstate::get_id(){
    return id;
}
int Ballstate::get_lockFrame(){
    return durationFrame;
}

QString Ballstate::get_result(){
    if (result==0) return "fail";
    else if (result == 1) return "success";
    else return "undefined";

}
int Ballstate::get_nextnear(){
    return next_id;
}

QString Ballstate::get_name(){
    int a = get_ballstate();
    if(a==0) return "touch";
    else if (a==1) return "shoot";
    else if (a==2) return "struggle";
    else if (a==3) return "pass";
    else if (a==4) return "dribble";
    else if (a==5) return "stop";
    else if (a==6) return "outoffield";
    else if (a==7) return "control";
    else if (a==8) return "undefine";
    else if (a==10) return "chip";
    else if (a==11) return "flat";
    else if (a==12) return "error:unknown situation";
    else return "unknown";
}

Information Ballstate::readLogFrame(){
    if (durationFrame>0){
        return Duration ;
    } //当一个duration的状态确定了，直接进这个判断
    if(!(judgeTool.isOnField(CURRENT_FRAME))){
       if (test) std::cout<<"Out_of_field"<<std::endl;
       return Out_of_field;
    }
    if(judgeTool.isOnField(CURRENT_FRAME)&&touchJudge(CURRENT_FRAME)){
        if (judgeTool.isDribble(CURRENT_FRAME,lasttouch,touchteam)){
            if (test) std::cout<<"Dribble"<<std::endl;
            return Dribble;
        }else if(judgeID == struggleJudge){
            return Struggle;
        }else {
            if (test) std::cout<<"Touched"<<std::endl;
            return Touched;
        }
    }
    if(judgeTool.isOnField(CURRENT_FRAME)&&!touchJudge(CURRENT_FRAME)){//在场上，无车touch
        if (judgeID==stopJudge){
            if (test) std::cout<<"Stop"<<std::endl;
            return Stop;
        }//死球
        if (judgeID==struggleJudge){
            if (test) std::cout<<"Struggle"<<std::endl;
            return Struggle;
        }//争球
        else{
            //看未来情况
            return readLogFuture();
        }
    }
}

Information Ballstate::readLogFuture(){
    int frame = CURRENT_FRAME;
    for(frame = CURRENT_FRAME ; frame<CURRENT_FRAME+MAX_FRAME ; frame++){
        if(frame == CURRENT_FRAME+MAX_FRAME-1){
            if (test) std::cout<<"Future--Overtime"<<std::endl;
            return Overtime;
        }//判断超时，认为是死球
        Information futureInfo = dealFutureFrame(frame);
        if (futureInfo != Read_future_continue){
            return futureInfo;
        }
    }
    return Stop;
}

Information Ballstate::dealFutureFrame(int frame){
    if(judgeTool.inPenalty(frame)){
        usedInPenalty = 1;
    }
    if(!judgeTool.isOnField(frame)){
        Information futureOutInfo = dealFutureOut(frame);
        return futureOutInfo;
    }

    if(judgeTool.isOnField(frame)&&nearRobot(frame)){
        if(judgeTool.isTouched(nearrob.angle,nearrob.pos,vm->maintain[frame].ball[0].pos)){
                durationFrame=frame-CURRENT_FRAME-2;//到frame处更新lasttouch
        }
        else{
                durationFrame=frame-CURRENT_FRAME-1;
        }
        Information futureNearInfo = dealFutureNear(frame);
        return futureNearInfo;
    }
    return Read_future_continue;
}

Information Ballstate::dealFutureOut(int frame){//处理出球后出界先出现的情况
    durationFrame=frame-CURRENT_FRAME-1;//duration判断完毕，状态锁定
    if (judgeTool.goal(frame)){//破门
        if (test) std::cout<<"Future--!isOnField--goal"<<std::endl;
        return Goal;
    }
    else if(isShoot(frame)){//射门偏出
         if (test) std::cout<<"Future--!isOnField--Shoot_not_on_goal"<<std::endl;
        return Shoot_not_on_goal;
    }
    else {//传球出界
        if (test) std::cout<<"Future--!isOnField--Pass_out_of_field"<<std::endl;
        return Pass_out_of_field;
    }
}

Information Ballstate::dealFutureNear(int frame){//处理出球后先接近车的情况
    if((judgeID/PARAM::ROBOTMAXID) != (nearrob.id/PARAM::ROBOTMAXID)){//敌方接近球
        if(test) std::cout<<"theirnear"<<std::endl;
        if(!judgeTool.ballLineChange(frame)){
            if(vm->maintain[frame].ball[0].pos.dist(nearrob.pos)<=80){//穿过小车，认为是挑球
                chipsolver.addChipConfidence(1);
            }
            return Read_future_continue;//球路未改变，认为是擦过车身
        }
        else if(isShoot(frame) ){
            if (test) std::cout<<"Future--isOnField--theirNear--Shoot_intercepted_by_opposite"<<std::endl;
            return Shoot_intercepted_by_opposite;
        }
        else if(!isShoot(frame)){
            if (test) std::cout<<"Future--isOnField--theirNear--Pass_intercepted_by_opposite"<<std::endl;
            if(durationFrame<=90&&vm->maintain[frame].ball[0].velocity.mod()<velBoundary) return Struggle;
            else return Pass_intercepted_by_opposite;
        }
    }
   if((judgeID/PARAM::ROBOTMAXID) == (nearrob.id/PARAM::ROBOTMAXID)) {//我方接近球
        if(judgeTool.isTouched(nearrob.angle,nearrob.pos,vm->maintain[frame].ball[0].pos)){
            if(nearrob.id == judgeID&&(frame-CURRENT_FRAME)<=60) {
                if (test) std::cout<<"Future--isOnField--ourNear--Control_ball"<<std::endl;
                return Control_ball;
            }
            if(nearrob.id == judgeID&&(frame-CURRENT_FRAME)>=60) {
                if (test) std::cout<<"Future--isOnField--ourNear--Struggle"<<std::endl;
                return Struggle;
            }
            if (test) std::cout<<"Future--isOnField--ourNear--Pass_success"<<std::endl;
            return Pass_success;
        }
        else if(judgeTool.ballLineChange(frame)){
            if (test) std::cout<<"Future--isOnField--ourNear--Pass_block_by_our_side"<<std::endl;
            return Pass_block_by_our_side;
        }
    }
}



void Ballstate::run(DataQueue<ReceiveVisionMessage> record){
    if (maintain.validSize()==0) {
        for (int i =0;i>-(record.validSize());i-- ){
            maintain.push(record[i]);
        }
    }
    else if (maintain.validSize()!=0){
        maintain.push(record[0]);
    }
    int frame;
    frame = CURRENT_FRAME;
    Information information = readLogFrame() ;
    dealInformation(information);
}

