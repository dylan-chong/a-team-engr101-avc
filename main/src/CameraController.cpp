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
int * CameraController::getWhiteArray(){
	take_picture();
	int white[320];
	for (int count = 0; count<320; count++){
		try{
			white[count]=(get_pixel(count,120,3) > WHITE_THRESHOLD);
		} catch(int e){}
	}
	int * whitePointer = white;
	return whitePointer;
}

//gets the total sum of the white array * the position on the white pixels from the center
int CameraController::getSum(int* white){
	int total = 0;
	for (int count = 0; count<320; count++){
		total += *(white + count)*(count-center);
	}
	return total;
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
	int sum = getSum(getWhiteArray());
	int diff = differential(sum);
	return motorMovement(sum, diff);
}

char CameraController::getDir(){
	return dir;
}



