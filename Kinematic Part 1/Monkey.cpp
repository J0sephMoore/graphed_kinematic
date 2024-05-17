#include "Monkey.h"

Monkey::Monkey(double xInit, double yInit, double xVi, double yVi)
{
    T_xPose = xInit;
    T_height = yInit;
    T_xVel = xVi;
    T_yVel = yVi;
}

void Monkey::deltaPoseMonk()
{
    T_yVel += T_yAccel * T_deltaT;
    T_height += 0.001 * T_yVel;

    T_xVel += T_xAccel * T_deltaT;
    T_xPose += T_xVel * T_deltaT;
}