#include <stdio.h>


// NOTE: This is only pseudo code for 
// jotting down the jist of things. Syntax is very 
// very un-C.


char * runNetwork() {
	// do network stuff and 
	// return error msg or NULL
	return NULL;
}

char * runLine() {
	return NULL;
}

char * runMaze() {
	return NULL;
}

char * runFinished() {
	// spin around in circles, 
	// after passing the finish line
	return "Too much win";
}


char * run() {
	{
		char error[] = runNetwork();
		if (error) {
			return "Error during Network State: " + error;
		}
	}
	{
		char error[] = runLine();
		if (error) {
			return "Error during Line State: " + error;
		}
	}
	{
		char error[] = runMaze();
		if (error) {
			return "Error during Maze State: " + error;
		}
	}
	{
		char error[] = runFinished();
		if (error) {
			return "Error during Finished State: " + error;
		}
	}

	return NULL;
}

int main() {

	char error[] = run();
	if (error != NULL) {
		printf("\n\n%s\n\n", error);
	}

	printf("%s\n", "Done");

	return 0;
}