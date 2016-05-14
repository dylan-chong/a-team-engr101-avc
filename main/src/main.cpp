#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"

extern "C" int init(int d_lev);
extern "C" int sleep(int sec, int  usec);

int main(){
	init(1);
	NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2",22);
	MotorController *motor_controller = MotorController::makeInstance();
	IRController *IR_controller = IRController::makeInstance();
	CameraController *camera_controller = CameraController::makeInstance();

	for (int count = 0 ; count<1000; count++){
		printf("count: %d\n", count);
		printf("%d\n", camera_controller->update());
		motor_controller->arc('l', .5);
		printf("loop\n");
	}
	motor_controller->setStraightLine(0);
	printf("it worked\n");

	return  0;
}
