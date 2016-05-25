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
#include <stdlib.h>
#include <stdio.h>

extern "C" int set_motor(int motor, int speed);
extern "C" int Sleep(int sec, int usec);

MotorControllerTest::MotorControllerTest() {
	// TODO Auto-generated constructor stub

}

MotorControllerTest::~MotorControllerTest() {
	// TODO Auto-generated destructor stub
}
void MotorControllerTest::testMotor(){
	/*arc(0,1);//right
	    printf("Turing Forward ********");
	    Sleep(2,0);
	    arc(1,1);//right
	    printf("Turing Right********");
	    Sleep(2,0);
	   arc(-1,1);//left
	    printf("Turing Right********");
	    Sleep(2,0);*/
}
//runs the tests
void MotorControllerTest::runTests(){
	printf("Motor Test Running...............\n");
	MotorController *motor_controller = (MotorController*)MotorController::getInstance();
	testMotor();
	printf("Network Tests finished\n");
}


