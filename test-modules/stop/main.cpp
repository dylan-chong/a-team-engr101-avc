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

    while (true) {
        set_motor(1, 5);
        set_motor(2, 5);
        sleepMillis(5000);
    }

    return 0;
}
