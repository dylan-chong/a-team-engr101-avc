#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int usec);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

const float KP = 0;//0.5; // TODO LATER adjust values (look at my photos)
const float KD = 0;//5.0;

const int IMG_WIDTH = 320; // TODO ASK ANDREW reference the camera module for constants?

// TODO NEXT last line value and last time

// ******************** PUBLIC ********************

/* PUBLIC */ int getPIDValue() {
    // Algorithm for calculating PID was taken from the Kaiwhata wiki
    // https://github.com/kaiwhata/ENGR101-2016/wiki/PID-(Proportional-Integral-Derivative)-Control
    // TODO sum P and D
}


// ******************** PRIVATE ********************

// TODO get the value from the camera module
// For testing, inject fake values
int getLineValue() {
    return 1234;
}

int getProportional(int lineValue) {
    int proportional_signal = lineValue * KP;
    // int motorVal = proportional_signal / (IMG_WIDTH / 2) * 255; // do we even need this?
    return proportional_signal;

}

int getDerivative(int lineValue) {
    int derivative_signal = (lineValue - previousLineValue / refreshPeriod) * KD;
    return derivative_signal;
}

// Integral apparently not necessary for AVC according to wiki
// int getIntegral() { return 0;}


// ******************** TESTING ONLY ********************
//                  not for main project

int main() {

    printf("\nTEST SLEEP\n\n"); // TODO currently just for testing the sleep functions

    printf("test\n");
    sleep(1, 0);
    printf("test 2\n");
    Sleep(1, 0);
    printf("test 3\n");

    printf("\nENDING PROGRAM\n");
    return 0;

    // TODO once done testing sleep, remove wrong import at top

    // ------------------------

    printf("\nTEST BEDMAS\n\n"); // TODO test order of operations

    float a = (4 - 2 / 3);
    float b = ((4 - 2) / 3);
    printf("\ta = %f,\n\tb = %f\n", a, b);

    printf("\nENDING PROGRAM\n");
    return 0;

    // ------------------------



    printf("\nENDING PROGRAM\n");
    return 0;
}