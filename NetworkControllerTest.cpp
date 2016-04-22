#include  <stdio.h>
#include  <assert.h>
#include  "NetworkController.h"

class NetworkControllerTest : public NetworkController{
public:
	NetworkControllerTest();
	~NetworkControllerTest();
	void makeInstanceTest();
	void connectionTest(NetworkController*);
	void messageTest(NetworkController*);
	void runTests();
};

int main(){
	NetworkControllerTest nct = new NetworkControllerTest();
	nct.runTests();
	return  0;
}

NetworkControllerTest::NetworkControllerTest(){
	//does nothing
}

NetworkControllerTest::~NetworkControllerTest(){
	//also does nothing
}

//runs the tests
void NetworkControllerTest::runTests(){
	printf("Test Running");
	NetworkController *network_controller = NetworkController::getInstance();
	connectionTest(network_controller);
	messageTest(network_controller);
	makeInstanceTest();
}

//test the conntection by see what connect returns
void NetworkControllerTest::connectionTest(NetworkController *network_controller){
	assert(network_controller->connect == 0);
	printf("the IP address exists");
	printf("The network controller connected");

}

//test the sending message by what sendMessage returns
void NetworkControllerTest::messageTest(NetworkController *network_controller){
	assert(network_controller->sendMessage("msg") == 0);
	printf("Message sent successfully");
}

//checks that you can only make one NetworkController
void NetworkControllerTest::makeInstanceTest(){
	assert(NetworkController::makeInstance() == 0);
	printf("Instance made");
	assert(NetworkController::makeInstance() == 1);
	printf("making two instances successfully failed");
}



