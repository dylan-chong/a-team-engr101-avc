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
	const int WHITE_THRESHOLD;
	int center;
	int previousError;

public:
	static CameraController* makeInstance();
	virtual ~CameraController();
	CameraController();

	int[] getWhiteArray();
	int sum(int white[]);
	int differential(int sum);
};
#endif /* CAMERACONTROLLER_H_ */
