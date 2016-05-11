#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"

extern "C" int init(int d_lev);
extern "C" int  sleep(int sec, int  usec);

int main(){
	init(1);
	NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2",22);
	MotorController *motor_controller = MotorController::makeInstance();
	IRController *IR_controller = IRController::makeInstance();
	CameraController *camera_controller = CameraController::makeInstance();


	while(true){
		//printf("%d\n", camera_controller->update());
		motor_controller->arc('l', .5);
		printf("loop\n");
	}
	printf("it worked\n");
	return  0;
}
