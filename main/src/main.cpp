#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"

extern "C" int  InitHardware();
extern "C" int  Sleep(int sec, int  usec);

int main(){
	InitHardware();
	NetworkController *network_controller = (NetworkController *)NetworkController::makeInstance("192.168.1.2",22);
	MotorController *motor_controller = (MotorController *)MotorController::makeInstance();
	IRController *IR_controller = (IRController *)IRController::makeInstance();
	CameraController *camera_controller = (CameraController *)CameraController::makeInstance();
	printf("it worked");
	return  0;
}
