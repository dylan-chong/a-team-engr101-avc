#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

const float KP = 0;//0.5; // TODO LATER adjust values (look at my photos)
const float KD = 0;//5.0;

const int IMG_WIDTH = 320; // TODO ASK ANDREW reference the camera module for constants?

int previousLineValue;

clock_t lastClock = clock();

// ******************** PRIVATE ********************

double getTimeDiff() { // in seconds
    clock_t newClock = clock();
    printf("CLOCK %f", (double) newClock);

    double timeDiff = (double) (newClock-lastClock);
    
    printf("TIMEDIFF %f", timeDiff);
    lastClock = newClock;
    return timeDiff / CLOCKS_PER_SEC;
}

double getProportional(int lineValue) {
    double proportional_signal = lineValue * KP;
    // int motorVal = proportional_signal / (IMG_WIDTH / 2) * 255; // do we even need this?
    return proportional_signal;
}

double getDerivative(int lineValue, double timeDiff, int prevLineValue) {
    double derivative_signal = (lineValue - prevLineValue / timeDiff) * KD;
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

    double timeDiff = getTimeDiff();

    double proportional = getProportional(lineValue);
    double derivative = getDerivative(lineValue, timeDiff, previousLineValue);

    double pid = proportional + derivative;

    // TODO find maximum and minimum pid values and scale
    // pid to fit between -1 and 1 (maybe don't use the actual
    // maximums and minimums, try pick some values through 
    // experimentation)

    previousLineValue = lineValue;

    return pid;
}

// ******************** TESTING ONLY ********************
//                  not for main project

int main() {
    init(0);

    printf("\nENDING PROGRAM\n");
    return 0;
}
