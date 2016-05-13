#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int read_analog(int ch_adc);
extern "C" int sleep(int sec, int  usec);

// Return the distance in centimetres



float getDistanceFromSensor(int sensorPin) {

    // Jonah do your calculation here then

	//Formula distance = Voltage/samples http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/


	// 26 = range , 26/1024*reading

	int pinReading = read_analog(sensorPin);

	printf("%d\n",pinReading);

	float multiplier = (float)(26.0/1024.0);
	float distance = multiplier*(1024-pinReading)+4; //4 is the offset as readings are in the range of 4-30 cm
							 //1024 - pinReading as it inverts the value
	printf("%f\n",multiplier);


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
	init(0);

	while(true){
		printf("%f", getLeftDistance());
		printf("CM\n");
		sleep(1,0);
	}
    // Jonah write code here so you can test it

    return 0;
}
