/*
 * CameraController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

#ifndef CAMERACONTROLLER_H_
#define CAMERACONTROLLER_H_

#include "Controller.h"

class CameraController: public Controller{
friend class CameraControllerTest;
private:
	const static int WHITE_THRESHOLD = 140;
	const static double Kp=1;
	const static double Kd=1;
	const static double Ki=0;

	int center = 120;
	int previousError = 0;
	char dir = 'l';

public:
	static CameraController* makeInstance();
	virtual ~CameraController();
	CameraController();

	char getDir();
	int * getWhiteArray();
	int sum(int white[]);
	int differential(int sum);
};
#endif /* CAMERACONTROLLER_H_ */
