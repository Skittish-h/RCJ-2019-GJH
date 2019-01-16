//Main code for motor control - GJH team
//Due to budget (and time) restrictions we have 2 different types of Motor Drivers (thus the retarded code)
//include the arduino libary cuz we to lazy for AVR :)
//#include <Arduino.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <math.h>
#define  PI 3.14159265
uint8_t motpins[3][3] = {{11,12,0}, {6,7,0}, {11,12,0}};
uint8_t pinCounts[3] = {2,2,2};
uint16_t directions[3] = {60,300,60};
int16_t calcs[3][180];
int16_t speeds[3] = {0,0,0};
//create our structs


int absol(int number)
{
  if(number < 0)
  {
    return -number;
  }
  else
  {
    return number;
  }

}
//functions

//simple function limits a number
int limiter(int16_t lower, int16_t upper, int16_t input)
{

  if (input<lower) {
    return lower;
  } else if (input>upper) {
    return upper;
  } else {
    return input;
  }
}

//sets motors up - mosty for testing purposes so far

void calcVals(uint8_t iter) {
  for (uint16_t i = 0; i < 180; i++) {
    Serial.println(iter);
    calcs[iter][i] = int16_t(sin((i*2 - directions[iter]) * PI/180)* 255);
  }
}
void setupMotors() {
  for (uint8_t i = 0; i < 3; i++) {
    Serial.print("yeer");
    Serial.println(i);
    calcVals(i);
  }

}
//function that sets speeds depending on the required vector
//TODO: make function increase speed proportionally for maximum speed
void setSpeedFromVector(uint16_t vector, int16_t percentage)
{
  //uint8_t speed[3];
  for (uint8_t i = 0; i < 3; i++) {
    speeds[i] = (calcs[i][vector/2] * percentage) / 100;
  }
}
//set Rotation of the whole robot by ofseting
void setRotation(int16_t rotation)
{
  for (uint8_t i = 0; i < 3; i++) {
    speeds[i] = limiter(-255,255,speeds[i] + rotation);
  }
}
//once we have adjusted all nessecary things, we can set the speed of the motor
void setMotorSpeed(uint8_t iter) {

  //if (motor->xdd == 2) {
    Serial.print(iter);
    Serial.print(" : ");
    Serial.println(speeds[iter]);
    analogWrite(motpins[iter][0], (speeds[iter] < 0) ? 255-speeds[iter] : absol(speeds[iter] -255));
    //printf("Enable (%d): %d\n", motor->pins[0],(motor->speed < 0) ? 255-absol(motor->speed) : absol(motor->speed));
    //printf("Digital (%d): %d\n", motor->pins[1], (motor->speed < 0));
    digitalWrite(motpins[iter][1], (speeds[iter] > 0));
    //Serial.println((motor->speed < 0) ? 255-motor->speed : motor->speed -255);
  //} else {
    //analogWrite(motor->pins[0],absol(motor->speed));
    //digitalWrite(motor->pins[1], (motor->speed < 0));
    //digitalWrite(motor->pins[2], !(motor->speed < 0));
    /*printf("Enable (%d): %d\n", motor->pins[0],absol(motor->speed));
    printf("Digital1 (%d): %d\n", motor->pins[1], (motor->speed < 0));
    printf("Digital2 (%d): %d\n", motor->pins[2], !(motor->speed < 0));*/
  //}
}
//set speeds for all motors
void setAllSpeed() {
  for (uint8_t i = 0; i < 2; i++) {
    //printf("Motor %d\n", i);
    setMotorSpeed(i);
  }
}
