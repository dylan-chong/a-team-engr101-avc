
/*
 #include <stdio.h>
 #include <time.h>


 extern "C" int init(int d_lev);
 extern "C" int take_picture();
 extern "C" char get_pixel(int row, int col, int colour);
 extern "C" int Sleep(int sec, int usec);
 */

long getLineValue2() {
	long value = 0;

	return value;
}

#include <stdio.h>
#include <time.h>
#include <limits.h>

extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);


double sum =0;

double getLineValue() {
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
			if(i<120){
				leftPixelWhiteness[i]=c;
				sum--;
			} else{
				rightPixelWhiteness[i]=c;
				sum++;
			}
			noWhitePixels++;
		}
	}
	return sum;
}

void goLeft(int leftNess){ //Accepts a parameter telling it how much it should turn left
	double constant = 0.01; // Set the constant to make up for motors differences
	int tweakedValue = leftNess * constant; //Changing the input value by the constant
	set_motor(2,tweakedValue );
}

void goRight(int rightNess){
	double constant = -0.02;
	int tweakedValue = rightNess * constant;
	set_motor(1,tweakedValue );
}

// uses lineValue, not pid
void setMotorsBasic() {
	//int left = 0.01 * sum + 40;
	//int right = -0.02 * sum + 41;

	int pidValue=20; //INSERT PID VALUE HERE, not actually pid but the range above which it should try and correct

	if(sum>pidValue){ //more whiteness on the right


	} else if(sum<-pidValue){ //more whiteness on left

	}
}

int main() {
	init(0);
	int count = 0;
	int sum = 1;

	while (count < 2000) {
		getLineValue();
		printf("%d",sum);
		setMotorsBasic();
		goLeft(40);
		goRight(40);
		count++;
	}
	return 0;
}

void printIntArray(int[]) {

}

