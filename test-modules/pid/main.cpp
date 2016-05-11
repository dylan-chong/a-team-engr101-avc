#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

int main() {
    printf("test\n");
    sleep(1, 0);
    printf("end\n");
    return 0;
}

// Copy pasted from wiki (slightly modified for readability)
/*
int proportional() {

}

int integral() {

}

int derivative() {
    int current_error = 0;
    int kd = 5.0;


    for (int i = 0; i < 320; i++) {
        error = (i - 160) * get_pixel(i, 120, 3);
        current_error = current_error + error;
    }

    Sleep(0, 100000);
    int derivative_signal = (current_error - previous_error / 0.1) * kd;
    int previous_error = current_error;
    printf("Derivative signal is: %d", derivative_signal);
    set_motor(1, derivative_signal);
}
 */