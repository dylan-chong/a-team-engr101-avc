/*
 * PidController.h
 *
 *  Created on: 21/05/2016
 *      Author: root
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

#include "Controller.h"
#include <time.h>

class PidController: public Controller{
friend class PidControllerTest;
private:
	const float KP;//0.5; // TODO LATER adjust values (look at my photos)
	const float KD;//5.0;
	const float KI;//intergral sensitivity
	const float KN;//derivative filtering sensitivity
	const double PID_BOUNDS = 5.0; // TODO FIX

	const int IMG_WIDTH; // TODO ASK ANDREW reference the camera module for constants?

	clock_t previousClock;

	int previousLineValue;
	double previousDerivativeValue;
	int intergral;

	double getTimeDiff();
	int getProportional(int lineValue);
	double getDerivative(int lineValue, double timeDiff, int prevLineValue);
	int getIntergral(int lineValue);
	double getFOC(double derivative, double timeDiff, double previousDerivative);
public:
	static PidController* makeInstance();
	PidController();
	virtual ~PidController();

	double getPIDValue(int lineValue);
};
#endif /* PIDCONTROLLER_H_ */
