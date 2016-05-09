/*
 * MotorController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Controller.h"

class MotorController: public Controller{
	friend class MotorControllerTest;
private:
	const int LEFT_MOTOR;
	const int RIGHT_MOTOR;
	const int MAX_SPEED;

public:
	static MotorController* makeInstance();
	virtual ~MotorController();
	MotorController();

	void setStraightLine();
	void arcLeft(double percent);
	void arcRight(double percent);
	void arc(char dir, double percent);

};

#endif /* MOTORCONTROLLER_H_ */
