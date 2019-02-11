/*main code for RCJ 2019 robotic socer ny GJH team :)*/
//Code is as C - oriented as possible (minimalizing the amount of Classes)
/* robot has 4 main systems it has to rely on to be able to score a goal:
    -Visual Ball & Goal detection
    -Bottom IR sensors (LED & PhotoTransostor pairs)
    -Gyroscope (IMU included) & Magnetic compass
    -Motor Control
    


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //Get all vals
  getVals();
  int ballPos = ...;
  //isLine? -> move  away
  int lineDegs = getDegree();
  if(lineDegs != -1)
  {
    setSpeedFromVector(lineDegs - 180 , 100);
  }
  //Find ball
  //isBall? -> remember val -> move after ball
  //See ball? -> move to ball
  //don't see ball? -> move backwards
  if(ballPos == -1)
  {
    setSpeedFromVector(180, 100);
  }
  //Compare gyro and goal;
  //Somehow figure out rotation
  //Apply to motors

}
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
//#include <stdlib.h>




void setup()
{
  Serial.begin(9600);
  Serial.println("yo");
  setupMotors();
  
  for (int i = 0; i < 180; i++) {
    Serial.print(i*2);
    Serial.print(" : ");
    Serial.println(calcs[1][i]);
  }
}
void loop()
{
  setSpeedFromVector(0 ,100);
    setAllSpeed();
}
