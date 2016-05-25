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
    dir = 'l';
}

//this is the destructor
CameraController::~CameraController() {

}

CameraController *CameraController::makeInstance() {
    instance = new CameraController();
    return (CameraController *) instance;
}

//gets the total sum of the white array * the position on the white pixels from the center
int CameraController::getSum(int row) {
    //the first array getting the camera input
    int whiteness[320];
    //the sum of all the white final numbers added
    int sum = 0;
    // a count of how many white spots have been counted( to check if we can still see the line)
    n_whites = 0;
    take_picture();
    for (int y = 0; y < row; y += 2) {
        for (int i = 0; i < 320; i++) {
            whiteness[i] = (get_pixel(i, y, 3) > WHITE_THRESHOLD);
            n_whites += whiteness[i];
            sum += whiteness[i] * (i - 160);
        }
    }
    sum /= (row * 2);
    // trying to make it so if it loses the line it reverses to try make it find it again
    if (n_whites <= 15) { //if the line is completely lost
        throw 1;
        // }else if (n_whites <= 800){ //if the line ends SIM ONLY
    } else if (n_whites <= 200) { //LIVE ONLY
        throw 2;
    } else {
        return sum;
    }
}

int CameraController::update(int row) {
    try {
        int sum = getSum(row);
        return sum;
    } catch (int e) {
        throw e;
    }
}

char CameraController::getDir() {
    return dir;
}



