/*
 * CameraController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "CameraController.h"
#include <cmath>
#include <stdio.h>

extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int Sleep(int sec, int usec);

//This is the constructor
CameraController::CameraController() {
    n_whites = 0;
}

//this is the destructor
CameraController::~CameraController() {

}

CameraController *CameraController::makeInstance() {
    instance = new CameraController();
    return (CameraController *) instance;
}

//gets the total sum of the white array * the position on the white pixels from the center
int CameraController::getSum(int startRow,int finishRow) {
    //the first array getting the camera input
    int whiteness[320];
    //the sum of all the white final numbers added
    int sum = 0;
    // a count of how many white spots have been counted( to check if we can still see the line)
    n_whites = 0;
    int leftWhites = 0, rightWhites = 0;
    
    take_picture();
    for (int y = startRow; y < finishRow; y += 2) {
        for (int i = 0; i < 320; i++) {
            whiteness[i] = (get_pixel(i, y, 3) > WHITE_THRESHOLD);
            if (whiteness[i] == 1) {
                n_whites++;
                sum += (i - 160);
                if (i < 160) leftWhites++;
                else rightWhites++;
            }
        }
    }

    sum /= ((finishRow-startRow) / 2);
    n_whites /= ((finishRow-startRow) / 2);
    // trying to make it so if it loses the line it reverses to try make it find it again
    if (n_whites <= 1) { //if the line is completely lost
        throw 1;
    } else if (n_whites <= 3) { //if the line is almost lost
        throw 2;
    } else {
        return sum;
    }
}

int CameraController::update(int finishRow) { //returns thes the line value
    try {
        int sum = getSum(0,finishRow); // gets the linevalue from the top of the image to a specific row
        return sum;
    } catch (int e) {
        throw e; //throws the exception that was thrown by the sum function
    }
}
