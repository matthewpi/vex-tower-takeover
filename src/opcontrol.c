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

#define DRIVE_MINIMUM_SPEED 30
#define DRIVE_SLOW_MAXIMUM_SPEED 80
#define DRIVE_SLOW_MULTIPLIER 1.5

/**
 * Get's the throttle value for a motor from a joystick.
 *
 * If the joystick's value is not past "CONTROLLER_JOYSTICK_THRESHOLD",
 * negatively or positively the return value will be "MOTOR_IDLE"
 * no matter if the "slow" parameter is true or false.
 *
 * If "slow" is true, the value from the joystick will be:
 *     - Multiplied by "DRIVE_SLOW_MULTIPLIER"
 *     - Capped at "DRIVE_SLOW_MAXIMUM_SPEED" if the value exceeds it
 *     - Motors will run at a minimum "DRIVE_MINIMUM_SPEED"
 */
int getThrottle(int axis) {
    int throttle = joystickGetAnalog(CONTROLLER_ID, axis);
    if (throttle > CONTROLLER_JOYSTICK_THRESHOLD) {
        return MOTOR_MAX;
    } else if (throttle < (CONTROLLER_JOYSTICK_THRESHOLD * -1)) {
        return MOTOR_MIN;
    } else {
        return MOTOR_IDLE;
    }
}

void operatorControl() {
    while (true) {
        // Left Joystick (y-axis)
        int leftThrottle = getThrottle(3);
        chassisLeft(leftThrottle);

        // Right Joystick (y-axis)
        int rightThrottle = getThrottle(2);
        chassisRight(rightThrottle);

        // Right Trigger (Up)
        if (joystickGetDigital(CONTROLLER_ID, 6, JOY_UP)) {
            armLift();
        // Right Trigger (Down)
        } else if (joystickGetDigital(CONTROLLER_ID, 6, JOY_DOWN)) {
            armDown();
        } else {
            armStop();
        }

        // Left Trigger (Up)
    	if (joystickGetDigital(CONTROLLER_ID, 5, JOY_UP)) {
    	    grabberClose();
    	// Left Trigger (Down)
    	} else if (joystickGetDigital(CONTROLLER_ID, 5, JOY_DOWN)) {
    	    grabberOpen();
    	} else {
    	    grabberStop();
    	}

        // Motors can only be updated every 20ms.
        delay(20);
    }
}
