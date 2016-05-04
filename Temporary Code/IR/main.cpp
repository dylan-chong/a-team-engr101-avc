#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int take_picture();
extern "C" char get_pixel(int row,int col,int colour);
extern "C" int Sleep(int sec, int usec);

int main(){
    //This sets up the RPi hardware and ensures
    //everything is working correctly
    init(0);
    
    printf("Done");
    return 0;
}