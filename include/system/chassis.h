#ifndef SYSTEM_CHASSIS_H_

#define SYSTEM_CHASSIS_H_

/**
 * Sets the chassis' left drive motors speed.
 */
void chassisLeft(int speed);

/**
 * Sets the chassis' right drive motors speed.
 */
void chassisRight(int speed);

/**
 * Sets the chassis' drive motors speed.
 */
void chassisAll(int speed);

/**
 * Stops all of the chassis' drive motors.
 */
void chassisStop();

#endif
