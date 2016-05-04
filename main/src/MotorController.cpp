/*
 * MotorController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "NetworkController.h"



// returns 0 if made a new Motor controller retruns 1 if the controller already exists
int Controller::makeInstance(){
	if (!instance){
		instance = new MotorController();
		return 0;
	} else {
		return 1;
	}
}

//This is the constructor
MotorController::MotorController() {
}

//this is the destructor
MotorController::~MotorController() {

}



