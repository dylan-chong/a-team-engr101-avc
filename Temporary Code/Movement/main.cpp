#include  <stdio.h>
#include  <time.h>

extern "C" int init_hardware();
extern "C" int sleep(int sec, int  usec);
extern "C" int set_motor(int motor, int speed);

int main(){
	init_hardware();

	//sets motors on pin one and 2 to 100% speed one way for 5 seconds
	setMotor(1, 255);
	setMotor(2, 255);
	sleep(5, 0);

	setMotor(1, 0);
	setMotor(2, 0);

	return 0;
}
