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

public:
	static CameraController* makeInstance();
	virtual ~CameraController();
	CameraController();
};
#endif /* CAMERACONTROLLER_H_ */
