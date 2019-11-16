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
#include "system/arm.h"
#include "system/chassis.h"
#include "system/grabber.h"

enum RobotTeam team;

/**
 * This is in perspective of on the RED side of the field.
 * Left will always turn towards the large goals on the field,
 * while Right will always turn towards the small goals on the field.
 */
void driveLeft(int speed) {
    if (speed < 0) {
        return;
    }

    if (team == TEAM_RED) {
        chassisLeft(-speed);
        chassisRight(speed);
    } else {
        chassisLeft(speed);
        chassisRight(-speed);
    }
}

/**
 * This is in perspective of on the RED side of the field.
 * Left will always turn towards the large goals on the field,
 * while Right will always turn towards the small goals on the field.
 */
void driveRight(int speed) {
    if (speed < 0) {
        return;
    }

    if (team == TEAM_RED) {
        chassisLeft(speed);
        chassisRight(-speed);
    } else {
        chassisLeft(-speed);
        chassisRight(speed);
    }
}

void regularAutonomous() {
    /*// Drive forwards
    chassisAll(MOTOR_MAX);
    delay(500);
    chassisStop();

    // Close grabber
    grabberClose();
    delay(250);
    grabberStop();

    // Drive forwards
    chassisAll(MOTOR_MAX);
    delay(500);
    chassisStop();

    // Lift arm
    armLift();
    delay(300);
    armStop();

    // Drive forwards
    chassisAll(75);
    delay(250);
    chassisStop();

    // Open grabber
    grabberOpen();
    delay(250);
    grabberStop();

    // Lower arm
    armDown();
    delay(300);
    armStop();

    // Close grabber
    grabberClose();
    delay(250);
    grabberStop();

    // Lift arm
    armLift();
    delay(150);
    armStop();

    // Drive backwards
    chassisAll(-75);
    delay(1500);
    chassisStop();

    // Turn left
    driveLeft(75);
    delay(300);

    // Drive forwards
    chassisAll(75);
    delay(2250);
    chassisStop();

    // Lower arm
    armDown();
    delay(150);
    armStop();

    // Open grabber
    grabberOpen();
    delay(250);
    grabberStop();

    // Drive backwards
    chassisAll(MOTOR_MIN);
    delay(500);
    chassisStop();*/
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
    /*if (analogRead(ROBOT_JUMPER_AUTO_RED) > 0) {
        team = TEAM_RED;
    } else if (analogRead(ROBOT_JUMPER_AUTO_BLUE) > 0) {
        team = TEAM_BLUE;
    } else if (analogRead(ROBOT_JUMPER_AUTO_SKILLS) > 0) {
        skillsAutonomous();
        return;
    } else {
        return;
    }

    regularAutonomous();*/

    chassisAll(MOTOR_MAX);
    delay(500);
    chassisAll(MOTOR_MIN);
    delay(500);
    chassisStop();
}
