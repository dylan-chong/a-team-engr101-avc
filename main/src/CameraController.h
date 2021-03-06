/*
 * CameraController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

#ifndef CAMERACONTROLLER_H_
#define CAMERACONTROLLER_H_

#include "Controller.h"

class CameraController : public Controller {
    friend class CameraControllerTest;

private:
    const static int WHITE_THRESHOLD = 120;

public:
    const static int LAST_ROW_TO_CHECK = 60;
    int n_whites;

    int inMaze();

    static CameraController *makeInstance();

    virtual ~CameraController();

    CameraController();

    int getSum(int startRow, int finishRow);

    int update(int row);
};

#endif /* CAMERACONTROLLER_H_ */
