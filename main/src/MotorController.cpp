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
	RIGHT_SPEEDS[0]=200;
	RIGHT_SPEEDS[1]=150;
	RIGHT_SPEEDS[2]=105;
	RIGHT_SPEEDS[3]=80;
	RIGHT_SPEEDS[4]=65;
	RIGHT_SPEEDS[5]=41;
	RIGHT_SPEEDS[6]=30;
	RIGHT_SPEEDS[7]=20;
	RIGHT_SPEEDS[8]=10;
	RIGHT_SPEEDS[9]=0;
	RIGHT_SPEEDS[10]=-10;
	RIGHT_SPEEDS[11]=-20;
	RIGHT_SPEEDS[12]=-30;
	RIGHT_SPEEDS[13]=-41;
	RIGHT_SPEEDS[14]=-60;
	RIGHT_SPEEDS[15]=-70;
	RIGHT_SPEEDS[16]=-88;
	RIGHT_SPEEDS[17]=-95;
	RIGHT_SPEEDS[18]=-180;
	RIGHT_SPEEDS[19]=-200;
	RIGHT_SPEEDS[20]=-255;
}

//this is the destructor
MotorController::~MotorController() {

}

//OLD code
/*
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
*/
//NEW CODE***************************
// ******************** PRIVATE IMPLEMENTATION ******************** //

// Refer to even-speeds.txt for nicer formatting of data

void MotorController::freezeIfSpeedOutOfRange(int speed) {
    if (speed < -NUMBER_OF_REVERSE_SPEEDS || speed > 11) {
        set_motor(2, 0);
        set_motor(1, 0);
    }
}

// Both setLeft and setRight take values between
// -5 and 11 inclusive
// setting both to -3 to 2 inclusive means the robot wont move
void MotorController::setLeft(int speed) {
    //freezeIfSpeedOutOfRange(speed);
    //set_motor(2, speed * 10);//ON pi
    set_motor(1,-speed*10);//for test on simulator
}

void MotorController::setRight(int speed) {
    //freezeIfSpeedOutOfRange(speed);
    //set_motor(1, RIGHT_SPEEDS[speed + NUMBER_OF_REVERSE_SPEEDS]);
    set_motor(2,-speed*10); //for testing on the simulator
}

void MotorController::moveStraightAtSpeed(int speed) {
    setLeft(speed);
    setRight(speed);
}

void MotorController::freezeIfDirectionOutOfRange(double direction) {
    if (direction > 1 || direction < -1) {
        set_motor(2, 0);
        set_motor(1, 0);
    }
}

// ******************** PUBLIC METHODS ******************** //


// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it

// just set the motors to full forward
void MotorController::moveForward() {
   // printf("MOVING FORWARD\n");
    moveStraightAtSpeed(8);
    /*for (int a = 0; a < 21; a++) {
        printf("ITEM %d is %d\n\n", a, RIGHT_SPEEDS[a]);
    }*/
}

void MotorController::moveBackward() {
    moveStraightAtSpeed(-6);
}

void MotorController::stopMovement() {
    setLeft(0);
    setRight(0);
}

// turn left on the spot
// right wheel doesn't seem to do anything
void MotorController::rotateLeft() {
    setLeft(LEFT_MIN);
    setRight(RIGHT_MAX);
}

// turn right on the spot
void MotorController::rotateRight() {
    setLeft(LEFT_MAX);
    setRight(RIGHT_MIN);
}

// -1 is max left
// 0 is max forward
// 1 is max right

void MotorController::arc(double direction) {
	printf("Direction: %f\n",direction);
    if (direction < 0) {
        setLeft((int)((LEFT_MAX - LEFT_MIN) * (direction*100) + LEFT_MAX));
        setRight(RIGHT_MAX);
        printf("Turningn left: %d\n", (int)((LEFT_MAX - LEFT_MIN) * direction + LEFT_MAX));
    } else if (direction > 0) {
        setLeft(LEFT_MAX);
        setRight((int)((RIGHT_MIN - RIGHT_MAX) * (direction*100) + RIGHT_MAX));
        printf("Turningn RIGHT: %d\n", (int)((RIGHT_MIN - RIGHT_MAX) * direction + RIGHT_MAX));
    } else if (direction == 0) {
        moveForward();
    }
}

