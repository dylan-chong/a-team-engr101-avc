#include  <stdio.h>
#include  <time.h>

extern "C" int init(int x);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_TURN_TIME = 1.2345; // DANIEL calibrate this

const int FORWARD_SPEED = 30;
const int BACKWARD_SPEED = -20;
const int ROTATE_SPEED = 30; // should always be positive



int main() {
    init(0);

    set_motor(1,0);
    set_motor(2,0);

    return 0;
}
