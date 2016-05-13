#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int usec);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

const float KP = 0.5;
const float KD = 5.0;

int IMG_WIDTH = 320;

// Don't need this.
//int getPixelGreyscale(int x, int y) {
//    return get_pixel(x, y, 3);
//}

// Use the value from the camera module, eventually
int getLineValue() {

}

// Refactored code from wiki

int getProportional(int row, int lineValue) {
    int proportional_signal = lineValue * kp;
    set_motor(1, (proportional_signal / (160 * 1 * kp)) * 255);

    printf("Proportional signal is: %d\n", proportional_signal);
}

// refreshPeriod is in seconds
int getDerivative(int row, int lineValue, int previous_error, float refreshPeriod) {

//    Sleep(0, (int) refreshPeriod * 1e6); // needs to be a sleep function in here to allow for time
    int derivative_signal = (lineValue - previous_error / refreshPeriod) * kd; // add brackets around (current_error - previous_error) ?
    printf("Derivative signal is: %d\n", derivative_signal);

    set_motor(1, derivative_signal);
}

// Integral apparently not necessary for AVC according to wiki
int getIntegral() { return 0;}

//

int main() {
    // currently just for testing the sleep functions
    printf("test\n");
    sleep(1, 0);
    printf("test 2\n");
    Sleep(1, 0);
    printf("test 3\n");

    return 0;
}