#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CameraController.h"
#include "NetworkController.h"
#include "MotorController.h"
#include "IRController.h"

#include "PidController.h"

extern "C" int init(int d_lev);
extern "C" int Sleep(int sec, int usec);

const float PERPENDICULAR_LEFT_TURN_TIME = 0.5;
const float PERPENDICULAR_RIGHT_TURN_TIME = 1.2345; // NOT NEEDED

int forward = 1;

void sleepMillis(int millis) {
    for (int a = 0; a < millis; a++) {
        Sleep(0, 1000);
    }
}

int main() {
    init(0);
    //NetworkController *network_controller = NetworkController::makeInstance("192.168.1.2", 22);
    MotorController *motor_controller = MotorController::makeInstance();
    IRController *IR_controller = IRController::makeInstance();
    CameraController *camera_controller = CameraController::makeInstance();
    PidController *pid_controller = PidController::makeInstance();

    //network_controller->openGate();

    while (true) {
        try {
            int sumC = camera_controller->update(CameraController::CENTER_ROW); //gets the linevalue
            double pid_val = pid_controller->getPIDValue(sumC); //turns the line value in a PID value
            motor_controller->arc(pid_val, forward*0.70); //sets what the motor should do from the pid value

            if (camera_controller->n_whites > 50) { //if the robot gets back to a T intersection
                forward = 1;
            }
        } catch (int e) {
            if (e == 1) { //if the robot losses the line
                printf("*** E: lost line ***");
                if (IR_controller->inMaze()) {
                    break;
                }
                forward = -1;
            } else if (e == 2) {//if robot almost loses line
                forward = -1;
                printf("*** E: almost lost line ***");
            } else if (e == 3) { // perpendicular turn on left
                printf("*** E: line on left ***");
                motor_controller->arc(-1.0, 1);
                sleepMillis(1000 * PERPENDICULAR_LEFT_TURN_TIME * 0.9);
                motor_controller->stopMovement();
            }

            // tODO handle 3,4 errors
        }
        printf("**************************************\n");//debuging print
    }

    printf("\n\n\n************ NOW IN THE MAZE ************\n\n\n");

    //This is for when the robot is in the Maze phase
    while (true) {
        printf("Intense maze solving happening");
    }
    motor_controller->stopMovement();
    printf("Program Ended\n");

    return 0;
}