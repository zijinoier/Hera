#include "statejudge.h"
StateJudge::StateJudge(){

}

bool StateJudge::isOnField(int frame){
    if(maintain[frame].ball[0].pos.y() < FIELD_HEIGHT/2
            &&maintain[frame].ball[0].pos.y() > -FIELD_HEIGHT/2
            &&maintain[frame].ball[0].pos.x() < FIELD_WIDTH/2
            &&maintain[frame].ball[0].pos.x() > -FIELD_WIDTH/2){
        return true;
    }else{
        return false;
    }
}

bool StateJudge::robToBall(float rob_angle,CGeoPoint rob_pos,CGeoPoint ball_pos){  //小车嘴巴朝向球，用于判断吸球状态
    CVector line(ball_pos.x()-rob_pos.x(),ball_pos.y()-rob_pos.y());
    float angle=line.dir();


    float angle_max=angle+touch_angle;
    float angle_min=angle-touch_angle;
    bool flag;

    if(angle>PI/2&&(angle+touch_angle)>PI){
        angle_max=angle_max-2*PI;
//        std::cout<<"1,angle_max:"<<angle_max<<",angle_min:"<<angle_min<<std::endl;
        if ( angle_min<rob_angle||rob_angle<angle_max ) flag = 1;
        else flag = 0;
    }
    else if (angle<-PI/2&&(angle-touch_angle)<-PI) {
        angle_min=angle_min+2*PI;
//        std::cout<<"2,angle_max:"<<angle_max<<",angle_min:"<<angle_min<<std::endl;
        if ( (angle_min<rob_angle)||(rob_angle<angle_max) ) flag = 1;
        else flag = 0;
    }
    else if (angle_min<rob_angle&&rob_angle<angle_max) {
//        std::cout<<"3,angle_max:"<<angle_max<<",angle_min:"<<angle_min<<std::endl;
        flag = 1;
    }
    else {
//        std::cout<<"4,angle_max:"<<angle_max<<",angle_min:"<<angle_min<<std::endl;
        flag = 0;
    }

//       std::cout << "diff:"<<rob_angle-angle <<" rob:"<<rob_angle<<" line"<<angle<<std::endl;
    return flag;
}

bool StateJudge::angleToGoal(CGeoPoint rob_pos,CGeoPoint ball_pos,float boardLength){  //车球路线朝向球门，用于判断射门
    CVector robToBall(ball_pos.x()-rob_pos.x(),ball_pos.y()-rob_pos.y());
    CGeoPoint rightGoal1(0.5*FIELD_WIDTH,+0.5*boardLength);
    CGeoPoint rightGoal2(0.5*FIELD_WIDTH,-0.5*boardLength);
    CGeoPoint leftGoal1(-0.5*FIELD_WIDTH,+0.5*boardLength);
    CGeoPoint leftGoal2(-0.5*FIELD_WIDTH,-0.5*boardLength);
    CVector rightShotLine1(rightGoal1.x()-rob_pos.x(),rightGoal1.y()-rob_pos.y());
    CVector rightShotLine2(rightGoal2.x()-rob_pos.x(),rightGoal2.y()-rob_pos.y());
    CVector leftShotLine1(leftGoal1.x()-rob_pos.x(),leftGoal1.y()-rob_pos.y());
    CVector leftShotLine2(leftGoal2.x()-rob_pos.x(),leftGoal2.y()-rob_pos.y());
    float angle = robToBall.dir();
    float rightShotAngle1=rightShotLine1.dir();
    float rightShotAngle2=rightShotLine2.dir();
    float leftShotAngle1=leftShotLine1.dir();
    float leftShotAngle2=leftShotLine2.dir();
    bool flag1;
    bool flag2;
    if(leftShotAngle1<0) leftShotAngle1=leftShotAngle1+2*PI;
    if(leftShotAngle2<0) leftShotAngle2=leftShotAngle2+2*PI;
    if(leftShotAngle1<leftShotAngle2) {
        float a = leftShotAngle1;
        leftShotAngle1 = leftShotAngle2;
        leftShotAngle2 = a;
    }
    if(angle<-PI/2) angle = 2*PI+angle;
    if(angle<leftShotAngle1 && angle>leftShotAngle2) flag1 = 1;
    else flag1 = 0;
    if(angle<rightShotAngle1 && angle>rightShotAngle2) flag2 = 1;
    else flag2 = 0;
   // std::cout<<"angle:"<<angle<<std::endl;
   // std::cout<<"left:"<<leftShotAngle1<<","<<leftShotAngle2<<std::endl;
   // std::cout<<"right:"<<rightShotAngle1<<","<<rightShotAngle2<<std::endl;
    if (flag1 || flag2 )return 1;
    else return 0;
}

bool  StateJudge::ballLineChange(CGeoPoint before,CGeoPoint mid,CGeoPoint after,double angle){//ball near robot时，判断球路是否变化

    CVector line_before(mid.x()-before.x(),mid.y()-before.y());
    CVector line_after(after.x()-mid.x(),after.y()-mid.y());
    //std::cout<<"after:"<<line_after.dir()<<" before"<<line_before.dir()<<std::endl;
    float dif=abs(line_after.dir()-line_before.dir());
   //  std::cout<<"dif"<<dif<<"angle permit"<<angle_permit<<std::endl;
    if(dif<angle ||dif >(2*PI-angle)) return 0;
    else return 1;
}

bool StateJudge::ballLineChange(int frame,double angle)
{
    CGeoPoint before = maintain[frame-4].ball[0].pos;
    CGeoPoint mid = maintain[frame].ball[0].pos;
    CGeoPoint after = maintain[frame+4].ball[0].pos;
    if (frame-CURRENT_FRAME<4) before=maintain[CURRENT_FRAME].ball[0].pos;
    CVector line_before(mid.x()-before.x(),mid.y()-before.y());
    CVector line_after(after.x()-mid.x(),after.y()-mid.y());
   // std::cout<<"after:"<<line_after.dir()<<" before"<<line_before.dir()<<std::endl;
    float dif=abs(line_after.dir()-line_before.dir());
   //  std::cout<<"dif"<<dif<<"angle permit"<<angle_permit<<std::endl;
    if(dif<angle ||dif >(2*PI-angle)) return 0;
    else return 1;
}

bool  StateJudge::nearPenalty(int frame){
    if((maintain[frame].ball[0].pos.y() < (PENALTY_LENGTH/2+NEAR_LENGHTH)
            &&maintain[frame].ball[0].pos.y() > (-PENALTY_LENGTH/2-NEAR_LENGHTH)
            &&maintain[frame].ball[0].pos.x() < (FIELD_WIDTH/2+NEAR_LENGHTH)
            &&maintain[frame].ball[0].pos.x() > (FIELD_WIDTH/2-PENALTY_WIDTH-NEAR_LENGHTH))
            ||(maintain[frame].ball[0].pos.y() < (PENALTY_LENGTH/2+NEAR_LENGHTH)
               &&maintain[frame].ball[0].pos.y() > (-PENALTY_LENGTH/2-NEAR_LENGHTH)
               &&maintain[frame].ball[0].pos.x() > (-FIELD_WIDTH/2-NEAR_LENGHTH)
               &&maintain[frame].ball[0].pos.x() < (-FIELD_WIDTH/2+PENALTY_WIDTH+NEAR_LENGHTH))
            ){
        return true;
    }else{
        return false;
    }
}

bool  StateJudge::inPenalty(int frame){
    if((maintain[frame].ball[0].pos.y() < (PENALTY_LENGTH/2)
            &&maintain[frame].ball[0].pos.y() > (-PENALTY_LENGTH/2)
            &&maintain[frame].ball[0].pos.x() < (FIELD_WIDTH/2)
            &&maintain[frame].ball[0].pos.x() > (FIELD_WIDTH/2-PENALTY_WIDTH))
            ||(maintain[frame].ball[0].pos.y() < (PENALTY_LENGTH/2)
               &&maintain[frame].ball[0].pos.y() > (-PENALTY_LENGTH/2)
               &&maintain[frame].ball[0].pos.x() > (-FIELD_WIDTH/2)
               &&maintain[frame].ball[0].pos.x() < (-FIELD_WIDTH/2+PENALTY_WIDTH))
            ){
        return true;
    }else{
        return false;
    }
}

bool StateJudge::goal(int frame){
    if((maintain[frame].ball[0].pos.y() < (GOAL_WIDTH/2)
            &&maintain[frame].ball[0].pos.y() > (-GOAL_WIDTH/2)
            &&maintain[frame].ball[0].pos.x() > (FIELD_WIDTH/2)
            &&maintain[frame].ball[0].pos.x() < (FIELD_WIDTH/2+GOAL_DEPTH)
            )||(maintain[frame].ball[0].pos.y() < (GOAL_WIDTH/2)
               &&maintain[frame].ball[0].pos.y() > (-GOAL_WIDTH/2)
               &&maintain[frame].ball[0].pos.x() > (-FIELD_WIDTH/2-GOAL_DEPTH)
               &&maintain[frame].ball[0].pos.x() < -FIELD_WIDTH/2)
            ){
        return true;
    }else{
        return false;
    }
}

bool StateJudge::ballLineAcrossRob(CGeoPoint lineStrat,CGeoPoint lineEnd,CGeoPoint rob){
    CGeoLine line(lineStrat, lineEnd);
    if(line.projection(rob).dist(rob)<distForballLineAcrossRob) return 1;
    else return 0;
    //可能会用上的方法，带向量计算，以免把球路反向的车算入
//    CGeoPoint lineStart = ballstate4log::instance()->maintain[frame-7].ball[0].pos;
//    CGeoPoint lineEnd = ballstate4log::instance()->maintain[frame].ball[0].pos;
//    if(frame-CURRENT_FRAME<7) lineStart = ballstate4log::instance()->maintain[CURRENT_FRAME].ball[0].pos;
//    CVector line(lineEnd.x()-lineStart.x(),lineEnd.y()-lineStart.y());
//    CVector add((line/line.mod()).x()*5,(line/line.mod()).y()*5);
//    double dist=lineEnd.dist(nearrob.pos);
//    while(1){
//        lineEnd = lineEnd+add;
//        if(lineEnd.dist(nearrob.pos)<dist) dist=lineEnd.dist(nearrob.pos);
//        else break;
//        if (dist<80) return 1;
//    }
//    return 0;
}

bool StateJudge::isTouched(float rob_angle,CGeoPoint rob_pos,CGeoPoint ball_pos){
        if(rob_pos.dist(ball_pos) < TOUCH_DISTANCE
                && robToBall(rob_angle,rob_pos,ball_pos)){
            //ourBallState = touch;
            return true;
        }else{
            return false;
        }
}
