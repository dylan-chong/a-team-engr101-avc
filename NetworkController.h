/*
 * NetworkController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 *      This is a header file that sets out whats in the NetworkContoller class
 *      to use the NetworkController class include NetworkConroller.h and call NetworkController::getInstance()
 */

#ifndef NETWORKCONTROLLER_H_
#define NETWORKCONTROLLER_H_

class NetworkController : public Controller{
private:
	const char IP_address[15];
	const int port;


public:
	NetworkController(char IP_address[15], int port);
	virtual ~NetworkController();

	int connect();
	int sendMessage(char message[]);
	char recieveMessage(char message[]);
	int openGate();
};

#endif /* NETWORKCONTROLLER_H_ */
