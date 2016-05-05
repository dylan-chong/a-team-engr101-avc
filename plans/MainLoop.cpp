#include <stdio.h>

// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS

// NOTE: This file is only pseudo code for 
// jotting down the jist of things. Syntax is a bit un-C.


char * run() {
	{
		printf("\n\nStarting NetworkController\n");
		char error[] = NetworkController.getInstance().run();
		if (error) {
			return "Network State: " + error;
		}
		printf("NetworkController Succeeded\n");
	}
	{	
		printf("\n\nStarting LineController\n");
		char error[] = LineController.getInstance().run();
		if (error) {
			return "Line State: " + error;
		}
		printf("LineController Succeeded\n");
	}
	{
		printf("\n\nStarting MazeController\n");
		char error[] = MazeController.getInstance().run();
		if (error) {
			return "Maze State: " + error;
		}
		printf("MazeController Succeeded\n");
	}
	{
		printf("Starting Finished Part\n");
		// spin around in circles, 
		// after passing the finish line
		// or don't get too cocky and just stay still
		printf("Finished Part Succeeded\n");
	}

	return NULL;
}

int main() {

	char error[] = run();
	if (error) {
		printf("\n\nError during %s\n\n", error);
	}

	printf("%s\n", "Done");

	return 0;
}

// NOTE: the funny syntax means put this method inside the NetworkControler class
// 		 the same applies to all the other class below
class NetworkController {
	public char * run(MotorController *motorController) {
		// do network stuff and 
		// return error msg or NULL
		return NULL;
	}
};

class LineController {

	typedef enum {
		SLIGHTLY_TO_LEFT,
		SLIGHTLY_TO_RIGHT,
		EXTENDS_LEFT,
		EXTENDS_RIGHT,
		EXTENDS_LEFT_AND_RIGHT,
		NO_LINE // maze completed ? // TODO DISCUSS check what is at the end of the maze
	} LineState;

	// When the lineValue (in run()) is > than SLIGHT_THRESHOLD, then 
	const long SLIGHT_THRESHOLD = 12345l;

	public char * run(MotorController *motorController) {

		while (true) {
			LineState lineValue = Camera.getLineState(); 
				// calls get the line value and then 
		}

		return NULL;
	}
};

class Camera {
	public getLineState() {

	}
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

			// TODO DISCUSS should we allow motors to be async or just make 
			// the motors stop after each action
			switch (action) { // tell movement to do stuff
				case GO_STRAIGHT:
					motorController.moveForward(0.1) // 10 cm // TODO DISCUSS m or cm?
					break;
				case TURN_LEFT:
					motorController.turnLeft(90); // degrees
					break;
				case TURN_RIGHT:
					motorController.turnLeft(90); // degrees
					break;
				case FINISH;
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
		// TODO PLAN
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
}