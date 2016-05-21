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
	const float KP = 0.08;//0.5; // TODO LATER adjust values (look at my photos)
	const float KD = .5;//5.0;

	const int IMG_WIDTH = 320; // TODO ASK ANDREW reference the camera module for constants?

	clock_t start = clock();

	int previousLineValue;
	long previousTime = -1;

	long getCurrentTime();
	int getProportional(int lineValue);
	int getDerivative(int lineValue, float timeDiff, int prevLineValue);
public:
	static PidController* makeInstance();
	PidController();
	virtual ~PidController();

	double getPIDValue(int lineValue);
};
#endif /* PIDCONTROLLER_H_ */
