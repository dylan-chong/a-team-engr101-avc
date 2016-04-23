/*
 * CameraController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "CameraContoller.h"

// returns 0 if made a new Camera controller retruns 1 if the controller already exists
int Controller::makeInstance(){
	if (!instance){
		instance = new CameraController();
		return 0;
	} else {
		return 1;
	}
}

//This is the constructor
CameraController::CameraController() {
}

//this is the destructor
CameraController::~CameraController() {

}



