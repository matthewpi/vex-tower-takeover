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

int getThrottle(int axis) {
    int throttle = joystickGetAnalog(CONTROLLER_ID, axis);
    // Joystick is pushed forwards.
    if (throttle > CONTROLLER_JOYSTICK_THRESHOLD) {
        // This is my janky way of making the joystick allow power control while also
        // allowing full power even if the joystick is not reading the proper value.
        if (throttle > 120) {
            throttle = MOTOR_MAX;
        }
    // Joystick is pushed backwards.
    } else if (throttle < (CONTROLLER_JOYSTICK_THRESHOLD * -1)) {
        // This is my janky way of making the joystick allow power control while also
        // allowing full power even if the joystick is not reading the proper value.
        if (throttle < -120) {
            throttle = MOTOR_MIN;
        }
    // Joystick is either slightly pushed or neutral.
    } else {
        throttle = MOTOR_IDLE;
    }

    return throttle;
}

void operatorControl() {
    bool slowDrive = false;
    while (true) {
        if (joystickGetDigital(CONTROLLER_ID, 7, JOY_UP)) {
            slowDrive = true;
        } else if(joystickGetDigital(CONTROLLER_ID, 7, JOY_RIGHT)) {
            slowDrive = false;
        }

        // Left Joystick (y-axis)
        int leftThrottle = getThrottle(3);
        if (leftThrottle != 0 && slowDrive) {
            leftThrottle /= 3;
        }
        chassisLeft(leftThrottle);

        // Right Joystick (y-axis)
        int rightThrottle = getThrottle(2);
        if (rightThrottle != 0 && slowDrive) {
            rightThrottle /= 3;
        }
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

        delay(20);
    }
}
