/*main code for RCJ 2019 robotic socer ny GJH team :)*/
//Code is as C - oriented as possible (minimalizing the amount of Classes)
/* robot has 4 main systems it has to rely on to be able to score a goal:
    -Visual Ball & Goal detection
    -Bottom IR sensors (LED & PhotoTransostor pairs)
    -Gyroscope (IMU included) & Magnetic compass
    -Motor Control
*/
/*  Motors are aranged in the following way:
          _________ Mot 2
          _________
        /           \
      /              \
    /                 \
  \ \                / /
    \ \             / /
      \ \ _________/ /  mot 1
mot 3      front
*/

//include all our .h's
#include "includes/motors.h"
#include "includes/sensors.h"
#include "includes/gyro.h"
#include "includes/improc.h"

//our motors
Motor motors[3];

void setup()
{

}
void loop()
{

}
