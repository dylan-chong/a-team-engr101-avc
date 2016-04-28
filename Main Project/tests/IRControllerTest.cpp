/*
 * IRControllerTest.cpp
 *
 *  Created on: 28/04/2016
 *      Author: mgoo
 */

#include  <stdio.h>
#include  <assert.h>
#include  "../src/IRController.h"
#include "IRControllerTest.h"

//runs the tests
void IRControllerTest::runTests(){
	printf("IR Test Running");
	IRController *IR_controller = (IRController*)IRController::getInstance();
}

IRControllerTest::IRControllerTest() {
	// TODO Auto-generated constructor stub

}

IRControllerTest::~IRControllerTest() {
	// TODO Auto-generated destructor stub
}

