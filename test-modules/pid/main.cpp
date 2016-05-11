#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

int main() {
    printf("test\n");
    Sleep(1,0);
    printf("end\n");
    return 0;
}