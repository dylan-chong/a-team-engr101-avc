/*
 * IRController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

#ifndef IRCONTROLLER_H_
#define IRCONTROLLER_H_

#include "Controller.h"

class IRController : public Controller {
    friend class IRControllerTest;

private:
    float leftThreshold;
    float rightThreshold;
    float middleThreshold;
    bool thresholdSet;

    double lastLeftDistance;
    double lastRightDistance;
    double lastMiddleDIstance;

public:
    int preRight;

    static IRController *makeInstance();

    virtual ~IRController();

    IRController();

    float getDistanceFromSensor(int sensorPin);

    float getLeftDistance();

    float getMiddleDistance();

    float getRightDistance();

    void setThreshold(float left, float right, float middle);

    int getSum();



    double update();

    bool inMaze();
};

#endif /* IRCONTROLLER_H_ */
