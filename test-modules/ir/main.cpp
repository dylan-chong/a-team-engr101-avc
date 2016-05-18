#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int read_analog(int ch_adc);
extern "C" int sleep(int sec, int  usec);

///Setting whole bunch of default values

float leftThreshold=0;
float rightThreshold=0;
float middleThreshold=0;
bool thresholdSet=false;

double lastLeftDistance=0;
double lastRightDistance=0;
double lastMiddleDIstance=0;

float getDistanceFromSensor(int sensorPin) {

    // Jonah do your calculation here then
	//Formula distance = Voltage/samples http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
	// 26 = range , 26/1024*reading

	int pinReading = read_analog(sensorPin);

	float multiplier = (float)(26.0/1024.0);
	float distance = multiplier*(1024-pinReading)-9; //4 is the offset as readings are in the range of 4-30 cm
	
	return distance;
}

float getLeftDistance() {
    return getDistanceFromSensor(0); // use actual pin number later
}

float getMiddleDistance() {
    return getDistanceFromSensor(1); // use actual pin number later
}

float getRightDistance() {
    return getDistanceFromSensor(2); // use actual pin number later
}

void setThreshold(float left,float right,float middle){
	leftThreshold=left;
	rightThreshold=right;
	middleThreshold=middle;
}

double update(){
	if(!thresholdSet){
		setThreshold(0f,0f,0f); //TEMPORARILY SETTING THRESHOLD TO 0, change this when connecting to the controller
		thresholdSet=true;
	} else{
					
	}		
}

// This method is just for testing. Not for use in main project
int main(){
	init(0);
	while(true){
		if(!thresholdSet){
			setThreshold(getLeftDistance(),getRightDistance(),getMiddleDistance());	
			thresholdSet=true;
		} else{ //If thresholds are set return 1 if the object is further away and -1 if it is closer
			if(getLeftDistance()>leftThreshold){
				lastLeftDistance=-1;	
			} else {
				lastLeftDistance=1;
			} if(getRightDistance()>rightThreshold){
				lasrRightDistance=-1;
			} else{
				lastRightDistance=1;
			} if(getMiddleDistance()>middleThreshold){
				lastMiddleDistance=-1;
			} else{
				lastMiddleDistance=1;
			}		
		}
		
		
		printf("%f", getLeftDistance());
		printf("CM - Left\n");
		printf("%f", getRightDistance());
		printf("CM - Right\n");
		sleep(1,0);
	}
    // Jonah write code here so you can test it

    return 0;
}
