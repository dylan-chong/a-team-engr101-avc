/*
 * Controller.h
 *
 *  Created on: 21/04/2016
 *      Author: mgoo
 *
 *      this is basically forces all controller to use the singleton design pattern
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

class Controller {
private:

public:
	static Controller* instance;
	static Controller* getInstance();
	Controller();
	virtual ~Controller();
};

#endif /* CONTROLLER_H_ */
