
/*
 #include <stdio.h>
 #include <time.h>


 extern "C" int init(int d_lev);
 extern "C" int take_picture();
 extern "C" char get_pixel(int row, int col, int colour);
 extern "C" int Sleep(int sec, int usec);
 */



#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <csignal>
#include <cstdlib>

extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

void handle_signal(int signal) {
	if (signal == SIGINT) {
		set_motor(1, 0);
		set_motor(2, 0);

		std::exit(0);
	}
}

double sum =0;

double getLineValue() {
	sum=0;
	char c;
	//the first array getting the camera input
	int pixelValues[320];
	//whether the number is white enough
	int white_thr = 127;

	int leftPixelWhiteness[160];
	int rightPixelWhiteness[160];

	// a count of how many white spots have been counted( to check if we can still see the line)
	int noWhitePixels = 0;

	int leftMotor = 0;
	int rightMotor = 0;

	take_picture();
	for (int i = 0; i < 320; i++) {

		c = get_pixel(i, 120, 3);
		if (c > white_thr) {
			if(i<160){
				leftPixelWhiteness[i]=c;
				sum--;
			} else{
				rightPixelWhiteness[i-160]=c;
				sum++;
			}
			noWhitePixels++;
		}
	}
	return sum;
}

void goLeft(int leftNess){ //Accepts a parameter telling it how much it should turn left
	double constant = 1; // Set the constant to make up for motors differences
	int tweakedValue = leftNess * constant; //Changing the input value by the constant
	set_motor(2,tweakedValue );
	printf("%f\n",tweakedValue);
}

void goRight(int rightNess){
	double constant = 1;
	int tweakedValue = rightNess*constant;
	set_motor(1,tweakedValue );
	printf("%f\n",tweakedValue);

}

// uses lineValue, not pid
void setMotorsBasic() {
	//int left = 0.01 * sum + 40;
	//int right = -0.02 * sum + 41;

	int pidValue=10; //INSERT PID VALUE HERE, not actually pid but the range above which it should try and correct

	if(sum>pidValue){ //more whiteness on the right
		printf("%f\n",sum);
		goLeft(60);
		goRight(40);
	} else if(sum<-pidValue){ //more whiteness on left
		printf("%f\n",sum);
		goRight(60);
		goLeft(40);
	} else  { //If going in straight line
		goLeft(40);
		goRight(40);
	}
}

int main() {
 	init(0);
	std::signal(SIGINT, handle_signal);
	int count = 0;

	while (count < 400) {
		getLineValue();
		setMotorsBasic();
		count++;
	}
	goLeft(0);
	goRight(0);
	return 0;
}

void printIntArray(int[]) {

}

