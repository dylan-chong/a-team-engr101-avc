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

    NetworkController *network_controller = NetworkController::makeInstance("130.195.6.196", 1024);
    MotorController *motor_controller = MotorController::makeInstance();
    IRController *IR_controller = IRController::makeInstance();
    CameraController *camera_controller = CameraController::makeInstance();
    PidController *pid_controller = PidController::makeInstance();

    motor_controller->stopMovement();

    //network_controller->openGate();
    motor_controller->moveForward();

    while (true) {
        try {
            int sumC = camera_controller->update(CameraController::LAST_ROW_TO_CHECK); //gets the linevalue
            //printf("SUM: %d\n", sumC);
            double pid_val = pid_controller->getPIDValue(sumC); //turns the line value in a PID value

            motor_controller->arc(pid_val, forward*0.70); //sets what the motor should do from the pid value

            if (camera_controller->n_whites > 50) { //if the robot gets back to a T intersection
                forward = 1;
            }
        } catch (int e) {
            if (e == 1) { //if the robot losses the line
                printf("*** E: lost line ***");
                motor_controller->rotateRight();
                //forward = -1;
            } else if (e == 3) { // perpendicular turn on left
                printf("*** E: line on left ***");
                motor_controller->arc(-1.0, 1*.9);
                Sleep(0,1000); //only needs it on the left side as it turns right when the line is lost
            } else if (e == 4){//center
            	motor_controller->arc(0, 1*.9);
            } else if (e == 5) {//right
            	printf("*** E: line on right ***");
            	motor_controller->arc(1, 1*.9);
            } else if (e == 6) { // is in maze
            	break;
            }
        }
        printf("**************************************\n");//debuging print
    }

    printf("\n\n\n************ NOW IN THE MAZE ************\n\n\n");

    //This is for when the robot is in the Maze phase
    while (true) {
        int sum = IR_controller->getSum();
        double pid_val = pid_controller->getPIDValue(sum);
        motor_controller->arc(pid_val, forward * 0.70);
        //printf("Intense maze solving happening");
    }
    motor_controller->stopMovement();
    printf("Program Ended\n");

    return 0;
}
