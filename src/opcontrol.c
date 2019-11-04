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
        if (throttle > 110) {
            throttle = MOTOR_MAX;
        }
    // Joystick is pushed backwards.
    } else if (throttle < (CONTROLLER_JOYSTICK_THRESHOLD * -1)) {
        // This is my janky way of making the joystick allow power control while also
        // allowing full power even if the joystick is not reading the proper value.
        if (throttle < -110) {
            throttle = MOTOR_MIN;
        }
    // Joystick is either slightly pushed or neutral.
    } else {
        throttle = MOTOR_IDLE;
    }

    return throttle;
}

/**
 * Left Joystick (y-axis)
 */
void leftThrottle() {
    int throttle = getThrottle(3);

    motorSet(ROBOT_MOTOR_DRIVE_LEFT1, -throttle); // Keep "-", motor is on port 1 or 10 preventing the connection from being reversed.
    motorSet(ROBOT_MOTOR_DRIVE_LEFT2, throttle);
}

/**
 * Right Joystick (y-axis)
 */
void rightThrottle() {
    // Set the right drive motors.
    int throttle = getThrottle(2);

    motorSet(ROBOT_MOTOR_DRIVE_RIGHT1, throttle);
    motorSet(ROBOT_MOTOR_DRIVE_RIGHT2, throttle);
}

/**
 * Rights Triggers (Up & Down)
 */
void giantArmButton() {
    // Right Trigger (Up)
    if (joystickGetDigital(CONTROLLER_ID, 6, JOY_UP)) {
        motorSet(ROBOT_MOTOR_ARM_LEFT1, MOTOR_MIN);
        motorSet(ROBOT_MOTOR_ARM_LEFT2, MOTOR_MIN);
        motorSet(ROBOT_MOTOR_ARM_RIGHT1, MOTOR_MIN);
        motorSet(ROBOT_MOTOR_ARM_RIGHT2, MOTOR_MIN);
    // Right Trigger (Down)
    } else if (joystickGetDigital(CONTROLLER_ID, 6, JOY_DOWN)) {
        motorSet(ROBOT_MOTOR_ARM_LEFT1, 85);
        motorSet(ROBOT_MOTOR_ARM_LEFT2, 85);
        motorSet(ROBOT_MOTOR_ARM_RIGHT1, 85);
        motorSet(ROBOT_MOTOR_ARM_RIGHT2, 85);
    } else {
        motorSet(ROBOT_MOTOR_ARM_LEFT1, MOTOR_IDLE);
        motorSet(ROBOT_MOTOR_ARM_LEFT2, MOTOR_IDLE);
        motorSet(ROBOT_MOTOR_ARM_RIGHT1, MOTOR_IDLE);
        motorSet(ROBOT_MOTOR_ARM_RIGHT2, MOTOR_IDLE);
    }
}

/**
 * Left Triggers (Up & Down)
 */
void armGrabber() {
	// Left Trigger (Up)
	if (joystickGetDigital(CONTROLLER_ID, 5, JOY_UP)) {
	    motorSet(ROBOT_MOTOR_GRABBER_LEFT, 60);
	    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, 60);
	// Left Trigger (Down)
	} else if (joystickGetDigital(CONTROLLER_ID, 5, JOY_DOWN)) {
	    motorSet(ROBOT_MOTOR_GRABBER_LEFT, -40);
	    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, -40);
	} else {
	    motorSet(ROBOT_MOTOR_GRABBER_LEFT, MOTOR_IDLE);
	    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, MOTOR_IDLE);
	}
}

void operatorControlOLD() {
    while (true) {
        // Run the left throttle control.
        leftThrottle();

        // Run the right throttle control.
        rightThrottle();

        // Giant arm button, thanks..
        giantArmButton();

        // Arm Grabber
        armGrabber();

        // Delay the loop.
		delay(20);
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

        delay(20);
    }
}
