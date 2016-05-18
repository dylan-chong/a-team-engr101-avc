#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int read_analog(int ch_adc);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

///Setting whole bunch of default values

float leftThreshold = 0;
float rightThreshold = 0;
float middleThreshold = 0;
bool thresholdSet = false;

double lastLeftDistance = 0;
double lastRightDistance = 0;
double lastMiddleDIstance = 0;


// The controller using a MotorController will access
// this variable. The MotorController itself doesn't use it
const float PERPENDICULAR_TURN_TIME = 1.2345; // DANIEL calibrate this

const int FORWARD_SPEED = 30;
const int BACKWARD_SPEED = -20;
const int ROTATE_SPEED = 30; // should always be positive

// NOTE: dont put any sleeps in any of these methods


// just set the motors to full forward
void moveForward() {
    // OLD motor speeds - most updated ones in MotorController.h
    set_motor(2, 200);//FORWARD_SPEED); //right motor
    set_motor(1, 230);//FORWARD_SPEED); //left motor
}

void moveBackward() {
    set_motor(2, BACKWARD_SPEED); //made reversing slower for higher accuracy in path correction
    set_motor(1, BACKWARD_SPEED);
}

void stopMovement() {
    set_motor(2, 0);
    set_motor(1, 0);
}

// turn left on the spot
void rotateLeft() {
    set_motor(2, -ROTATE_SPEED);
    set_motor(1, ROTATE_SPEED);
}

// turn right on the spot
void rotateRight() {
    set_motor(2, ROTATE_SPEED);
    set_motor(1, -ROTATE_SPEED);
}

// when percent is 1.0 don't actually turn
// when percent is -1.0 turn left on the spot
// DANIEL maybe instead make 0 move straight
// and 1.0 turn on the spot - whatever makes most sense
// then edit this description
void arcLeft(double percent) {
    // set right to full speed;
    // set left full speed * percent or whatever
}

void arcRight(double percent) {
    // similar thing as arcLeft
}

float getDistanceFromSensor(int sensorPin) {

	// Jonah do your calculation here then
	//Formula distance = Voltage/samples http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
	// 26 = range , 26/1024*reading

	int pinReading = read_analog(sensorPin);

	float multiplier = (float) (26.0 / 1024.0);
	float distance = multiplier * (1024 - pinReading) - 9; //4 is the offset as readings are in the range of 4-30 cm

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

void setThreshold(float left, float right) {
	leftThreshold = left;
	rightThreshold = right;
	//middleThreshold = middle;
}

double * update() {
	if (!thresholdSet) {
		setThreshold(15, 15); //TEMPORARILY SETTING THRESHOLD TO 0, change this when connecting to the controller
		thresholdSet = true;
	} else {
		if (getLeftDistance() > leftThreshold) {
			lastLeftDistance = -1;
		} else {
			lastLeftDistance = 1;
		}
		if (getRightDistance() > rightThreshold) {
			lastRightDistance = -1;
		} else {
			lastRightDistance = 1;
		}
//		if (getMiddleDistance() > middleThreshold) {
//			lastMiddleDistance = -1;
//		} else {
//			lastMiddleDistance = 1;
//		}
		printf("%f",getRightDistance());
	}
	double returnPackage[2];
	returnPackage[0]=getLeftDistance();
	returnPackage[1]=getRightDistance();
	return returnPackage;
}

// This method is just for testing. Not for use in main project
int main() {
	init(0);

	while (true) {
		double * data;
		data= update();
		printf("%f",data[0]);
		printf("\n");
		printf("%f",data[1]);
		printf("\n");
	}


	return 0;
}
