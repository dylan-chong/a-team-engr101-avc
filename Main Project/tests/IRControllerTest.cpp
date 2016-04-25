#include  <stdio.h>
#include  <assert.h>
#include  "../src/NetworkController.h"

class IRControllerTest : public IRController{
public:
	IRControllerTest();
	~IRControllerTest();
	void runTests();
};

int main(){
	IRControllerTest IRct = new IRControllerTest();
	IRct.runTests();
	return  0;
}

IRControllerTest::IRControllerTest(){
	//does nothing
}

IRControllerTest::~IRControllerTest(){
	//also does nothing
}

//runs the tests
void IRControllerTest::runTests(){
	printf("Test Running");
	IRController *IR_controller = IRController::getInstance();
}
