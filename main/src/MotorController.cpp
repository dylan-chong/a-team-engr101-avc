/*
 * MotorController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "MotorController.h"

//Makes a new Motor Controller and returns a pointer to it
MotorController* MotorController::makeInstance(){
		instance = new MotorController();
		return (MotorController*)instance;
}

//This is the constructor
MotorController::MotorController() {
}

//this is the destructor
MotorController::~MotorController() {

}



