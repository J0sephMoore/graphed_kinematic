#pragma once
class Ball {
public:
    Ball(double xInit, double yInit, double xVi, double yVi);
    double m_height = 0;
    double m_t = 0;
    double m_deltaT = 0.001;
    double m_xVel = 0;
    double m_yVel = 0;
    double m_xPose = 0;
    double m_xAccel = 0;
    double m_yAccel = -9.809;
    double energyLoss = -0.9;

    void ybounce();
    void xbounce();
    void deltaPose();
};