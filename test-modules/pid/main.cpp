#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int usec);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

const float KP = 0.5;
const float KD = 5.0;

int IMG_WIDTH = 320; // TODO LATER reference the camera module for constants?

// Don't need this.
//int getPixelGreyscale(int x, int y) {
//    return get_pixel(x, y, 3);
//}

// TODO Use the value from the camera module
// For testing, inject fake values
int getLineValue() {
    return 1234; // TODO change
}

// Very refactored code from wiki

int getProportional(int row, int lineValue) {
    int proportional_signal = lineValue * kp;
    int motorVal = (proportional_signal / ((IMG_WIDTH / 2) * 1 * KP)) * 255;
    set_motor(1, motorVal);

    printf("Proportional signal is: %d\n", proportional_signal);
}

// refreshPeriod is in seconds
int getDerivative(int row, int lineValue, int previousLineValue, float refreshPeriod) {

    int derivative_signal = (lineValue - previousLineValue / refreshPeriod) * KD; // add brackets around (current_error - previous_error) ?

    printf("Derivative signal is: %d\n", derivative_signal);

    set_motor(1, derivative_signal);
}

// Integral apparently not necessary for AVC according to wiki
int getIntegral() { return 0;}

// TODO use the put everything together formula

//

int main() {

    printf("\nTEST SLEEP\n\n");

    // TODO currently just for testing the sleep functions
    printf("test\n");
    sleep(1, 0);
    printf("test 2\n");
    Sleep(1, 0);
    printf("test 3\n");

    printf("\nTEST BEDMAS\n\n");

    // TODO test order of operations
    float a = (4 - 2 / 3);
    float b = ((4 - 2) / 3);
    printf("\ta = %f,\n\tb = %f\n", a, b);

    return 0;
}