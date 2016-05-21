#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"
#include "PidController.h"

extern "C" int init(int d_lev);
extern "C" int Sleep(int sec, int  usec);

int main(){
	init(1);
	NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2",22);
	MotorController *motor_controller = MotorController::makeInstance();
	IRController *IR_controller = IRController::makeInstance();
	CameraController *camera_controller = CameraController::makeInstance();
	PidController *pid_controller = PidController::makeInstance();

	for (int count = 0 ; count<300; count++){
		//printf("count: %d\n", count);
		double sumC = camera_controller->update();
		double pid_val = pid_controller->getPIDValue(sumC);
		printf("Sum: %f\n", sumC);
		printf("MotoValue: %f\n", pid_val);

		//motor_controller->arc(camera_controller->getDir(), sumC);
		//printf("loop\n");
	}
	motor_controller->setStraightLine(0);
	printf("it worked\n");

	return  0;
}
