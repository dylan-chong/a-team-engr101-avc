#include <stdio.h>

// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS
// TODO DISCUSS 5 May Dylan/Andrew - things marked TODO DISCUSS

// NOTE: This file is only pseudo code for 
// jotting down the jist of things. Syntax is a bit un-C.


char * run() {
	{
		char error[] = NetworkController.getInstance().run();
		if (error) {
			return "Network State: " + error;
		}
	}
	{
		char error[] = LineController.getInstance().run();
		if (error) {
			return "Line State: " + error;
		}
	}
	{
		char error[] = MazeController.getInstance().run();
		if (error) {
			return "Maze State: " + error;
		}
	}
	{
		// spin around in circles, 
		// after passing the finish line
		// or don't get too cocky and just stay still
	}

	return NULL;
}

int main() {

	char error[] = run();
	if (error != NULL) {
		printf("\n\nError during %s\n\n", error);
	}

	printf("%s\n", "Done");

	return 0;
}

// NOTE: the funny syntax means put this method inside the NetworkControler class
// 		 the same applies to all the other class below
class NetworkController {
	char * run(MotorController *motorController) {
		// do network stuff and 
		// return error msg or NULL
		return NULL;
	}
};

class LineController {
	char * run(MotorController *motorController) {

		/* 

		maybe just return an enum
			typedef enum { // line is...
				SLIGHTLY_TO_LEFT,
				SLIGHTLY_TO_RIGHT,
				FAR_TO_LEFT,
				FAR_TO_RIGHT,
				FAR_TO_LEFT_AND_RIGHT,
				NO_LINE
			} CameraResult;
		and have a camera.update method

		need camera processed value?
		or just ask camera class for 
			- isLineSlightlyToLeft() or right
			- doesLineHaveSharpLeft() and right

		*/
		return NULL;
	}
};

class MazeController {
	char * run(MotorController *motorController) {

		while (true) {
			float leftDistance = IR.getLeftDistance(); // use real class name instead of IR
			float middleDistance = IR.getMiddleDistance();
			float rightDistance = IR.getRightDistance();

			MazeAction action = 
				getNextAction(leftDistance, middleDistance, rightDistance);
				// getNextAction is part of MazeController

			// TODO DISCUSS should we allow this to be 

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
				default:
					motorController.ensureStop();
					return "No valid action";
			}
		}
		/*
		

		typedef enum {
			GO_STRAIGHT,
			TURN_LEFT,
			TURN_RIGHT,
			//REGRESS?
		} MazeAction;



		*/

		return NULL;
	}
};