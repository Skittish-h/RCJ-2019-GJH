#include <Arduino.h>

uint8_t sensorPins[6] = {A0,A1,A2,A3,A4,A5};
bool sensorVals[6];
uint16_t sensorPos[6] = {30,60,7,6,4,33}; 

void getVals()
{
	
	
	for(int i =0; i<=5;i++)
	{
		sensorVals[i] = 400 < analogRead(sensorPins[i]);
	}
}
int16_t getDegree()
{
	for(int i =0; i <=5; i++){
		if(sensorVals[i]){
			return sensorVals[i];
		}
	}
	return -1;
}

void setUpSens(){
	for(int i = 0; i <=5; i++){
		pinMode(sensorPins[i], INPUT);
	}
}

