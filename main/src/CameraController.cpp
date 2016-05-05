/*
 * CameraController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "CameraController.h"

//Controller* CameraController::instance;

//This is the constructor
CameraController::CameraController() {
}

//this is the destructor
CameraController::~CameraController() {

}

CameraController* CameraController::makeInstance(){
	instance = new CameraController();
	return (CameraController*)instance;
}



