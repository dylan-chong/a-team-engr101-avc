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
	const static int NUMBER_OF_REVERSE_SPEEDS = 9;
    int RIGHT_SPEEDS[21];
	const static int LEFT_MAX = 9;
	const static int LEFT_MIN = -8;
	const static int RIGHT_MAX = 8;
	const static int RIGHT_MIN = -7;
    /*const static int LEFT_MAX = 8;//Made motors the same for the simulator
	const static int LEFT_MIN = -7;
	const static int RIGHT_MAX = 8;
	const static int RIGHT_MIN = -7;*/

	const static float PERPENDICULAR_LEFT_TURN_TIME = 1.2345; // DANIEL calibrate this
	const static float PERPENDICULAR_RIGHT_TURN_TIME = 1.2345; // DANIEL calibrate this



	//const static int LEFT_MOTOR=2;
	//const static int RIGHT_MOTOR=1;

	//const static int LEFT_BASE_SLOW = 40;
	//const static int RIGHT_BASE_SLOW = 41;
	/*const static int MAX_SPEED_LEFT=200; //commented out couse it goes way faster on the simulator
	const static int MAX_SPEED_RIGHT=230;*/


	/**Simulator Values*/
	/*const static int MAX_SPEED_LEFT=-20; //these are negative because the simulator seems to be backwards
	const static int MAX_SPEED_RIGHT=-20;
	const static int LEFT_MOTOR=1; //swpaed cause simulator
	const static int RIGHT_MOTOR=2;*/

	void freezeIfSpeedOutOfRange(int speed);
	void setLeft(int speed);
    void setRight(int speed);
    void moveStraightAtSpeed(int speed);
    void freezeIfDirectionOutOfRange(double direction);
public:
	static MotorController* makeInstance();
	virtual ~MotorController();
	MotorController();

	void moveForward();
	void moveBackward();
	void stopMovement();
	void rotateLeft();
	void rotateRight();
	void arc(double percent, int forward);

	/*void setStraightLine(double percent);
	void arcLeft(double percent);
	void arcRight(double percent);
	void arc(double percent);
	void reverse(double percent);
	void stop();*/
};

#endif /* MOTORCONTROLLER_H_ */
