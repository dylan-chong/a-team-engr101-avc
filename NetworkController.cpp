/*
 * NetworkController.cpp
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 */

#include "NetworkController.h"

extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);

/**
 * returns 0 if made a new Network controller retruns 1 if the controller already exists
 */
int Controller::makeInstance(){
	if (!instance){
		instance = new NetworkController("192.168.1.2",22);
		return 0;
	} else {
		return 1;
	}
}

//This is the constructor it sets the IP_address and port variables then calls the connect function
NetworkController::NetworkController(char IP_address[15], int port)
:IP_address(IP_address),port(port) {
	connect();
}

//this is the destructor
NetworkController::~NetworkController() {
	// TODO Auto-generated destructor stub
}

//connects to the gate
void NetworkController::connect(){
	//connect_to_server(getInstance().IP_address, getInstance().port);
	connect_to_server("" + IP_address,port);
}

//sends a message to the gate
void NetworkController::sendMessage(char message[]){
	send_to_server(message);
}

//recieves a message from the gate
char NetworkController::recieveMessage(char message[]){
	return receive_from_server(message);
}

//opens the gate returns 0 if worked correctly
int NetworkController::openGate(){
	sendMessage("" + recieveMessage("Please"));
	return 0;
}

