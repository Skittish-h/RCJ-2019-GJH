//Main code for motor control - GJH team
//Due to budget (and time) restrictions we have 2 different types of Motor Drivers (thus the retarded code)
//include the arduino libary cuz we to lazy for AVR :)
#include <Arduino.h>
#define  Pi 3.14

//create our structs

struct Motor {
  //amount of pins 2 or 3
  uint8_t pinCount;
  //pin locations of the pins - [PWM, dig (, dig)]
  uint8_t pins[3];
  //direction of the motor, in degrees
  uint16_t direction;
  //since we dont want to due a lot of sines/cosines, we create a list of possible outputs, one for each degree
  uint8_t calc[360];
};

//typedef time
typedef Motor Motor;

//functions
void motorSetup(Motor *motor, bool pin2or3, uint16_t direc, uint8_t pin[3])
{
  motor->pinCount = pin2or3 ? 2 : 3;
  motor->direction = direc;

  for (size_t i = 0; i < 3; i++) {
    motor->pins[i] = pin[i];
  }

}
void calcVals(Motor *motor) {
  for (size_t i = 0; i < 360; i++) {
    motor->calc[i] = uint16_t(sin(i - motor->direction) * 255);
  }
}
