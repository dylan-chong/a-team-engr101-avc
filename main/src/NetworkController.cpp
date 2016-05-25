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
NetworkController::NetworkController(char IP_address[15], int port){
	connect(IP_address, port); //conects to the gate when the controller is made
}

//this is the destructor
NetworkController::~NetworkController() {

}

//connects to the gate
int NetworkController::connect(char IP_address[15], int port){
	try{
		connect_to_server(IP_address,port); //connects to the server
		return 0;
	} catch (int e){
		return e;
	}

}

//opens the gate returns 0 if worked correctly
int NetworkController::openGate(){
	char* pass;
	send_to_server("Please"); //sends Please to the gate
	receive_from_server(pass); //gets the password
	send_to_server(pass); //sends the password to the gate
	return 0;
}

