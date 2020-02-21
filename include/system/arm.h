#ifndef SYSTEM_ARM_H_

#define SYSTEM_ARM_H_

#define ROBOT_SYSTEM_ARM_LIFT_SPEED 75
#define ROBOT_SYSTEM_ARM_DOWN_SPEED 75

/**
 * Lifts the arm.
 */
void armLift();

/**
 * Lowers the arm.
 */
void armDown();

/**
 * Stops lifting or lowering the arm.
 */
void armStop();

#endif
