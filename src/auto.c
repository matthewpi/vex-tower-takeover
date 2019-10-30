/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "robot.h"

enum RobotTeam team;

void driveTobor(int left, int right) {
    motorSet(ROBOT_MOTOR_DRIVE_LEFT, -left);// Keep the "-", the motor is wired directly into the cortex not allowing the connection to be flipped.
    motorSet(ROBOT_MOTOR_DRIVE_LEFT2, left);
    motorSet(ROBOT_MOTOR_DRIVE_RIGHT, right);
    motorSet(ROBOT_MOTOR_DRIVE_RIGHT2, right);
}

void driveForwards() {
    driveTobor(MOTOR_MAX, MOTOR_MAX);
}

void driveBackwards() {
    driveTobor(MOTOR_MIN, MOTOR_MIN);
}

/**
 * This is in perspective of on the RED side of the field.
 * Left will always turn towards the large goals on the field,
 * while Right will always turn towards the small goals on the field.
 */
void driveLeft() {
    if (team == TEAM_RED) {
        driveTobor(MOTOR_MIN, MOTOR_MAX);
    } else {
        driveTobor(MOTOR_MAX, MOTOR_MIN);
    }
}

/**
 * This is in perspective of on the RED side of the field.
 * Left will always turn towards the large goals on the field,
 * while Right will always turn towards the small goals on the field.
 */
void driveRight() {
    if (team == TEAM_RED) {
        driveTobor(MOTOR_MAX, MOTOR_MIN);
    } else {
        driveTobor(MOTOR_MIN, MOTOR_MAX);
    }
}

void driveStop() {
    driveTobor(MOTOR_IDLE, MOTOR_IDLE);
}

void regularAutonomous() {
    driveForwards();
    delay(750);
    driveBackwards();
    delay(750);
    driveStop();
}

void skillsAutonomous() {
    // TODO: Write
}

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous() {
    if (analogRead(ROBOT_JUMPER_AUTO_RED) > 0) {
        team = TEAM_RED;
    } else if (analogRead(ROBOT_JUMPER_AUTO_BLUE) > 0) {
        team = TEAM_BLUE;
    } else if (analogRead(ROBOT_JUMPER_AUTO_SKILLS) > 0) {
        skillsAutonomous();
        return;
    } else {
        return;
    }

    regularAutonomous();
}
