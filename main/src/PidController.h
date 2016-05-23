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
	const float KP = 0.002;//0.5; // TODO LATER adjust values (look at my photos)
	const float KD = 0.0001;//5.0;
	const float KI = 0;//intergral sensitivity
	const float KN = 0;//derivative filtering sensitivity

	const int IMG_WIDTH = 320; // TODO ASK ANDREW reference the camera module for constants?

	clock_t start;

	int previousLineValue;
	double previousDerivativeValue;
	int intergral;

	float getTimeDiff();
	int getProportional(int lineValue);
	double getDerivative(int lineValue, float timeDiff, int prevLineValue);
	int getIntergral(int lineValue);
	double getFOC(double derivative, float timeDiff, double previousDerivative);
public:
	static PidController* makeInstance();
	PidController();
	virtual ~PidController();

	double getPIDValue(int lineValue);
};
#endif /* PIDCONTROLLER_H_ */
