/*
 * PidController.cpp
 *
 *  Created on: 21/05/2016
 *      Author: root
 */

#include "PidController.h"
#include <time.h>
#include <stdio.h>

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
	//printf("Current Time: %f\n",time(NULL));//debuging print
    return (long) time(NULL);
}

int PidController::getProportional(int lineValue) {
    int proportional_signal = lineValue * KP;
    // int motorVal = proportional_signal / (IMG_WIDTH / 2) * 255; // do we even need this?
    return proportional_signal;
}

int PidController::getDerivative(int lineValue, float timeDiff, int prevLineValue) {
	if ((double)timeDiff==0)timeDiff=1; //stops deviding by 0
	//printf("lineVal: %d\n", lineValue); //debug print
	//printf("timeDif: %f\n", (double)timeDiff); //debug print
	//printf("preLineVal: %d\n", prevLineValue); //debug print

    int derivative_signal = (int)(((double)lineValue - (double)prevLineValue / (double) timeDiff) * (double)KD);
    return derivative_signal;
}

/** Public */

double PidController::getPIDValue(int lineValue) {
    // Algorithm for calculating PID was taken from the Kaiwhata wiki
    // https://github.com/kaiwhata/ENGR101-2016/wiki/PID-(Proportional-Integral-Derivative)-Control

    int proportional = getProportional(lineValue);
    int derivative;
    long currentTime;

    if (previousTime != -1) {
        currentTime = getCurrentTime();
        float timeDiff = float(clock()-start);
        derivative = getDerivative(lineValue, timeDiff, previousLineValue);
    } else {
        derivative = 0;
    }
    printf("P: %d\n", proportional);
    printf("D: %d\n", derivative);

    int pid = proportional + derivative;

    previousTime = currentTime;
    previousLineValue = lineValue;

    return (double)(pid)/(double)500;
}

