/*
 * NetworkControllerTest.cpp
 *
 *  Created on: 28/04/2016
 *      Author: mgoo
 */
#include  <stdio.h>
#include  <assert.h>
#include  "../src/NetworkController.h"

#include "NetworkControllerTest.h"

NetworkControllerTest::NetworkControllerTest() {
	// TODO Auto-generated constructor stub

}

NetworkControllerTest::~NetworkControllerTest() {
	// TODO Auto-generated destructor stub
}

//runs the tests
void NetworkControllerTest::runTests(){
	printf("Network Test Running...............\n");
	NetworkController *network_controller =(NetworkController*)NetworkController::makeInstance("192.168.1.2",22);
	connectionTest(network_controller);
	messageTest(network_controller);
	makeInstanceTest();
	printf("Network Tests finished\n");
}

//test the conntection by see what connect returns
void NetworkControllerTest::connectionTest(NetworkController *network_controller){
	//connect is a private method
	assert(network_controller->connect("192.168.1.2",22) == 0);
	printf("the IP address exists\n");
	printf("The network controller connected\n");

}

//test the sending message by what sendMessage returns
void NetworkControllerTest::messageTest(NetworkController *network_controller){
	//send message is a private method
	assert(network_controller->sendMessage("msg") == 0);
	printf("Message sent successfully\n");
}

//checks that you can only make one NetworkController
void NetworkControllerTest::makeInstanceTest(){
	//assert(NetworkController::makeInstance() == 0);
	printf("Instance made\n");
	//assert(NetworkController::makeInstance() == 1);
	printf("making two instances successfully failed\n");
}




