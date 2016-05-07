#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"

// these two init methods were in the merge conflict
// Andrew remove this comment once you see it
extern "C" int  init_hardware();
extern "C" int  init(int d_lev); 
extern "C" int  sleep(int sec, int  usec);

int main(){
	init_hardware();
	//init(0);
	NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2",22);

	MotorController *motor_controller = MotorController::makeInstance();
	IRController *IR_controller = IRController::makeInstance();
	CameraController *camera_controller = CameraController::makeInstance();
	printf("it worked\n");
	return  0;
}
