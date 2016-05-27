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
int CameraController::getSum(int startRow, int finishRow) {
    int SIDE_COUNT_WIDTH = 140; // must be less than 160
    // NOTE: the line takes up 166 pixels across

    //the first array getting the camera input
    int whiteness[320];
    //the sum of all the white final numbers added
    int sum = 0;
    // a count of how many white spots have been counted( to check if we can still see the line)
    n_whites = 0;
    int leftWhites = 0, rightWhites = 0, centreWhites = 0;

    take_picture();
    for (int y = startRow; y < finishRow; y += 2) {
        for (int i = 0; i < 320; i++) {
            whiteness[i] = (get_pixel(i, y, 3) > WHITE_THRESHOLD);
            if (whiteness[i] == 1) {
                n_whites++;
                sum += (i - 160);

                if (i < SIDE_COUNT_WIDTH) leftWhites++;
                if (i > 320 - SIDE_COUNT_WIDTH) rightWhites++;
                if (i > centreWhites && i < 320 - centreWhites) centreWhites++;
            }
        }
    }

//    printf("\nLINE\n");
//    for (int a = 0; a < 320; a+=2) {
//        printf("%d", whiteness[a]);
//    }
//    printf("\nEND LINE\n");


    sum /= ((finishRow - startRow) / 2);
    n_whites /= ((finishRow - startRow) / 2);

    int rows = finishRow - startRow;

    // trying to make it so if it loses the line it reverses to try make it find it again
    if (n_whites <= 1) { //if the line is completely lost
        throw 1;
    } else if (n_whites <= 3) { //if the line is almost lost
        throw 2;
    } else if (leftWhites > 80 * rows && centreWhites > 40 * rows) {
        throw 3;
    } else if (rightWhites > 80 * rows && centreWhites > 40 * rows) {
        throw 4;
    } else {
        return sum;
    }
}

int CameraController::update(int finishRow) { //returns thes the line value
    try {
        int sum = getSum(0, finishRow); // gets the linevalue from the top of the image to a specific row
        return sum;
    } catch (int e) {
        throw e; //throws the exception that was thrown by the sum function
    }
}
