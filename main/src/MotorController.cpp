/*
 * MotorController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "MotorController.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" int set_motor(int motor, int speed);

//Makes a new Motor Controller and returns a pointer to it
MotorController *MotorController::makeInstance() {
    instance = new MotorController();
    return (MotorController *) instance;
}

//This is the constructor
MotorController::MotorController() {
    RIGHT_SPEEDS[0] = 255;
    RIGHT_SPEEDS[1] = 140;
    RIGHT_SPEEDS[2] = 190;
    RIGHT_SPEEDS[3] = 150;
    RIGHT_SPEEDS[4] = 110;
    RIGHT_SPEEDS[5] = 65;
    RIGHT_SPEEDS[6] = 40;
    RIGHT_SPEEDS[7] = 35;
    RIGHT_SPEEDS[8] = 20;
    RIGHT_SPEEDS[9] = 0;
    RIGHT_SPEEDS[10] = -20;
    RIGHT_SPEEDS[11] = -30;
    RIGHT_SPEEDS[12] = -50;
    RIGHT_SPEEDS[13] = -70;
    RIGHT_SPEEDS[14] = -110;
    RIGHT_SPEEDS[15] = -165;
    RIGHT_SPEEDS[16] = -210;
    RIGHT_SPEEDS[17] = -235;
    RIGHT_SPEEDS[18] = -255;
//    RIGHT_SPEEDS[19] = -200; // no longer in range
//    RIGHT_SPEEDS[20] = -255;
}

//this is the destructor
MotorController::~MotorController() {

}

// ******************** PRIVATE IMPLEMENTATION ******************** //

// Refer to even-speeds.txt for nicer formatting of data

void MotorController::setLeft(int speed) {
    //set_motor(1, -(speed * 10 / 1.5));//ON pi FOR Dylans code
    set_motor(1, -speed * 7.5);
}

void MotorController::setRight(int speed) {
    //set_motor(2, (int)-(RIGHT_SPEEDS[(int) (speed/1.5) + NUMBER_OF_REVERSE_SPEEDS])); //FOR Dylans code
    set_motor(2, -(int) (((RIGHT_SPEEDS[(int) (speed) + NUMBER_OF_REVERSE_SPEEDS])) / 1.5));//for pid
}

void MotorController::moveStraightAtSpeed(int speed) {
    setLeft(speed);
    setRight(speed);
}
// ******************** PUBLIC METHODS ******************** //

void MotorController::moveForward() {
    moveStraightAtSpeed(8); //movefowards fast
}

void MotorController::moveBackward() {
    moveStraightAtSpeed(-3); //movebackwards
}

void MotorController::stopMovement() {
    setLeft(0);
    setRight(0);
}

// turn left on the spot
// right wheel doesn't seem to do anything
void MotorController::rotateLeft() {
    setLeft((int) (LEFT_MIN * .2));
    setRight((int) (RIGHT_MAX * .2));
}

// turn right on the spot
void MotorController::rotateRight() {
    printf("Right rotate: *******************");
    setLeft((int) (LEFT_MAX * .5));
    setRight((int) (RIGHT_MIN * .5));
}

// -1 is max left
// 0 is max forward
// 1 is max right
void MotorController::arc(double direction, double speedScale) {
    if (abs(direction) > 1)direction /= abs(direction); //makes direction between 1 & -1
    printf("Direction: %f\n", direction);

    if (direction < 0) { //left
        setLeft((int) (LEFT_MAX * (1 - abs((int) direction)) *
                       speedScale));    //sets the left motor to something less than the max speed
        setRight((int) (RIGHT_MAX * (speedScale - 0.05)));                        //sets the right motor to max speed
    } else if (direction > 0) { //right
        setLeft((int) (LEFT_MAX * speedScale));                        //sets the left motor the max speed
        setRight((int) (RIGHT_MAX * (1 - direction) *
                        speedScale));     //sets the right motor to something less than the max speed
    } else if (direction == 0) {
        moveForward();
    }

}