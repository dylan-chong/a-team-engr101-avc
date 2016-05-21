/*
 * MotorController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "MotorController.h"
#include <stdlib.h>
#include <stdio.h>

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
	//printf("Motor Straight: %f\n", percent);//debuging print
	set_motor(LEFT_MOTOR, MAX_SPEED_LEFT*percent);
	set_motor(RIGHT_MOTOR, MAX_SPEED_RIGHT*percent);
}

//sets wheels to reverse
void MotorController::reverse(double percent){
	//printf("Motor reverse: %f\n", percent);//debuging print
	set_motor(LEFT_MOTOR, -MAX_SPEED_LEFT*percent);
	set_motor(RIGHT_MOTOR, -MAX_SPEED_RIGHT*percent);
}

//turn left at a certain percent
void MotorController::arcLeft(double percent){
	//printf("Motor left: %f\n", percent);//debuging print
	set_motor(LEFT_MOTOR, MAX_SPEED_LEFT*percent);
	set_motor(RIGHT_MOTOR, MAX_SPEED_RIGHT);
}

//turn right at a certain percent
void MotorController::arcRight(double percent){
	//printf("Motor right: %f\n", percent);//debuging print
	set_motor(RIGHT_MOTOR, MAX_SPEED_RIGHT*percent);
	set_motor(LEFT_MOTOR, MAX_SPEED_LEFT);
}

void MotorController::stop(){
	set_motor(RIGHT_MOTOR, 0);
	set_motor(LEFT_MOTOR, 0);
}

//rotate 90 degrees, negative for left and positive for right
// so will only need one method

void MotorController::arc(double percent){
	if (abs(percent)>1){
		percent = percent/abs(percent);
	}
	if (percent < 0){
		arcLeft(1+abs(percent));
	} else if (percent > 0){
		arcRight(1-abs(percent));
	} else {
		setStraightLine(1);
	}
}


