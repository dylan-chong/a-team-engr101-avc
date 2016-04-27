/*
 * mainTest.cpp
 *
 *  Created on: 28/04/2016
 *      Author: Andrew
 */

#include  <stdio.h>
#include  <assert.h>
#include "CameraControllerTest.cpp"
#include "IRControllerTest.cpp"
#include "MotorControllerTest.cpp"
#include "NetworkControllerTest.cpp"

int main(){
	CameraControllerTest camTest = new CameraControllerTest();
	camTest.runTests();
	IRControllerTest IRTest = new IRControllerTest();
	IRTest.runTests();
	MotorControllerTest motorTest = new MotorControllerTest();
	motorTest.runTests();
	NetworkControllerTest networkTest = new NetworkControllerTest();
	networkTest.runTests();
}



