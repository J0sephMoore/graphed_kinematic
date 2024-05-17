#include <iostream>
#include "GNUPlot.h"
#include "Ball.h"
#include "Monkey.h"

using namespace std;

int main()
{
    Ball ball(0, 10, 50, 20);//initial ball conditions
    Monkey Ty(50, 30, 0, 0);//initial monkey conditions
    GNUPlot myGraph;

    int counter = 0;

    double record[2][2]{
        { 0, 0 },
        { 0, 0 }
    };

    bool go = true;
    
    while (go) {//call fallBall function at desired time increment for desired precision until the ball has hit the ground

        double dist = sqrt((Ty.T_xPose - ball.m_xPose) * (Ty.T_xPose - ball.m_xPose) + (Ty.T_height - ball.m_height) * (Ty.T_height - ball.m_height));//calculate distance between projectiles

        ball.deltaPose();
        Ty.deltaPoseMonk();

        if (ball.m_height <= 0) {//bounce off of the ground
            ball.ybounce();
            ball.m_height = 0;
        }

        if (ball.m_xPose >= 55 || ball.m_xPose <= 0) {//bounce on walls
            ball.xbounce();
        }

        if (dist <= 0.0001 || Ty.T_height <= 0) {//end on hit
            go = false;
        }

        //add points to graph at set intervals
        if (counter % 100 == 0 || ball.m_height == 0) {
            myGraph.AddPoint(ball.m_xPose, ball.m_height);
            myGraph.AddPoint2(Ty.T_xPose, Ty.T_height);
        }
        counter += 1;
    }

    

    myGraph.CreatePlot();
    return 0;

}