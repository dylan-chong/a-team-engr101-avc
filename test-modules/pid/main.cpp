#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

const float KP = 0;//0.5; // TODO LATER adjust values (look at my photos)
const float KD = 0;//5.0;

const int IMG_WIDTH = 320; // TODO ASK ANDREW reference the camera module for constants?

int previousLineValue;

clock_t start = new clock();

// ******************** PRIVATE ********************

float getTimeDiff() { // in seconds
	float timeDiff = (float) clock()-start;
	start=clock();
    return timeDiff / CLOCKS_PER_SEC;
}

int getProportional(int lineValue) {
    int proportional_signal = lineValue * KP;
    // int motorVal = proportional_signal / (IMG_WIDTH / 2) * 255; // do we even need this?
    return proportional_signal;
}

int getDerivative(int lineValue, float timeDiff, int prevLineValue) {
    int derivative_signal = (lineValue - prevLineValue / (double) timeDiff) * KD;
    return derivative_signal;
}

// Integral apparently not necessary for AVC according to wiki
// int getIntegral() { return 0;}


// ******************** PUBLIC ********************

// Constructor needs no args or implementation

// Returns a value between -1 (full left) and 1 (full right)
double getPIDValue(int lineValue) {
    // Algorithm for calculating PID was taken from the Kaiwhata wiki
    // https://github.com/kaiwhata/ENGR101-2016/wiki/PID-(Proportional-Integral-Derivative)-Control

    int proportional = getProportional(lineValue);
    int derivative;

    float timeDiff = getTimeDiff();
    derivative = getDerivative(lineValue, timeDiff, previousLineValue);


    double pid = proportional + derivative;

    // TODO find maximum and minimum pid values and scale
    // pid to fit between -1 and 1 (maybe don't use the actual
    // maximums and minimums, try pick some values through 
    // experimentation)

    previousLineValue = lineValue;

    return pid;
}

// ******************** COPY PASTED MOTOR CODE ******************** //
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

// ******************** TESTING ONLY ********************
//                  not for main project

int main() {
    init(0);

    printf("\nENDING PROGRAM\n");
    return 0;
}
