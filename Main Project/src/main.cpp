#include <stdio.h>
#include <time.h>
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"
#include "CameraController.h"

extern "C" int  InitHardware();
extern "C" int  Sleep(int sec, int  usec);

int main(){
	InitHardware();
	NetworkController *network_controller = (NetworkController *)NetworkController::getInstance();
	MotorController *motor_controller = (MotorController *)MotorController::getInstance();
	IRController *IR_controller = (IRController *)IRController::getInstance();
	CameraController *camera_controller = (CameraController *)CameraController::getInstance();
	printf("it worked");
	return  0;
}
