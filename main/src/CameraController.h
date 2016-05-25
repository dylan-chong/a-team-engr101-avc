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
    const static int CENTER_ROW = 60;
    int n_whites;

    static CameraController *makeInstance();

    virtual ~CameraController();

    CameraController();

    int getSum(int row);

    int update(int row);

    int getMidColOfLine();
};

#endif /* CAMERACONTROLLER_H_ */
