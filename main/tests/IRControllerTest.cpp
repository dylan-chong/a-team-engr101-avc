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
	printf("IR Test Running...............\n");
	IRController *IR_controller = (IRController*)IRController::getInstance();

	printf("Network Tests finished\n");
}

IRControllerTest::IRControllerTest() {
	// TODO Auto-generated constructor stub

}

IRControllerTest::~IRControllerTest() {
	// TODO Auto-generated destructor stub
}

