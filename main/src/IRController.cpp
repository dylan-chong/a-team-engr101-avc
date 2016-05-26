/*
 * IRController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "IRController.h"

#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int read_analog(int ch_adc);
extern "C" int Sleep(int sec, int usec);

//Makes a new IR Controller and returns a pointer to it
IRController *IRController::makeInstance() {
    instance = new IRController();
    return (IRController *) instance;
}

//This is the constructor
IRController::IRController() {
    leftThreshold = 0;
    rightThreshold = 0;
    middleThreshold = 0;
    thresholdSet = false;

    lastLeftDistance = 0;
    lastRightDistance = 0;
    lastMiddleDIstance = 0;
}

//this is the destructor
IRController::~IRController() {

}

///Setting whole bunch of default values
float IRController::getDistanceFromSensor(int sensorPin) {

    // Jonah do your calculation here then
    // Formula distance = Voltage/samples http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
    // 26 = range , 26/1024*reading

    int pinReading = read_analog(sensorPin);

    float multiplier = (float) (26.0 / 1024.0);
    float distance = multiplier * (1024 - pinReading) - 9; //4 is the offset as readings are in the range of 4-30 cm

    return distance;
}

float IRController::getLeftDistance() {
    return getDistanceFromSensor(0);
}

float IRController::getMiddleDistance() {
    return getDistanceFromSensor(1);
}

float IRController::getRightDistance() {
    return getDistanceFromSensor(2);
}

void IRController::setThreshold(float left, float right, float middle) {
    leftThreshold = left;
    rightThreshold = right;
    middleThreshold = middle;
}

double IRController::update() {
    if (!thresholdSet) {
        setThreshold(0.0, 0.0, 0.0); //TEMPORARILY SETTING THRESHOLD TO 0, change this when connecting to the controller
        thresholdSet = true;
    } else {

    }
    return 1.0;
}

bool IRController::inMaze() {
    if (getLeftDistance() < 5 && getRightDistance() < 5) {
        return 1;
    }
    return 0;
}


