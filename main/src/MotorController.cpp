/*
 * MotorController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "MotorController.h"



// returns 0 if made a new Motor controller retruns 1 if the controller already exists
MotorController* Controller::makeInstance(){
		instance = &(new MotorController());
		return instance;
}

//This is the constructor
MotorController::MotorController() {
}

//this is the destructor
MotorController::~MotorController() {

}



