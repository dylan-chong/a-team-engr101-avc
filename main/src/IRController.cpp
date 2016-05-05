/*
 * IRController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "IRController.h"

//Makes a new IR Controller and returns a pointer to it
IRController* IRController::makeInstance(){
		instance = new IRController();
		return (IRController*)instance;
}

//This is the constructor
IRController::IRController() {
}

//this is the destructor
IRController::~IRController() {

}



