#include <stdio.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"
#include "PidController.h"

#include <stdlib.h>

extern "C" int init(int d_lev);
extern "C" int Sleep(int sec, int usec);

int forward = 1;

void sleepMillis(int millis) {
    for (int a = 0; a < millis; a++) {
        Sleep(0, 1000);
    }
}

int main() {
    init(1);
    NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2", 22);
    MotorController *motor_controller = MotorController::makeInstance();
    IRController *IR_controller = IRController::makeInstance();
    CameraController *camera_controller = CameraController::makeInstance();
    PidController *pid_controller = PidController::makeInstance();

    network_controller->openGate();

    while (true) {
        try {
            int sumC = camera_controller->update(CameraController::CENTER_ROW);
            double pid_val = pid_controller->getPIDValue(sumC);
            motor_controller->arc(pid_val, forward);
            if (camera_controller->n_whites > 3000) {
                forward = 1;
            }
        } catch (int e) {
            if (e == 1) { //if the robot losses the line
                if (IR_controller->inMaze()) {
                    break;
                }
                forward = -1;
            } else if (e == 2) {//if robot almost loses line
                forward = -1;
            }
        }
        printf("**************************************\n");//debuging print
    }


    //This is for when the robot is in the Maze phase
    while (true) {
        printf("Intense maze solving happening");
    }
    motor_controller->stopMovement();
    printf("Program Ended\n");

    return 0;
}
