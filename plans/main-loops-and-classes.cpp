#include <stdio.h>

// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS

// NOTE: This file is only pseudo code for 
// jotting down the jist of things. Syntax is a bit un-C.

// ****************************** Main Class ************************************

char * run() {

	// Andrew figure this crap out
}

int main() {

	printf("\n\nRunning\n\n");

	char error[] = run();
	if (error) {
		printf("\n\nError during %s\n\n", error);
	}

	printf("\n\nFinished\n\n")

	return 0;
}

// ****************************** Other Classes ******************************

// NOTE: the funny syntax means put this method inside the NetworkControler class
// 		 the same applies to all the other class below

class MotorController {
	// Daniel implements

	// The controller using a MotorController will access
	// this variable. The MotorController itself doesn't use it
	float PERPENDICULAR_TURN_TIME = 1.2345; // Daniel calibrate this

	// dont put any sleeps in any of these methods

	// just set the motors to full forward
	public void moveForward() {

	}

	// turn left on the spot
	public void rotateLeft90() {

	}

	// turn right on the spot
	public void rotateRight90() {

	}

	// when percent is 1 don't actually turn
	// when percent is -1 turn left on the spot
	public void arcLeft(double percent) {
		right = full speed;
		left = full speed * percent;
	}

	public void arcRight(double percent) {
		// similar thing as arcLeft
	}
 
 };

class NetworkController {
	public char * run(MotorController *motorController) {
		// do network stuff and 
		// return error msg or NULL
		return NULL;
	}
};

class LineController {

	// TODO DISCUSS how will we distinguish between there being no line in sight
	// of the camera and the line being exactly in the centre

	// When the lineValue (in run()) is greater than PERPENDICULAR_THRESHOLD
	// there will be a perpendicular turn on the line. 
	const long PERPENDICULAR_THRESHOLD = 12345l; // Ben calibrate this

	// How fast the robot should arc to get back onto the line
	const float TURNING_SENSITIVITY = 0.123; // Unassigned

	public char * run(MotorController *motorController) {

		while (true) {
			long lineValue = Camera.getLineValue(); 

			// if the line ends it is a dead end
			// but if there are walls on either side of the robot
			//	then it is the end of the maze

			// NOTE: make it easy to change between the follow left or right algorithm
		}

		return "An impossible error occurred";
	}
};

class Camera {

	// run the algorithm on the left half of the image
	public long getLineValue() {
		// Ben does this with Elf's algorithm or whatever it is
	}

	// NOTE Ignore the possibility of having light on the edges of the picture
	// we can give the camera a shadow to work within or hope we don't have the problem
	// in the first place.

};

class MazeController {

	typedef enum {
		GO_STRAIGHT,
		TURN_LEFT,
		TURN_RIGHT,
		FINISH
	} MazeAction;

	public char * run(MotorController *motorController) {
		while (true) {
			float leftDistance = IR.getLeftDistance();
			float middleDistance = IR.getMiddleDistance();
			float rightDistance = IR.getRightDistance();

			MazeAction action = 
				getNextAction(leftDistance, middleDistance, rightDistance);
				// getNextAction is part of MazeController

			// NOTE: make it easy to change between the follow left or right wall algorithm

			switch (action) { // tell movement to do stuff
				case GO_STRAIGHT:
					motorController.moveForward() // 10 cm // TODO DISCUSS m or cm?
					sleep();
					break;
				case TURN_LEFT:
					motorController.rotateLeft90(90); // degrees
					break;
				case TURN_RIGHT:
					motorController.rotateLeft90(90); // degrees
					break;
				case FINISH;
					motorController.stop();
					return NULL;
				default:
					motorController.ensureStop();
					return "No valid action";
			}
		}

		return "An impossible error occurred";
	}

	private MazeAction getNextAction(float leftDistance, 
		float middleDistance, float rightDistance) {
		// whoever is on tracking can fill in this method for maze logic
	}
};

class IR {

	// TODO DISCUSS in m or cm?

	public float getLeftDistance() {
		return getDistanceFromSensor(0); // use actual pin number later
	}

	public float getMiddleDistance() {
		return getDistanceFromSensor(1); // use actual pin number later
	}

	public float getRightDistance() {
		return getDistanceFromSensor(2); // use actual pin number later
	}

	private float getDistanceFromSensor(int sensorPin) {
		// Jonah does the calculation here
		return 12.345;
	}
};

// TODO DISCUSS Andrew's job can be to turn this pseudo code into actual c++ syntax
// in the main project. Dylan's job will be to move these methods into the module projects