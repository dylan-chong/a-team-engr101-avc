#include <stdio.h>
#include <time.h>

extern "C" int init_hardware();
extern "C" int read_analog(int ch_adc);
extern "C" int sleep(int sec, int  usec);

// Return the distance in centimetres
float getDistanceFromSensor(int sensorPin) {

    // Jonah do your calculation here then
	
	//Formula distance = Voltage/samples http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
	float volts = analogRead(IRpin)*0.0048828125; ;
	float distance = 65*pow(volts, -1.10);
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

// This method is just for testing. Not for use in main project
int main(){

    // Jonah write code here so you can test it

    return 0;
}