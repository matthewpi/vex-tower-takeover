#include "main.h"
#include "robot.h"
#include "system/arm.h"

/**
 * Lifts the arm.
 */
void armLift() {
    motorSet(ROBOT_MOTOR_ARM_LEFT, -ROBOT_SYSTEM_ARM_LIFT_SPEED);
    motorSet(ROBOT_MOTOR_ARM_RIGHT, -ROBOT_SYSTEM_ARM_LIFT_SPEED);
}

/**
 * Lowers the arm.
 */
void armDown() {
    motorSet(ROBOT_MOTOR_ARM_LEFT, ROBOT_SYSTEM_ARM_DOWN_SPEED);
    motorSet(ROBOT_MOTOR_ARM_RIGHT, ROBOT_SYSTEM_ARM_DOWN_SPEED);
}

/**
 * Stops lifting or lowering the arm.
 */
void armStop() {
    motorSet(ROBOT_MOTOR_ARM_LEFT, MOTOR_IDLE);
    motorSet(ROBOT_MOTOR_ARM_RIGHT, MOTOR_IDLE);
}
