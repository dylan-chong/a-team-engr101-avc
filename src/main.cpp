#include  <stdio.h>
#include  <time.h>
#include  "NetworkController.h"

extern "C" int  InitHardware();
extern "C" int  Sleep(int sec, int  usec);

int main(){
	InitHardware();
	NetworkController *network_controller = (NetworkController *)NetworkController::getInstance();
	printf("it worked");
	return  0;
}
