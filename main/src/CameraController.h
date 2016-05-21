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


	int white[];
	int previousError;
	char dir;

public:
	const static int CENTER_ROW = 120;

	static CameraController* makeInstance();
	virtual ~CameraController();
	CameraController();

	char getDir();
	int getSum(int row);
	int update(int row);
};
#endif /* CAMERACONTROLLER_H_ */
