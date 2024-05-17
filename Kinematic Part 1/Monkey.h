#pragma once
class Monkey {
public:
    Monkey(double xInit, double yInit, double xVi, double yVi);
    double T_height = 20;
    double T_t = 0;
    double T_deltaT = 0.001;
    double T_xVel = 0;
    double T_yVi = 0;
    double T_yVel = T_yVi;
    double T_xPose = 15;
    double T_xAccel = 0;
    double T_yAccel = -9.809;
    double energyLoss = -0.9;
    void deltaPoseMonk();
};