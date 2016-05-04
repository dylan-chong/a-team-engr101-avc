#include <stdio.h>

// NOTE: This is only pseudo code for 
// jotting down the jist of things. Syntax is very 
// very un-C.


// NOTE: the funny syntax means put this method inside the NetworkControler clas
char * NetworkController.run(MovementController *movement) {
	// do network stuff and 
	// return error msg or NULL
	return NULL;
}

char * LineController.run(MovementController *movement) {

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

char * MazeController.run(MovementController *movement) {

	while (true) {
		float leftDistance = IR.getLeftDistance(); // use real class name instead of IR
		float middleDistance = IR.getMiddleDistance();
		float rightDistance = IR.getRightDistance();

		MazeAction action = 
			controller.getAction(leftDistance, middleDistance, rightDistance);

		switch (action) { // tell movement to do stuff
			case GO_STRAIGHT:
				break;
			case TURN_LEFT:
				break;
			case TURN_RIGHT:
				break;
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

char * FinishedController.run() {
	// spin around in circles, 
	// after passing the finish line

	// or don't get too cocky and just stay still
	return "Too much win";
}

char * run() {
	{
		// TODO NEXT get netowkr instance	
		char error[] = runNetwork();
		if (error) {
			return "Network State: " + error;
		}
	}
	{
		char error[] = runLine();
		if (error) {
			return "Line State: " + error;
		}
	}
	{
		char error[] = runMaze();
		if (error) {
			return "Maze State: " + error;
		}
	}
	{
		char error[] = runFinished();
		if (error) {
			return "Finished State: " + error;
		}
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