#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_TURN_TIME = 1.2345; // DANIEL calibrate this


// NOTE: dont put any sleeps in any of these methods


// just set the motors to full forward
void moveForward() {

}

// turn left on the spot
void rotateLeft() {

}

// turn right on the spot
void rotateRight() {

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