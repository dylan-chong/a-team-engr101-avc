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

    for (int i = 0; i < 320; i++) {
        //Take picture with camera
        take_picture();
        //get pixel "whiteness" from centre of image
        c = get_pixel(160, 120, 3);
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
        printf("%d\n", INT_MAX);
        return INT_MAX;
    }
        // the 0.004 is just a random small number i took, change it if you want
    else {
        printf("%d\n", sum);
        return sum;
    }
}

int main() {
    init(0);
    int count = 0;
    int sum = 1;
    while (count < 2000) {
        sum = getLineValue();
        if (sum == INT_MAX) {
            printf("%d\n", sum);
        }

        else {
            printf("%d\n", sum);
        }
        count++;
    }
    return 0;
}




// ****************** STUFF BEN ADDED ******************

// Update at like 1.20am on monday
// i had to rewrite this at 12.30am because i wrote it online and didnt save it rip.
// no clue whether this will work, typing this in word now so excuse lack of brackets and stuff
// also yeah it should be a method that returns a value and then a main one, but its kinda hard to write in word
// if it doesnt work at all just let me know and ill do it properly 
/*#include <stdio.h>
#include <time.h>


extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int Sleep(int sec, int usec);
extern "C" int set_motor(int motor, int speed);

int main() {
    init(0);
    char c;
    // possibly not the best place to put this loop (while true cause why not),
    //im going to change how its laid out just try test with this
    while (true) {
        int whiteness[320]; //the first array getting the camera input
        int white_thr = 140; //whether the number is white enough
        int white_compare[320]; // the second array to compare to (- on left, + on the right)
        int white_final[320]; // what should be the multiplied version of the two above arrays

        int sum = 0; //the sum of all the white final numbers added
        int n_whites = 0; // a count of how many white spots have been counted( to check if we can still see the line)

        for (int i = 0; i < 320; i++) {
            take_picture();
            c = get_pixel(160, 120, 3); //get pixel "whiteness" from centre of image

            //Prints read pixel value
            if (c > white_thr) {
                // if its greater than the threshold, the number is a one, and therefore white, so count increases
                whiteness[i] = 1;
                n_whites++;
            } else {
                whiteness[i] = 0;
            }
            white_compare[i] = i - 160;
            white_final[i] = whiteness[i] * white_compare[i];
        }

        // what should be the sum of white final working
        for (int i = 0; i < 320; i++) {
            sum = sum + white_final[i];
        }

        printf("sum: %d\n", sum);

        // You don't need to control the motors, just deal with the camera stuffg
        /*
        // trying to make it so if it loses the line it reverses to try make it find it again
        if (n_whites == 0) {
            int leftMotor = -35;
            int rightMotor = -35;
            set_motor(1, rightMotor);
            set_motor(2, leftMotor);
        } else {
            int leftMotor = 35 + -sum * 0.004; // the 0.004 is just a random small number i took, change it if you want
            int rightMotor = 35 + sum * 0.004;
            set_motor(1, rightMotor);
            set_motor(2, leftMotor);
        }
        
    }

    set_motor(1, 0);
    set_motor(2, 0);

    return 0;
}

void printIntArray(int[] ) {

}
*/

// ************  Old ************

/*
// Code copied from the Kaiwhata wiki that we used to test the camera
// (it worked!)
int main(){
    //This sets up the RPi hardware and ensures
    //everything is working correctly
    init(0);
    char c;
    for (int a = 0; a < 1000; a++){
        //Take picture with camera
        take_picture();
        //get pixel "whiteness" from centre of image (160x120)
        c = get_pixel(160,120,3);
        //Prints read pixel value
        printf("%d\n",c);
        //Waits for 0.5 seconds (500000 microseconds)
        Sleep(0,500000);
    }
    printf("Done");
    return 0;
}
 */
