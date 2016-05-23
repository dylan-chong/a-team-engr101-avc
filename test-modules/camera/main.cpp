// ****************** TEMPLATE STUFF ******************

/*
#include <stdio.h>
#include <time.h>


extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int Sleep(int sec, int usec);
*/

// long getLineValue2() {
//     long value = 0;

//     // Ben do your calculation stuff here

//     return value;
// }

// This method is just for testing your getLineValue() method.
// Not for use in main project
/* TODO LATER use this actual main method
int main() {

    // Ben, make a printf statement that will print out the result
    // of the getLineValue() method so that you can test if it's working

    return 0;
}*/

#include <stdio.h>
#include <time.h>
#include <limits.h>


extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

const double KP = 0.0001;//0.5; // TODO LATER adjust values (look at my photos)
const double KD = 0;//5.0;

const int IMG_WIDTH = 320; // TODO ASK ANDREW reference the camera module for constants?

int previousLineValue;

clock_t start = clock();

// ******************** COPY PASTED PID CODE ********************
// ******************** PRIVATE ********************

float getTimeDiff() { // in seconds
    float timeDiff = (float) clock()-start;
    start=clock();
    return timeDiff;
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

//******** new stuff that ben wrote*********

int getLineValue() {
    char c;
    //the first array getting the camera input
    int whiteness[320];
    //whether the number is white enough
    int white_thr = 127;
    // the second array to compare to (- on left, + on the right)
    int white_compare[320];
    // what should be the multiplied version of the two above arrays
    int white_final[320];
    //the sum of all the white final numbers added 
    int sum = 0;
    // a count of how many white spots have been counted( to check if we can still see the line)
    int n_whites = 0;
    // left motor vroom vroom
    int leftMotor = 0;
    // right motor also vroom vroom
    int rightMotor = 0;
    take_picture();
    for (int i = 0; i < 320; i++) {
        //Take picture with camera
        
        //get pixel "whiteness" from centre of image
        c = get_pixel(i, 120, 3);
        //printf("%d\n", c);
        if (c > white_thr) {
            // if its greater than the threshold, the number is a one, and therefore white, so count increases
            whiteness[i] = 1;
            n_whites++;
        }
        else {
            whiteness[i] = 0;
        }
        white_compare[i] = i - 160;
        white_final[i] = whiteness[i] * white_compare[i];
    }

    // what should be the sum of white final working
    for (int i = 0; i < 320; i++) {
        sum = sum + white_final[i];
    }
    // trying to make it so if it loses the line it reverses to try make it find it again
    if (n_whites == 0) {
        //printf("%d\n", sum);
        return sum;
    }
        // the 0.004 is just a random small number i took, change it if you want
    else {
        //printf("%d\n", sum);
        return sum;
    }
}

// NON PID
const int LINE_VALUE_BOUNDS = 10000;
// uses lineValue, not pid
void useLineValue(int lineValue) {
    // double d = lineValue;
    // if (lineValue < -LINE_VALUE_BOUNDS) d = -LINE_VALUE_BOUNDS;
    // if (lineValue > LINE_VALUE_BOUNDS) d = LINE_VALUE_BOUNDS;
    // arc(d/LINE_VALUE_BOUNDS);
    // printf("LV: %f", d);
}

// PID
const double PID_BOUNDS = 1.0;
void usePID(double pid) {
    double v = pid;
    printf("PID: %f\n", v);
    if (v < -PID_BOUNDS) v = -PID_BOUNDS;
    if (v > PID_BOUNDS) v = PID_BOUNDS;
    
    arc(v/PID_BOUNDS);
}

void printIntArray(int[] ) {

}

// ******************** TESTING ******************** //

int main() {
    init(0);
    int count = 0;

    while (count < 2000) {
        int lineValue = getLineValue();
        double pid = getPIDValue(lineValue);
        usePID(pid);

        count++;
    }
    return 0;
}

/*

#include <stdio.h>
#include <time.h>
#include <limits.h>


extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

int getLineValue() {
    char c;
    //the first array getting the camera input
    int whiteness[320];
    //whether the number is white enough
    int white_thr = 127;
    // the second array to compare to (- on left, + on the right)
    int white_compare[320];
    // what should be the multiplied version of the two above arrays
    int white_final[320];
    //the sum of all the white final numbers added 
    int sum = 0;
    // a count of how many white spots have been counted( to check if we can still see the line)
    int n_whites = 0;
    // left motor vroom vroom
    int leftMotor = 0;
    // right motor also vroom vroom
    int rightMotor = 0;
    float kp = 0.005;
    double proportional_signal =0;
    take_picture();
    for (int i = 0; i < 320; i++) {
        //Take picture with camera
        
        //get pixel "whiteness" from centre of image
        c = get_pixel(i, 120, 3);
        //printf("%d\n", c);
        if (c > white_thr) {
            // if its greater than the threshold, the number is a one, and therefore white, so count increases
            whiteness[i] = 1;
            n_whites++;
        }
        else {
            whiteness[i] = 0;
        }
        white_compare[i] = i - 160;
        white_final[i] = whiteness[i] * white_compare[i];
    }

    // what should be the sum of white final working
    for (int i = 0; i < 320; i++) {
        sum = sum + white_final[i];
    }
    proportional_signal = sum*kp
    printf("%d\n", sum);
    return proportional_signal;

}

int main() {
    init(0);
    int count = 0;
    int proportional_signal = 1;
    while (count < 2000) {
        proportional_signal = getLineValue();
    if (proportional_signal < 0) {

		
		rightMotor = (50 - (proportional_signal / (160)) * 175); 
		leftSpeed = (50 + (proportional_signal / (160)) * 175);
	}

	else if (proportional_signal > 0) { 

		
		rightMotor = (50 - (proportional_signal / (160)) * 175);
		leftMotor = (50 + (proportional_signal / (160)) * 175); 
	}

	else {

	
		leftMotor = 80;
		rightMotor = 80;
	}
        		
		printf("%d\n", leftMotor);
		printf("%d\n", rightMotor);

		set_motor(1, leftMotor);
		set_motor(2, rightMotor);
        count++;
    }
    return 0;
}





void printIntArray(int[] ) {

}
*/





