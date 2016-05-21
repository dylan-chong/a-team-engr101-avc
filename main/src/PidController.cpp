/*
 * PidController.cpp
 *
 *  Created on: 21/05/2016
 *      Author: root
 */

#include "PidController.h"
#include  <time.h>

PidController::PidController() {
	previousLineValue = 0;
}

PidController::~PidController() {
	// TODO Auto-generated destructor stub
}

PidController* PidController::makeInstance(){
	instance = new PidController();
	return (PidController*)instance;
}

/** Private */

long PidController::getCurrentTime() { // in seconds
    return (long) time(NULL);
}

int PidController::getProportional(int lineValue) {
    int proportional_signal = lineValue * KP;
    // int motorVal = proportional_signal / (IMG_WIDTH / 2) * 255; // do we even need this?
    return proportional_signal;
}

int PidController::getDerivative(int lineValue, long timeDiff, int prevLineValue) {
    int derivative_signal = (lineValue - prevLineValue / (double) timeDiff) * KD;
    return derivative_signal;
}

/** Public */

int PidController::getPIDValue(int lineValue) {
    // Algorithm for calculating PID was taken from the Kaiwhata wiki
    // https://github.com/kaiwhata/ENGR101-2016/wiki/PID-(Proportional-Integral-Derivative)-Control

    int proportional = getProportional(lineValue);
    int derivative;
    long currentTime;

    if (previousTime != -1) {
        currentTime = getCurrentTime();
        long timeDiff = currentTime - previousTime;
        derivative = getDerivative(lineValue, timeDiff, previousLineValue);
    } else {
        derivative = 0;
    }

    int pid = proportional + derivative;

    previousTime = currentTime;
    previousLineValue = lineValue;

    return pid;
}

