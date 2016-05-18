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

extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int Sleep(int sec, int usec);

//This is the constructor
CameraController::CameraController(){
	center = 120;
	previousError = 0;
	dir = 'l';
}

//this is the destructor
CameraController::~CameraController() {

}

CameraController* CameraController::makeInstance(){
	instance = new CameraController();
	return (CameraController*)instance;
}

//gets an array of 1's and 0's that indicate blank and white pixels
int CameraController::getWhiteArray(){
	/*take_picture();
	for (int count = 0; count<320; count++){
		white[count]=(get_pixel(count,120,3) > WHITE_THRESHOLD);
	}
	return 0;*/
}

//gets the total sum of the white array * the position on the white pixels from the center
int CameraController::getSum(){
	    //the first array getting the camera input
	    int whiteness[320];
	    //the sum of all the white final numbers added
	    int sum = 0;
	    // a count of how many white spots have been counted( to check if we can still see the line)
	    int n_whites = 0;
	    take_picture();
	    for (int i = 0; i < 320; i++) {
	        whiteness[i] = get_pixel(i, center, 3) > WHITE_THRESHOLD;
	        n_whites += whiteness[i];
	        sum += whiteness[i] * (i - 160);
	    }
	    // trying to make it so if it loses the line it reverses to try make it find it again
	    if (n_whites == 0) {
	        return 99999;
	    }else {
	        return sum;
	    }
}

//finds the change in error and updates the previous error variable
int CameraController::differential(int sum){
	int temp = previousError;
	previousError = sum;
	return (sum-temp)/temp;
}

double CameraController::motorMovement(int sum, int differential){
	double percent = (sum/300)*Kp+differential*Kd;
	if (percent > 1){
		dir = 'l';
		return 1;
	} else if (percent <-1){
		dir = 'r';
		return 1;
	} else {
		if (percent>0){
			dir = 'l';
		} else {
			dir = 'r';
		}
		return std::abs(percent);
	}
}

double CameraController::update(){
	//getWhiteArray();
	int sum = getSum();
	return sum;
	//int diff = differential(sum);
	//return motorMovement(sum, diff);
}

char CameraController::getDir(){
	return dir;
}



