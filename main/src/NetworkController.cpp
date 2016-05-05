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

//makes a new Network controller and retruns a pointer to it
NetworkController* NetworkController::makeInstance(char ip[15], int port){
	instance = new NetworkController(ip, port);
	return (NetworkController*)instance;
}

//This is the constructor it sets the IP_address and port variables then calls the connect function
NetworkController::NetworkController(char IP_address[15], int port)
:IP_address(IP_address),port(port) {
	connect();
}

//this is the destructor
NetworkController::~NetworkController() {

}

//connects to the gate
int NetworkController::connect(){
	return 0;//connect_to_server("" + IP_address,port);
}

//sends a message to the gate
int NetworkController::sendMessage(char message[]){
	return 0;//send_to_server(message);
}

//recieves a message from the gate
char NetworkController::recieveMessage(char message[]){
	return 0;//receive_from_server(message);
}

//opens the gate returns 0 if worked correctly
int NetworkController::openGate(){
	//sendMessage("" + recieveMessage("Please"));
	return 0;
}

