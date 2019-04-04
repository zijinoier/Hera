#ifndef CHIPSOLVER_H
#define CHIPSOLVER_H

#include "ballrecords.h"
#include "statejudge.h"

class VisionModule;
class Chipsolver {
public:
    Chipsolver(VisionModule *vm);
    ~Chipsolver();
    double chipsolveOffset(double timeOff);
    void getbestresult();
    CGeoPoint dealresult();
    void reset();
    void setrecord();
    void setrecord_test();
    void resetConfidence();
    void addChipConfidence(double value);
    void deChipConfidence(double value);

private:
    CVector3 kickVel;
    CVector3 kickPos;
    CVector3 posNow;
    CVector3 posEnd;
    double l1Error;
    double timeOffset;
    double t;
    double tFly;
    BallRecord ballrecord;
    double chipConfidence;
    double flatConfidence;
    StateJudge judgeTool;

    VisionModule* vm;

};
#endif // CHIPSOLVER_H
