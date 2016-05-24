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

	motor_controller->moveForward();

	while (true) {
		//printf("count: %d\n", count);
		int sumC = camera_controller->update(CameraController::CENTER_ROW);
		double pid_val = pid_controller->getPIDValue(sumC);
		//printf("Sum: %d\n", sumC);//debuging print
		//printf("MotoValue: %f\n", pid_val);//debuging print
		motor_controller->arc(pid_val);
		//motor_controller->arc(camera_controller->getDir(), sumC);
		printf("**************************************\n");//debuging print
		sleepMillis(500);
	}
	motor_controller->stopMovement();
	printf("Program Ended\n");

	return  0;
}

void sleepMillis(int millis) {
	for (int a = 0; a < millis; a++) {
		Sleep(0, 1000);
	}
}
