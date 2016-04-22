#include  <stdio.h>
#include  <time.h>

extern "C" int  init_hardware();
extern "C" int  sleep(int sec, int  usec);
extern "C" int  set_motor(int motor, int speed);

int  main(){
init_hardware();

set_motor(1, 127); //sets motors on pin one and 2 to 50% speed for 5 seconds
set_motor(2, 127);
sleep(5,0);

set_motor(1, 0);
set_motor(2, 0);

return  0;}