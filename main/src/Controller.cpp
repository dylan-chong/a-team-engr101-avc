/*
 * Controller.cpp
 *
 *  Created on: 21/04/2016
 *      Author: mgoo
 */

#include "Controller.h"

Controller *Controller::instance;

Controller *Controller::getInstance() {
    return instance;
}

Controller::Controller() {

}

Controller::~Controller() {

}

/*int main(){
	return 0;
}*/
