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
	const static int RIGHT_SPEEDS[21] = {
	        200, 150, 105, 80, 65, 41, 30, 20, 10, // reverse
	        0, // definitely stop
	        -10, -20, -30, -41, -60, -70, -88, -95, -180, -200, -255 // forward
	};

	const static int LEFT_MAX = 9;
	const static int LEFT_MIN = -8;
	const static int RIGHT_MAX = 8;
	const static int RIGHT_MIN = -7;

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
	void arc(double percent);

	/*void setStraightLine(double percent);
	void arcLeft(double percent);
	void arcRight(double percent);
	void arc(double percent);
	void reverse(double percent);
	void stop();*/
};

#endif /* MOTORCONTROLLER_H_ */
