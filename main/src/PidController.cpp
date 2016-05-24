/*
 * PidController.cpp
 *
 *  Created on: 21/05/2016
 *      Author: root
 */

#include "PidController.h"
#include <time.h>
#include <stdio.h>

PidController::PidController() : KP(0.002), KD(0.0001), KI(0), KN(0), IMG_WIDTH(0), PID_BOUNDS(5.0) {
    previousClock = clock();

    previousLineValue = 0;
    previousDerivativeValue = 0;
    intergral = 0;
}

PidController::~PidController() {
    // TODO Auto-generated destructor stub
}

PidController *PidController::makeInstance() {
    instance = new PidController();
    return (PidController *) instance;
}

/** Private */

double PidController::getTimeDiff() { // in clock ticks
    double timeDiff = (double) (clock() - previousClock);
    previousClock = clock();
    return timeDiff;
}

//returns the line value
int PidController::getProportional(int lineValue) {
    int proportional_signal = lineValue;// * KP;
    // int motorVal = proportional_signal / (IMG_WIDTH / 2) * 255; // do we even need this?
    return proportional_signal;
}

//gets the change in the line value with respect to time
double PidController::getDerivative(int lineValue, double timeDiff, int prevLineValue) {
//    printf("lineValue: %d\n", lineValue);
//    printf("previous Line Value: %d\n", prevLineValue);
//    printf("timeDiff: %f\n", timeDiff);
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
    double FOC_derivative_signal = ((double) (derivative - previousDerivative) / timeDiff);
    return FOC_derivative_signal;
}

/** Public */

double PidController::getPIDValue(int lineValue) {
    // Algorithm for calculating PID was taken from the Kaiwhata wiki
    // https://github.com/kaiwhata/ENGR101-2016/wiki/PID-(Proportional-Integral-Derivative)-Control

    double timeDiff = getTimeDiff();
    if (timeDiff == 0) timeDiff = 0.0001; //stops dividing by 0

    int proportional = getProportional(lineValue);
    double derivative = getDerivative(lineValue, timeDiff, previousLineValue);
    double secondDerivative = getFOC(derivative, timeDiff, previousDerivativeValue);
    int intergral = getIntergral(lineValue);

    // Removing some elements for testing
    intergral = 0;
    secondDerivative = 0;

    printf("Line Value: %d\n", lineValue);
    printf("P: %d\n", proportional);
    printf("D: %f\n", derivative);
    printf("I: %d\n", intergral);
    printf("N: %f\n", secondDerivative);

    double pid = (KP * proportional - (KD * derivative - KN * secondDerivative) + KI * intergral);

    // TODO test
    printf("PID NO BOUNDS: %f\t", pid);
    if (pid > PID_BOUNDS) pid = PID_BOUNDS;
    if (pid < -PID_BOUNDS) pid = -PID_BOUNDS;
    printf("PID BOUNDED: %f\n", pid);

    previousLineValue = lineValue;
    previousDerivativeValue = derivative;

    return pid / PID_BOUNDS;
}

