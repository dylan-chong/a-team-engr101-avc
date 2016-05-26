#include <stdio.h>

// NOTE: This file is only pseudo code for 
// jotting down the jist of things. Syntax is a bit un-C.

// ****************************** Main Class ************************************

char * run() {

	// do network stuff

	// Andrew figure out if we should return errors in the run methods or not

	runLine();
	runMaze();
	runFinish();
}

private runLine() {
	// When the lineValue (in run()) is greater than PERPENDICULAR_THRESHOLD
	// there will be a perpendicular turn on the line. 
	const long PERPENDICULAR_THRESHOLD = 12345l; // Ben calibrate this

	// How fast the robot should arc to get back onto the line
	const float TURNING_SENSITIVITY = 0.123; // Unassigned

	while (true) {
		long lineValue = CameraController.getLineValue();

		// if the line ends it is a dead end
		// but if there are walls on either side of the robot
		//	then it is the end of the maze

		// NOTE: make it easy to change between the follow left or right algorithm

		// DYLAN PLANS for tracking the line
		long lineVA = CameraController.getLineValueForRow(120-20);
		long lineVB = CameraController.getLineValueForRow(120+20);
		if (lineVA < PERPENDICULAR_THRESHOLD) continue; // just ignoring perpendicular turns
		if (lineVB < PERPENDICULAR_THRESHOLD) continue;
		
		if (lineVA < 0 && line VB < 0) {
			// robot to the right of line

		} else if (lineVA > 0 && line VB > 0) {
			// robot to the left of line


		} else if (lineVA < 0 && line VB > 0) {
			// robot should turn left

		} else if (lineVA > 0 && line VB < 0) {
			// robot should turn left

		}

		// TODO LATER
	}
}


private runMaze() {
	MazeController *mazeController = ...;
	while (true) {
		float leftDistance = IR.getLeftDistance();
		float middleDistance = IR.getMiddleDistance();
		float rightDistance = IR.getRightDistance();

		MazeAction action = 
			mazeController.getNextAction(leftDistance, middleDistance, rightDistance);
	}
}

private runFinish() {
	// spin on the spot - "woo sounds!!"
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
	public void rotateLeft() {

	}

	// turn right on the spot
	public void rotateRight() {

	}

	// direction between -1 (full left)
	// and 1 (full right)
	public void arc(double direction) {

	}
 
 };

class NetworkController {
	public char * run(MotorController *motorController) {
		// do network stuff and 
		// return error msg or NULL
		return NULL;
	}
};

class CameraController {

	// run the algorithm on the left half of the image later?

	public long getLineValue() {
		// Ben does this with Elf's algorithm or whatever it is
	}

	// NOTE Ignore the possibility of having light on the edges of the picture
	// we can give the camera a shadow to work within or hope we don't have the problem
	// in the first place.

};

class MazeController {

	public typedef enum {
		GO_STRAIGHT,
		TURN_LEFT,
		TURN_RIGHT,
		FINISH
	} MazeAction;

	public char * run(MotorController *motorController) {
		while (true) {
			

		}

		return "An impossible error occurred";
	}

	private MazeAction getNextAction(float leftDistance, 
		float middleDistance, float rightDistance) {
		// whoever is on tracking can fill in this method for maze logic
	}
};

class IRController {

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

class PIDController {

	// return between -1 and 1
	public double getPIDValue() {
		// use other get methods
	}

	private int getDerivativeValue() {

	}

	private int getProportionalValue() {

	}

	// probably don't need integral
};