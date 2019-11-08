#include "main.h"
#include "robot.h"
#include "system/chassis.h"

/**
 * Sets the chassis' left drive motor's speed.
 */
void chassisLeft(int speed) {
    // Keep "-" motor is on port 1 or 10 preventing the connection from being reversed.
    motorSet(ROBOT_MOTOR_DRIVE_LEFT1, speed);
    motorSet(ROBOT_MOTOR_DRIVE_LEFT2, speed);
}

/**
 * Sets the chassis' right drive motor's speed.
 */
void chassisRight(int speed) {
    motorSet(ROBOT_MOTOR_DRIVE_RIGHT1, -speed);
    motorSet(ROBOT_MOTOR_DRIVE_RIGHT2, speed);
}

/**
 * Sets the chassis' drive motors speed.
 */
void chassisAll(int speed) {
    chassisLeft(speed);
    chassisRight(speed);
}

/**
 * Stops all of the chassis' drive motors.
 */
void chassisStop() {
    chassisAll(MOTOR_IDLE);
}
