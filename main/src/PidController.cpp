/*
 * PidController.cpp
 *
 *  Created on: 21/05/2016
 *      Author: root
 */

#include "PidController.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

PidController::PidController() : KP(0.0032/*0.0002*/), KD(0.000075/*0.012*/), KI(0.00), KN(0.000), IMG_WIDTH(0){
    previousClock = clock();

    previousLineValue = 0;
    previousDerivativeValue = 0;
    intergral = 0;
}

PidController::~PidController() { }

PidController *PidController::makeInstance() {
    instance = new PidController();
    return (PidController *) instance;
}

/******************** Private ********************/

double PidController::getTimeDiff() { // in clock ticks
    double timeDiff = (double) (clock() - previousClock);
    if (timeDiff == 0) timeDiff = 0.0001; //stops dividing by 0
    previousClock = clock();
    return timeDiff;
}

//returns the line value
int PidController::getProportional(int lineValue) {
    return lineValue;
}

//gets the change in the line value with respect to time
double PidController::getDerivative(int lineValue, double timeDiff, int prevLineValue) {
    double derivative_signal = ((double) (lineValue - prevLineValue) / timeDiff);
    return derivative_signal;
}

//gets the integral I was thinking of using this to automatically tune the Kp and Kd
int PidController::getIntergral(int lineValue) {
    intergral += lineValue;
    return intergral;
}

//gets the derivative of the derivative (this is derviative filtering http://www2.ece.ohio-state.edu/~passino/lab3prelab.pdf if you want to know more)
double PidController::getFOC(double derivative, double timeDiff, double previousDerivative) {
    return (derivative - previousDerivative) / timeDiff;
}

//******************** Public ********************//

double PidController::getPIDValue(int lineValue) {
    // Algorithm for calculating PID was taken from the Kaiwhata wiki but has been refactored
    // greatly, with lots of new code added.
    // https://github.com/kaiwhata/ENGR101-2016/wiki/PID-(Proportional-Integral-Derivative)-Control

    double timeDiff = getTimeDiff();

    int proportional = getProportional(lineValue);
    double derivative = getDerivative(lineValue, timeDiff, previousLineValue);
    double secondDerivative = getFOC(derivative, timeDiff, previousDerivativeValue);
    int integral = getIntergral(lineValue);

    //printf("Line Value: %d\n", lineValue);
    //printf("P: %d\n", proportional);
    //printf("D: %f\n", derivative);
    //printf("I: %d\n", integral);
    //printf("N: %f\n", secondDerivative);

    double pid = (KP * proportional + (KD * derivative - KN * secondDerivative) + KI * integral)*2;

    previousLineValue = lineValue;
    previousDerivativeValue = derivative;

    return pid;
}

