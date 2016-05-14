/*
 * IRController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

#ifndef IRCONTROLLER_H_
#define IRCONTROLLER_H_

#include "Controller.h"

class IRController: public Controller{
friend class IRControllerTest;
private:

public:
	static IRController* makeInstance();
	virtual ~IRController();
	IRController();
};

#endif /* IRCONTROLLER_H_ */
