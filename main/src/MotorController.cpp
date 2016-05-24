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
    set_motor(1, -speed * 10);//for test on simulator
}

void MotorController::setRight(int speed) {
    //freezeIfSpeedOutOfRange(speed);
    //set_motor(1, RIGHT_SPEEDS[speed + NUMBER_OF_REVERSE_SPEEDS]);
    set_motor(2, -speed * 10); //for testing on the simulator
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

void MotorController::moveForward() {
    moveStraightAtSpeed(8);
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

void MotorController::arc(double direction, int shouldMoveForward) {
    printf("Direction: %f\n", direction);

    if (shouldMoveForward == 1) {
        printf("Going forwards\n");

        if (direction < 0) {
            int left = (int) ((LEFT_MAX - LEFT_MIN) * (direction * 100) + LEFT_MAX);
            setLeft(left);
            setRight(RIGHT_MAX);
            printf("Turning left: %d\n", left);
        } else if (direction > 0) {
            int right = (int) ((RIGHT_MIN - RIGHT_MAX) * (direction * 100) + RIGHT_MAX);
            setLeft(LEFT_MAX);
            setRight(right);
            printf("Turning RIGHT: %d\n", right);
        } else if (direction == 0) {
            moveForward();
        }

    } else if (shouldMoveForward == 0) { // needs testing
        printf("Going back\n");

        if (direction < 0) {
            int left = (int) ((LEFT_MAX - LEFT_MIN) * (direction * 100) + LEFT_MAX);
            setLeft(-left);
            setRight(-RIGHT_MAX);
            printf("Turning left: %d\n", left);
        } else if (direction > 0) {
            int right = (int) ((RIGHT_MIN - RIGHT_MAX) * (direction * 100) + RIGHT_MAX);
            setLeft(-LEFT_MAX);
            setRight(-right);
            printf("Turning RIGHT: %d\n", right);
        } else if (direction == 0) {
            moveBackward();
        }

    }
}

