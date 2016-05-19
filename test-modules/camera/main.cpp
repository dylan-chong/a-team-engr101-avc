// ****************** TEMPLATE STUFF ******************

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

    // Ben do your calculation stuff here

    return value;
}

// This method is just for testing your getLineValue() method.
// Not for use in main project
/* TODO LATER use this actual main method
int main() {

    // Ben, make a printf statement that will print out the result
    // of the getLineValue() method so that you can test if it's working

    return 0;
}*/

//******** new stuff that ben wrote*********

#include <stdio.h>
#include <time.h>
#include <limits.h>


extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

int getLineValue() {
    char c;
    //the first array getting the camera input
    int whiteness[320];
    //whether the number is white enough
    int white_thr = 127;
    // the second array to compare to (- on left, + on the right)
    int white_compare[320];
    // what should be the multiplied version of the two above arrays
    int white_final[320];
    //the sum of all the white final numbers added 
    int sum = 0;
    // a count of how many white spots have been counted( to check if we can still see the line)
    int n_whites = 0;
    // left motor vroom vroom
    int leftMotor = 0;
    // right motor also vroom vroom
    int rightMotor = 0;
    take_picture();
    for (int i = 0; i < 320; i++) {
        //Take picture with camera
        
        //get pixel "whiteness" from centre of image
        c = get_pixel(i, 120, 3);
        //printf("%d\n", c);
        if (c > white_thr) {
            // if its greater than the threshold, the number is a one, and therefore white, so count increases
            whiteness[i] = 1;
            n_whites++;
        }
        else {
            whiteness[i] = 0;
        }
        white_compare[i] = i - 160;
        white_final[i] = whiteness[i] * white_compare[i];
    }

    // what should be the sum of white final working
    for (int i = 0; i < 320; i++) {
        sum = sum + white_final[i];
    }
    // trying to make it so if it loses the line it reverses to try make it find it again
    if (n_whites == 0) {
        printf("%d\n", sum);
        return sum;
    }
        // the 0.004 is just a random small number i took, change it if you want
    else {
        printf("%d\n", sum);
        return sum;
    }
}

// uses lineValue, not pid
void setMotorsBasic(int lineValue) {
    int left = 0.004*lineValue +40;
    int right = -0.012*lineValue +41;
    set_motor(2, left); // left
    set_motor(1,right); // right
    printf("LV: %d, L: %d, R: %d\n", lineValue, left, right);
}

int main() {
    init(0);
    int count = 0;
    int sum = 1;

    while (count < 2000) {
        sum = getLineValue();

        setMotorsBasic(sum);

        count++;
    }
    return 0;
}





void printIntArray(int[] ) {

}



