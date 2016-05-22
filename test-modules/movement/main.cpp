#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

// ******************** PRIVATE IMPLEMENTATION ******************** //

// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_TURN_TIME = 1.2345; // DANIEL calibrate this

// NOTE: don't put any sleeps in any of these methods

// Refer to even-speeds.txt for nicer formatting of data
const int NUMBER_OF_REVERSE_SPEEDS = 9;
const int RIGHT_SPEEDS[21] = {
        200, 150, 105, 80, 65, 41, 30, 20, 10, // reverse
        0, // definitely stop
        -10, -20, -30, -41, -60, -70, -88, -95, -180, -200, -255 // forward
};

void freezeIfSpeedOutOfRange(int speed) {
    if (speed < -NUMBER_OF_REVERSE_SPEEDS || speed > 11) {
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
    set_motor(1, RIGHT_SPEEDS[speed + NUMBER_OF_REVERSE_SPEEDS]);
}

void moveStraightAtSpeed(int speed) {
    setLeft(speed);
    setRight(speed);
}

// ******************** PUBLIC METHODS ******************** //

// just set the motors to full forward
void moveForward() {
    moveStraightAtSpeed(5);
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
// right wheel doesn't seem to do anything
void rotateLeft() {
    setLeft(-8);
    setRight(8);
}

// turn right on the spot
void rotateRight() {
    setLeft(9);
    setRight(-7);
}

// -1 is max left
// 0 is max forward
// 1 is max right
void arc(double direction) {
    if (direction <= 0) setLeft((1 + direction) * -8);
    else setLeft(5);
    if (direction >= 0) setRight((1 - direction) * 7);
    else setRight(5);
}

// ******************** TESTING ONLY ******************** //

int main() {
    init(0);

    // todo test rotateRight
    // todo test arc (-1, 0, 1)

    arc(-1);
    sleep(3, 0);
    arc(1);
    sleep(3, 0);

    stopMovement();
    sleep(1, 0);

    return 0;
}