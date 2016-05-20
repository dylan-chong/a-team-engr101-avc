#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

// ******************** PRIVATE IMPLEMENTATION ******************** //

// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_TURN_TIME = 1.2345; // DANIEL calibrate this

// NOTE: dont put any sleeps in any of these methods


// Refer to even-speeds.txt for nicer formatting of data
const int RIGHT_SPEEDS[18] = {
        65, 41, 30, 20, 10, // reverse
        0, // definitely stop
        -10, -20, -30, -41, -60, -70, -88, -95, -180, -200, -255 // forward
};

void freezeIfSpeedOutOfRange(int speed) {
    if (speed < -5 || speed > 11) {
        set_motor(2, 0);
        set_motor(1, 0);
        while (true) {
            printf("You speed (%d) is not between -5 and 11\n", speed);
        }
    }
}

// Both setLeft and setRight take values between
// -5 and 11 inclusive
// setting both to -3 to 2 inclusive means the robot wont move
void setLeft(int speed) {
    freezeIfSpeedOutOfRange(speed);
    set_motor(2, speed * 10);
}

void setRight(int speed) {
    freezeIfSpeedOutOfRange(speed);
    set_motor(1, RIGHT_SPEEDS[speed + 5]);
}

void moveStraightAtSpeed(int speed) {
    setLeft(speed);
    setRight(speed);
}

// ******************** PUBLIC METHODS ******************** //

// just set the motors to full forward
void moveForward() {
    setLeft(5);
    setRight(5);
}

void moveBackward() {
    setLeft(-5);
    setRight(-5);
}

void stopMovement() {
    setLeft(0);
    setRight(0);
}

// turn left on the spot
void rotateLeft() {
    setLeft(-5);
    setRight(5);
}

// turn right on the spot
void rotateRight() {
    setLeft(5);
    setRight(-5);
}

// -1 is max left
// 0 is max forward
// 1 is max right
void arc(double direction) {
    setLeft(5 * direction);
    setRight(-5 * direction);
}

// ******************** TESTING ONLY ******************** //

int main() {
    init(0);

    // todo test rotateLeft and right movement
    rotateLeft();
    sleep(3, 0);

    stopMovement();
    sleep(1, 0);

    return 0;
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
