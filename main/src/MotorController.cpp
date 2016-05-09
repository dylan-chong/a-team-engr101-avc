/*
 * MotorController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "MotorController.h"

extern "C" int set_motor(int motor, int speed);

//Makes a new Motor Controller and returns a pointer to it
MotorController* MotorController::makeInstance(){
		instance = new MotorController();
		return (MotorController*)instance;
}

//This is the constructor
MotorController::MotorController() {
	LEFT_MOTOR = 0;
	RIGHT_MOTOR = 1;
	MAX_SPEED = 255;
}

//this is the destructor
MotorController::~MotorController() {

}

void MotorController::arc(char dir, double percent){
	if (dir = 'l'){
		arcLeft(percent);
	} else if (dir = 'r'){
		acrleft(percent);
	} else {
		setStraightLine(percent);
	}
}

//sets both wheels to ahead
void MotorContoller::setStraightLine(double percent){
	set_motor(LEFT_MOTOR, MAX_SPEED*percent);
	set_motor(RIGHT_MOTOR, MAX_SPEED*percent);
}

//tuen left at a certain percent
void MotorController::arcLeft(double percent){
	set_motor(LEFT_MOTOR, MAX_SPEED*percent);
	set_motor(RIGHT_MOTOR, MAX_SPEED);
}

//true right at a certain percent
void MotorController::arcRight(double percent){
	set_motor(RIGHT_MOTOR, MAX_SPEED*percent);
	set_motor(LEFT_MOTOR, MAX_SPEED);
}


