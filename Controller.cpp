/*
 * Controller.cpp
 *
 *  Created on: 21/04/2016
 *      Author: mgoo
 */

#include "Controller.h"

Controller Controller::instance;

Controller Controller::getInstance(){
	if (!instance){makeInstance();}
	return instance;
}
int Controller::makeInstance(){
	if (!instance){
		instance = new Controller();
		return 0;
	} else {
		return 1;
	}
}

Controller::Controller() {

}

Controller::~Controller() {

}

