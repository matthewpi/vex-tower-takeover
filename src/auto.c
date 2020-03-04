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

enum RobotTeam team = TEAM_RED;

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

void largeGoalAutonomous() {
    // Push cube into goal.
    chassisAll(MOTOR_MAX);
    delay(850);
    chassisAll(MOTOR_MIN);
    delay(170);

    // Turn towards the center of the field.
    driveRight(MOTOR_MAX);
    delay(850);

    // Drive forwards.
    chassisAll(MOTOR_MAX);
    delay(1000);
    chassisStop();

    // Close grabber.
    grabberClose();
    delay(425);
    grabberStop();

    // Turn towards the field perimeter.
    driveLeft(MOTOR_MAX);
    delay(850);

    // Drive forwards.
    chassisAll(MOTOR_MAX);
    delay(450);

    // Turn left.
    driveLeft(MOTOR_MAX);
    delay(450);

    // Drive forwards.
    chassisAll(MOTOR_MAX);
    delay(550);
    chassisStop();

    // Open the grabber.
    grabberOpen();
    delay(200);
    chassisAll(MOTOR_MIN);
    delay(500);
    grabberStop();

    // Drive backwards
}

void smallGoalAutonomous() {
    // Push cube into goal.
    chassisAll(MOTOR_MAX);
    delay(800);
    chassisAll(MOTOR_MIN);
    delay(350);

    // Turn towards the center of the field.
    driveLeft(MOTOR_MAX);
    delay(750);

    // Drive forwards.
    chassisAll(MOTOR_MAX);
    delay(600);
    chassisStop();

    // Close grabber.
    grabberClose();
    delay(425);
    grabberStop();

    // Turn towards the goal.
    driveRight(MOTOR_MAX);
    delay(1090);
    chassisStop();

    // Lift the arm.
    while (analogRead(1) > 2100) {
        armLift();
        delay(20);
    }
    armStop();

    // Drive forwards.
    chassisAll(80);
    delay(650);
    chassisStop();

    // Lower the arm.
    armDown();
    delay(200);
    armStop();
    delay(100);

    // Open the grabber, wait, drive backwards, wait, then stop the grabber and the chassis.
    grabberOpen();
    delay(100);
    chassisAll(-80);
    delay(450);
    grabberStop();
    chassisStop();

    // Lower the arm all the way.
    while (analogRead(1) < 2500) {
        armDown();
        delay(20);
    }
    armStop();

    // Drive forwards.
    /*chassisAll(-80);
    delay(200);
    chassisStop();*/

    // Turn towards the cubes.
    /*driveLeft(MOTOR_MAX);
    delay(1090);
    chassisStop();*/

    // Close the grabber.
    /*grabberClose();
    delay(425);
    grabberStop();*/

    // Turn towards the cubes.
    /*driveLeft(MOTOR_MAX);
    delay(1090);
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

    largeGoalAutonomous();
}
