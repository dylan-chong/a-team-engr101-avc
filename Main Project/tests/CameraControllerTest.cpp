#include  <stdio.h>
#include  <assert.h>
#include  "../src/CameraController.h"

class CameraControllerTest : public CameraController{
public:
	CameraControllerTest();
	~CameraControllerTest();
	void runTests();
};

int main(){
	CameraControllerTest cct = new CameraControllerTest();
	cct.runTests();
	return  0;
}

CameraControllerTest::CameraControllerTest(){
	//does nothing
}

CameraControllerTest::~CameraControllerTest(){
	//also does nothing
}

//runs the tests
void CameraControllerTest::runTests(){
	printf("Test Running");
	CameraController *camera_controller = CameraController::getInstance();

}




