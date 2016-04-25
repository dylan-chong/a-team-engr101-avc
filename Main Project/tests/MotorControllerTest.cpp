#include  <stdio.h>
#include  <assert.h>
#include  "../src/MotorController.h"

class MotorControllerTest : public MotorController{
public:
	MotorControllerTest();
	~MotorControllerTest();
	void runTests();
};

int main(){
	MotorControllerTest mct = new MotorControllerTest();
	mct.runTests();
	return  0;
}

MotorControllerTest::MotorControllerTest(){
	//does nothing
}

MotorControllerTest::~MotorControllerTest(){
	//also does nothing
}

//runs the tests
void MotorControllerTest::runTests(){
	printf("Test Running");
	MotorController *motor_controller = MotorController::getInstance();
}


