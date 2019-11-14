#include "main.h"
#include "robot.h"
#include "system/arm.h"

#define ROBOT_SYSTEM_ARM_LIFT_SPEED -127
#define ROBOT_SYSTEM_ARM_DOWN_SPEED 85

/**
 * Lifts the arm.
 */
void armLift() {
    motorSet(ROBOT_MOTOR_ARM_LEFT1, ROBOT_SYSTEM_ARM_LIFT_SPEED);
    motorSet(ROBOT_MOTOR_ARM_LEFT2, ROBOT_SYSTEM_ARM_LIFT_SPEED);
    motorSet(ROBOT_MOTOR_ARM_RIGHT1, ROBOT_SYSTEM_ARM_LIFT_SPEED);
    motorSet(ROBOT_MOTOR_ARM_RIGHT2, ROBOT_SYSTEM_ARM_LIFT_SPEED);
}

/**
 * Lowers the arm.
 */
void armDown() {
    motorSet(ROBOT_MOTOR_ARM_LEFT1, ROBOT_SYSTEM_ARM_DOWN_SPEED);
    motorSet(ROBOT_MOTOR_ARM_LEFT2, ROBOT_SYSTEM_ARM_DOWN_SPEED);
    motorSet(ROBOT_MOTOR_ARM_RIGHT1, ROBOT_SYSTEM_ARM_DOWN_SPEED);
    motorSet(ROBOT_MOTOR_ARM_RIGHT2, ROBOT_SYSTEM_ARM_DOWN_SPEED);
}

/**
 * Stops lifting or lowering the arm.
 */
void armStop() {
    motorSet(ROBOT_MOTOR_ARM_LEFT1, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_ARM_LEFT2, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_ARM_RIGHT1, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_ARM_RIGHT2, MOTOR_IDLE);
}
