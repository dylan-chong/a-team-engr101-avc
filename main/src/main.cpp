#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"

extern "C" int  init_hardware();
extern "C" int  sleep(int sec, int  usec);

int main(){
	init_hardware();
	NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2",22);
	MotorController *motor_controller = MotorController::makeInstance();
	IRController *IR_controller = IRController::makeInstance();
	CameraController *camera_controller = CameraController::makeInstance();
	printf("it worked\n");
	return  0;
}
