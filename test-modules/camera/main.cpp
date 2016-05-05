#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row,int col,int colour);
extern "C" int Sleep(int sec, int usec);

long getLineValue() {
    long value = 0;

    // Ben do your calculation stuff here

    return value;
}

// This method is just for testing your getLineValue() method.
// Not for use in main project
int main() {

    // Ben, make a printf statement that will print out the result
    // of the getLineValue() method so that you can test if it's working

    return 0;
}


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