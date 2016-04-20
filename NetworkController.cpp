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

//This is the only instace of the NetworkController that can exist ie. the singleton design pattern
NetworkController NetworkController::instance = new NetworkController("192.168.1.2",22);


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
	//connect_to_server(IP_address,port);
}

//sends a message to the gate
void NetworkController::sendMessage(char message[]){
	send_to_server(message);
}

//recieves a message from the gate
char NetworkController::recieveMessage(char message[]){
	return receive_from_server(message);
}

//returns the instance of the NetworkController
NetworkController NetworkController::getInstance(){
	return instance;
}

