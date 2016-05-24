#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

int main() {
    init(0);

    set_motor(1,0);
    set_motor(2,0);

    Sleep(1,0);

    return 0;
}
