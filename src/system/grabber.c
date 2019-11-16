#include "main.h"
#include "robot.h"
#include "system/grabber.h"

/**
 * Opens the grabber.
 */
void grabberOpen() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, -50);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, -50);
}

/**
 * Closes the grabber.
 */
void grabberClose() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, 90);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, 90);
}

/**
 * Stops moving the grabber.
 */
void grabberStop() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, MOTOR_IDLE);
}
