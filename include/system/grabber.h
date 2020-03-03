#ifndef SYSTEM_GRABBER_H_

#define SYSTEM_GRABBER_H_

#define ROBOT_SYSTEM_GRABBER_OPEN_SPEED  127
#define ROBOT_SYSTEM_GRABBER_CLOSE_SPEED 127

/**
 * Opens the grabber.
 */
void grabberOpen();

/**
 * Closes the grabber.
 */
void grabberClose();

/**
 * Stops moving the grabber.
 */
void grabberStop();

#endif
