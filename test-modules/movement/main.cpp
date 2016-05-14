#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_TURN_TIME = 1.2345; // DANIEL calibrate this

const int FORWARD_SPEED = 30;
const int BACKWARD_SPEED = -20;
const int ROTATE_SPEED = 30; // should always be positive

// NOTE: dont put any sleeps in any of these methods


// just set the motors to full forward
void moveForward() {
    set_motor(2, FORWARD_SPEED); //right motor
    set_motor(1, FORWARD_SPEED); //left motor
}

void moveBackward() {
    set_motor(2, BACKWARD_SPEED); //made reversing slower for higher accuracy in path correction
    set_motor(1, BACKWARD_SPEED);
}

void stopMovement() {
    set_motor(2, 0);
    set_motor(1, 0);
}

// turn left on the spot
void rotateLeft() {
    set_motor(2, -ROTATE_SPEED);
    set_motor(1, ROTATE_SPEED);
}

// turn right on the spot
void rotateRight() {
    set_motor(2, ROTATE_SPEED);
    set_motor(1, -ROTATE_SPEED);
}

// when percent is 1.0 don't actually turn
// when percent is -1.0 turn left on the spot
// DANIEL maybe instead make 0 move straight
// and 1.0 turn on the spot - whatever makes most sense
// then edit this description
void arcLeft(double percent) {
    // set right to full speed;
    // set left full speed * percent or whatever
}

void arcRight(double percent) {
    // similar thing as arcLeft
}







/*
// Daniels old code for moving in a straight line
int main() {
    init_hardware();

    set_motor(1, 127); //sets motors on pin one and 2 to 50% speed for 5 seconds
    set_motor(2, 127);
    sleep(5, 0);

    set_motor(1, 0);
    set_motor(2, 0);

    return 0;
}*/
