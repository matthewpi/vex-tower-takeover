/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "robot.h"
#include "system/arm.h"
#include "system/chassis.h"
#include "system/grabber.h"

#define ARM_POSITION_HIGHEST 1
#define ARM_POSITION_MEDIUM  2
#define ARM_POSITION_LOWEST  3
#define ARM_POSITION_ZERO    4

int requestedArmPosition = -1;
bool firstValuesComputed = false;
bool isPositionBackwards = false;

/**
 * Get's the throttle value for a motor from a joystick.
 *
 * If the joystick's value is not past "CONTROLLER_JOYSTICK_THRESHOLD",
 * negatively or positively the return value will be "MOTOR_IDLE".
 */
int getThrottle(int axis) {
    int throttle = joystickGetAnalog(CONTROLLER_ID, axis);
    bool reversed = (throttle < 0);
    throttle = abs(throttle);

    if (throttle < CONTROLLER_JOYSTICK_THRESHOLD) {
        return MOTOR_IDLE;
    }

    if (throttle < 40) {
        throttle = 40;
    } else if (throttle > 120) {
        throttle = MOTOR_MAX;
    }

    if (reversed) {
        throttle *= -1;
    }

    return throttle;
}

void operatorControl() {
    while (true) {
        // Left Joystick (y-axis)
        int leftThrottle = getThrottle(3);
        chassisLeft(leftThrottle);

        // Right Joystick (y-axis)
        int rightThrottle = getThrottle(2);
        chassisRight(rightThrottle);

        // Arm Position Buttons
        if (joystickGetDigital(CONTROLLER_ID, 8, JOY_UP)) {
            requestedArmPosition = ARM_POSITION_HIGHEST;
        } else if (joystickGetDigital(CONTROLLER_ID, 8, JOY_RIGHT)) {
            requestedArmPosition = ARM_POSITION_MEDIUM;
        } else if (joystickGetDigital(CONTROLLER_ID, 8, JOY_LEFT)) {
            requestedArmPosition = ARM_POSITION_LOWEST;
        } else if (joystickGetDigital(CONTROLLER_ID, 8, JOY_DOWN)) {
            requestedArmPosition = ARM_POSITION_ZERO;
        }

        // Right Trigger (Up)
        if (joystickGetDigital(CONTROLLER_ID, 6, JOY_UP)) {
            armLift();
            requestedArmPosition = -1;
        // Right Trigger (Down)
        } else if (joystickGetDigital(CONTROLLER_ID, 6, JOY_DOWN)) {
            armDown();
            requestedArmPosition = -1;
        } else {
            armStop();
        }

        // Left Trigger (Up)
    	if (joystickGetDigital(CONTROLLER_ID, 5, JOY_UP)) {
    	    grabberClose();
    	// Left Trigger (Down)
    	} else if (joystickGetDigital(CONTROLLER_ID, 5, JOY_DOWN)) {
            if (digitalRead(1) == LOW) {
                grabberStop();
            } else {
                grabberOpen();
            }
    	} else {
            grabberStop();
        }

        if (requestedArmPosition != -1) {
            int potentiometerLimit = -1;

            switch (requestedArmPosition) {
            case ARM_POSITION_HIGHEST:
                potentiometerLimit = 900;
                break;
            case ARM_POSITION_MEDIUM:
                potentiometerLimit = 1200;
                break;
            case ARM_POSITION_LOWEST:
                potentiometerLimit = 1800;
                break;
            case ARM_POSITION_ZERO:
                potentiometerLimit = 2500;
                break;
            }

            if (potentiometerLimit != -1) {
                int potentiometerValue = analogRead(1);

                if (!firstValuesComputed) {
                    isPositionBackwards = potentiometerValue < potentiometerLimit;
                    firstValuesComputed = true;
                }

                if (!isPositionBackwards) {
                    if (potentiometerValue > potentiometerLimit) {
                        armLift();
                    } else {
                        requestedArmPosition = -1;
                        firstValuesComputed = false;
                        armStop();
                    }
                } else {
                    if (potentiometerValue < potentiometerLimit) {
                        armDown();
                    } else {
                        requestedArmPosition = -1;
                        firstValuesComputed = false;
                        armStop();
                    }
                }
            }
        }

        // printf("%d\n", analogRead(1));

        // Motors can only be updated every 20ms.
        delay(20);
    }
}
