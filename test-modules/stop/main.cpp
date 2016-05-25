#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

void sleepMillis(int millis) {
    for (int a = 0; a < millis; a++) {
        Sleep(0, 1000);
    }
}

int main() {
    init(0);

    set_motor(1, 255);
    set_motor(2, 255);
    sleepMillis(400);

    set_motor(1, 0);
    set_motor(2, 0);
    sleepMillis(400);

    return 0;
}
