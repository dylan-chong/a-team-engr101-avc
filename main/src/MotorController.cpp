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
MotorController *MotorController::makeInstance() {
    instance = new MotorController();
    return (MotorController *) instance;
}

//This is the constructor
MotorController::MotorController() {
    RIGHT_SPEEDS[0] = 200;
    RIGHT_SPEEDS[1] = 150;
    RIGHT_SPEEDS[2] = 105;
    RIGHT_SPEEDS[3] = 80;
    RIGHT_SPEEDS[4] = 65;
    RIGHT_SPEEDS[5] = 41;
    RIGHT_SPEEDS[6] = 30;
    RIGHT_SPEEDS[7] = 20;
    RIGHT_SPEEDS[8] = 10;
    RIGHT_SPEEDS[9] = 0;
    RIGHT_SPEEDS[10] = -10;
    RIGHT_SPEEDS[11] = -20;
    RIGHT_SPEEDS[12] = -30;
    RIGHT_SPEEDS[13] = -41;
    RIGHT_SPEEDS[14] = -60;
    RIGHT_SPEEDS[15] = -70;
    RIGHT_SPEEDS[16] = -88;
    RIGHT_SPEEDS[17] = -95;
    RIGHT_SPEEDS[18] = -180;
    RIGHT_SPEEDS[19] = -200;
    RIGHT_SPEEDS[20] = -255;
}

//this is the destructor
MotorController::~MotorController() {

}

// ******************** PRIVATE IMPLEMENTATION ******************** //

// Refer to even-speeds.txt for nicer formatting of data

// Both setLeft and setRight take values between
// -5 and 11 inclusive
// setting both to -3 to 2 inclusive means the robot wont move
void MotorController::setLeft(int speed) {
	//set_motor(1, -(speed * 10 / 1.5));//ON pi FOR Dylans code
	//set_motor(1, -(speed * 10 / 2));//for pid
    set_motor(1,-speed*7.5);//for test on simulator
}

void MotorController::setRight(int speed) {
    //set_motor(2, (int)-(RIGHT_SPEEDS[(int) (speed/1.5) + NUMBER_OF_REVERSE_SPEEDS])); //FOR Dylans code
    set_motor(2, (-(int)(RIGHT_SPEEDS[(int) (speed) + NUMBER_OF_REVERSE_SPEEDS]))/1.5);//for pid
   // set_motor(2,-speed*8); //for testing on the simulator
}

void MotorController::moveStraightAtSpeed(int speed) {
    setLeft(speed);
    setRight(speed);
}
// ******************** PUBLIC METHODS ******************** //

void MotorController::moveForward() {
    moveStraightAtSpeed(8);
}

void MotorController::moveBackward() {
    moveStraightAtSpeed(-3);
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

void MotorController::arc(double direction, int shouldMoveForward) {
	direction *= 10;
    if (abs(direction)>1)direction /= abs(direction);
    printf("Direction: %f\n", direction);

    if (shouldMoveForward == 1) {
        //printf("Going forwards\n");

        if (direction < 0) { //left
           //int left = (int) ((LEFT_MAX - LEFT_MIN) * (direction) + LEFT_MAX);
        	int left = LEFT_MAX*(1-abs(direction));
            printf("LEFT MOTOR: %d/n", left);
            printf("RIGHT MOTOR: %d/n", RIGHT_MAX);
            setLeft(left);
            setRight(RIGHT_MAX);
        } else if (direction > 0) { //right
            //int right = (int) ((RIGHT_MIN - RIGHT_MAX) * (direction) + RIGHT_MAX);
            int right = RIGHT_MAX * (1-direction);
            printf("LEFT MOTOR: %d/n", LEFT_MAX);
			printf("RIGHT MOTOR: %d/n", right);
            setLeft(LEFT_MAX);
            setRight(right);
        } else if (direction == 0) {
            moveForward();
        }

    } else if (shouldMoveForward == 0) { // needs testing
        printf("Going back\n");

        if (direction < 0) {
            int left = (int) ((LEFT_MAX - LEFT_MIN) * (direction) + LEFT_MAX);
            setLeft(-left/30);
            setRight(-RIGHT_MAX/30);
            printf("Turning left: %d\n", left);
        } else if (direction > 0) {
            int right = (int) ((RIGHT_MIN - RIGHT_MAX) * (direction) + RIGHT_MAX);
            setLeft(-LEFT_MAX/30);
            setRight(-right/30);
            printf("Turning RIGHT: %d\n", right);
        } else if (direction == 0) {
            moveBackward();
        }

    }
}

