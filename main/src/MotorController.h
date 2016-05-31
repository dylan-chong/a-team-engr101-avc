/*
 * MotorController.h
 *
 *  Created on: 21/04/2016
 *      Author: mcghieandr
 *
 */

//Variables for the motorController Class

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Controller.h"

class MotorController : public Controller {
    friend class MotorControllerTest;

private:
    const static int NUMBER_OF_REVERSE_SPEEDS = 9;
    int RIGHT_SPEEDS[21];

    // Values for the PI
    const static int LEFT_MAX = 9;
    const static int LEFT_MIN = -9;
    const static int RIGHT_MAX = 9;
    const static int RIGHT_MIN = -9;

    void freezeIfSpeedOutOfRange(int speed);

    void setLeft(int speed);

    void setRight(int speed);

    void moveStraightAtSpeed(int speed);

    void freezeIfDirectionOutOfRange(double direction);

public:

    static MotorController *makeInstance();

    virtual ~MotorController();

    MotorController();

    void moveForward();

    void moveBackward();

    void stopMovement();

    void rotateLeft();
    void rotateLeftIR();

    void rotateRight();

    void arc(double percent, double speedScale);
};

#endif /* MOTORCONTROLLER_H_ */
