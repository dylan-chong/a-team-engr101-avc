#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

// ******************** PRIVATE IMPLEMENTATION ******************** //

// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_LEFT_TURN_TIME = 1.2345; // DANIEL calibrate this
const float PERPENDICULAR_RIGHT_TURN_TIME = 1.2345; // DANIEL calibrate this

// NOTE: don't put any sleeps in any of these methods

// Refer to even-speeds.txt for nicer formatting of data
const int NUMBER_OF_REVERSE_SPEEDS = 9;
const int RIGHT_SPEEDS[21] = {
        200, 150, 105, 80, 65, 41, 30, 20, 10, // reverse
        0, // definitely stop
        -10, -20, -30, -41, -60, -70, -88, -95, -180, -200, -255 // forward
};

const int LEFT_MAX = 9;
const int LEFT_MIN = -8;
const int RIGHT_MAX = 8;
const int RIGHT_MIN = -7;

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

void freezeIfDirectionOutOfRange(double direction) {
    if (direction > 1 || direction < -1) {
        set_motor(2, 0);
        set_motor(1, 0);
        while (true) {
            printf("Your direction %f is not between -1 and 1", direction);
        }
    }
}

// ******************** PUBLIC METHODS ******************** //

// just set the motors to full forward
void moveForward() {
    moveStraightAtSpeed(8);
}

void moveBackward() {
    moveStraightAtSpeed(-6);
}

void stopMovement() {
    setLeft(0);
    setRight(0);
}

// turn left on the spot
// right wheel doesn't seem to do anything
void rotateLeft() {
    setLeft(LEFT_MIN);
    setRight(RIGHT_MAX);
}

// turn right on the spot
void rotateRight() {
    setLeft(LEFT_MAX);
    setRight(RIGHT_MIN);
}

// -1 is max left
// 0 is max forward
// 1 is max right

void arc(double direction) {
    if (direction < 0) {
        setLeft((int)((LEFT_MAX - LEFT_MIN) * direction + LEFT_MAX));
        setRight(RIGHT_MAX);
    } else if (direction > 0) {
        setLeft(LEFT_MAX);
        setRight((int)((RIGHT_MIN - RIGHT_MAX) * direction + RIGHT_MAX));
    } else if (direction == 0) {
        moveForward();
    }
}

// ******************** TESTING ONLY ******************** //

int main() {
    init(0);

    arc(-1);
    sleep(3, 0);
    arc(1);
    sleep(3, 0);

    stopMovement();
    sleep(1, 0);

    return 0;
}