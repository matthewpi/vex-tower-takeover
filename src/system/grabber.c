#include "main.h"
#include "robot.h"
#include "system/grabber.h"

void grabberOpen() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, -40);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, -40);
}

void grabberClose() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, 60);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, 60);
}

void grabberStop() {
    motorSet(ROBOT_MOTOR_GRABBER_LEFT, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_GRABBER_RIGHT, MOTOR_IDLE);
}
