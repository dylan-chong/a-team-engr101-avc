/*
 * MotorController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

//Variables for the motorController Class

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Controller.h"

class MotorController: public Controller{
	friend class MotorControllerTest;
private:
	const static int LEFT_MOTOR=1;
	const static int RIGHT_MOTOR=2;
	const static int MAX_SPEED=255;
	const static int REVERSE=-255;

public:
	static MotorController* makeInstance();
	virtual ~MotorController();
	MotorController();

	void setStraightLine(double percent);
	void arcLeft(double percent);
	void arcRight(double percent);
	void arc(char dir, double percent);

};

#endif /* MOTORCONTROLLER_H_ */
