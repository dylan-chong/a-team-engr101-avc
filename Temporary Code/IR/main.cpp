#include <stdio.h>
#include <time.h>

extern "C" int init_hardware();
extern "C" int read_analog(int ch_adc);
extern "C" int sleep(int sec, int  usec);

int main(){


    // TODO get some readings from the IR sensors to make sure its working

    printf("Done");
    return 0;
}

int getDistance() {
    int distance = 0;

    // TODO

    return distance;
}