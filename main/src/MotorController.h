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

public:
	MotorController* makeInstance();
	virtual ~MotorController();
	MotorController();
};

#endif /* MOTORCONTROLLER_H_ */
