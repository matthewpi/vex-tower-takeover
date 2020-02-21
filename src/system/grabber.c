#include "main.h"
#include "robot.h"
#include "system/grabber.h"

/**
 * Opens the grabber.
 */
void grabberOpen() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, -ROBOT_SYSTEM_GRABBER_OPEN_SPEED);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, -ROBOT_SYSTEM_GRABBER_OPEN_SPEED);
}

/**
 * Closes the grabber.
 */
void grabberClose() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, ROBOT_SYSTEM_GRABBER_CLOSE_SPEED);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, ROBOT_SYSTEM_GRABBER_CLOSE_SPEED);
}

/**
 * Stops moving the grabber.
 */
void grabberStop() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, MOTOR_IDLE);
}
