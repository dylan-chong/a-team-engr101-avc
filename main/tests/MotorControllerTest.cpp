/*
 * MotorControllerTest.cpp
 *
 *  Created on: 28/04/2016
 *      Author: mgoo
 */
#include  <stdio.h>
#include  <assert.h>
#include "MotorControllerTest.h"
#include  "../src/MotorController.h"

MotorControllerTest::MotorControllerTest() {
	// TODO Auto-generated constructor stub

}

MotorControllerTest::~MotorControllerTest() {
	// TODO Auto-generated destructor stub
}

//runs the tests
void MotorControllerTest::runTests(){
	printf("Test Running");
	MotorController *motor_controller = (MotorController*)MotorController::getInstance();
}
