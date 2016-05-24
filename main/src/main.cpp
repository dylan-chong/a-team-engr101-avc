#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"
#include "PidController.h"

extern "C" int init(int d_lev);
extern "C" int Sleep(int sec, int  usec);

int forword = 1;

int main(){
	init(1);
	NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2",22);
	MotorController *motor_controller = MotorController::makeInstance();
	IRController *IR_controller = IRController::makeInstance();
	CameraController *camera_controller = CameraController::makeInstance();
	PidController *pid_controller = PidController::makeInstance();

	motor_controller->moveForward();

	while (true) {
		try {
			int sumC = camera_controller->update(CameraController::CENTER_ROW);
			double pid_val = pid_controller->getPIDValue(sumC);
			motor_controller->arc(pid_val,forword);
			if (camera_controller->n_whites>3000){
				forword=1;
			}
		} catch (int e){
			if (e==1){ //if the robot losses the line
				if (IR_controller->inMaze()){
					break;
				}
				motor_controller->moveBackward();
				printf("the camera lost the line!!");
			} else if (e==2){
				forword = 0;
				motor_controller->moveBackward();
			}
		}
		printf("n_whites: %d\n", camera_controller->n_whites);

		//motor_controller->arc(camera_controller->getDir(), sumC);
		printf("**************************************\n");//debuging print
		//Sleep(0, 1e8);
	}
	//This is for when the robot is in the Maze phase
	while(true){
		printf("Intense maze solving happening");
	}
	motor_controller->stopMovement();
	printf("Program Ended\n");

	return  0;
}
