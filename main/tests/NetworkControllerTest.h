/*
 * NetworkControllerTest.h
 *
 *  Created on: 28/04/2016
 *      Author: mgoo
 */

#ifndef MAIN_PROJECT_TESTS_NETWORKCONTROLLERTEST_H_
#define MAIN_PROJECT_TESTS_NETWORKCONTROLLERTEST_H_

class NetworkControllerTest {
public:
	NetworkControllerTest();
	virtual ~NetworkControllerTest();
	void makeInstanceTest();
	void connectionTest(NetworkController*);
	void messageTest(NetworkController*);
	void runTests();
};

#endif /* MAIN_PROJECT_TESTS_NETWORKCONTROLLERTEST_H_ */
