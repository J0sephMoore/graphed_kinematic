#include "Ball.h"
#include "Monkey.h"

Ball::Ball(double xInit, double yInit, double xVi, double yVi)
{
    m_xPose = xInit;
    m_height = yInit;
    m_xVel = xVi;
    m_yVel = yVi;
}

void Ball::ybounce()
{
    //bounces vertically
    m_yVel *= energyLoss;//simulate nonelastic collisions

}

void Ball::xbounce()
{
    m_xVel *= energyLoss;
}

void Ball::deltaPose() {//calculates the change in height and applies it to the height value
    m_yVel += m_yAccel * m_deltaT;
    m_height += 0.001 * m_yVel;

    m_xVel += m_xAccel * m_deltaT;
    m_xPose += m_xVel * m_deltaT;//find the change in x position
}