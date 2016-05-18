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

}

//this is the destructor
MotorController::~MotorController() {

}

//sets both wheels to ahead
//can stop motors by setting % to 0
void MotorController::setStraightLine(double percent){
	set_motor(LEFT_MOTOR, MAX_SPEED_LEFT*percent);
	set_motor(RIGHT_MOTOR, MAX_SPEED_RIGHT*percent);
}

//sets wheels to reverse
void MotorController::reverse(double percent){
	set_motor(LEFT_MOTOR, -MAX_SPEED_LEFT*percent);
	set_motor(RIGHT_MOTOR, -MAX_SPEED_RIGHT*percent);
}

//turn left at a certain percent
void MotorController::arcLeft(double percent){
	set_motor(LEFT_MOTOR, MAX_SPEED_LEFT*percent);
	set_motor(RIGHT_MOTOR, MAX_SPEED_RIGHT);
}

//turn right at a certain percent
void MotorController::arcRight(double percent){
	set_motor(RIGHT_MOTOR, MAX_SPEED_RIGHT*percent);
	set_motor(LEFT_MOTOR, MAX_SPEED_LEFT);
}

//rotate 90 degrees, negative for left and positive for right
// so will only need one method

void MotorController::arc(char dir, double percent){
	if (dir == 'l'){
		arcLeft(percent);
	} else if (dir == 'r'){
		arcRight(percent);
	} else if (dir == 's'){
		setStraightLine(percent);
	} else {
		setStraightLine(0);
	}
}


