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
	//const static int LEFT_MOTOR=2;
	//const static int RIGHT_MOTOR=1;

	const static int LEFT_BASE_SLOW = 40;
	const static int RIGHT_BASE_SLOW = 41;
	/*const static int MAX_SPEED_LEFT=200; //commented out couse it goes way faster on the simulator
	const static int MAX_SPEED_RIGHT=230;*/


	/**Simulator Values*/
	const static int MAX_SPEED_LEFT=-20; //these are negative because the simulator seems to be backwards
	const static int MAX_SPEED_RIGHT=-20;
	const static int LEFT_MOTOR=1; //swpaed cause simulator
	const static int RIGHT_MOTOR=2;
public:
	static MotorController* makeInstance();
	virtual ~MotorController();
	MotorController();

	void setStraightLine(double percent);
	void rotate(double percent);
	void arcLeft(double percent);
	void arcRight(double percent);
	void arc(double percent);
	void reverse(double percent);
	void stop();

};

#endif /* MOTORCONTROLLER_H_ */
