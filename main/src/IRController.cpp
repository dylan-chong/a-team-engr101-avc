/*
 * IRController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "IRController.h"

// returns 0 if made a new IR controller retruns 1 if the controller already exists
int Controller::makeInstance(){
	if (!instance){
		instance = new IRController();
		return 0;
	} else {
		return 1;
	}
}//test comment please ignore

//This is the constructor
IRController::IRController() {
}

//this is the destructor
IRController::~IRController() {

}



