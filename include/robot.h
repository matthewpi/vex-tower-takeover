#ifndef ROBOT_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define ROBOT_H_

enum RobotTeam {
    TEAM_RED  = 1,
    TEAM_BLUE = 2,
};

// Motor Definitions
#define MOTOR_MAX  127
#define MOTOR_IDLE 0
#define MOTOR_MIN  -127
// END Motor Definitions

// Robot Definitions

// Controller
#define CONTROLLER_ID 1
#define CONTROLLER_JOYSTICK_THRESHOLD 16
// END Controller

// Motors
/*
1: Empty
2: Right Drive 1
3: Right Drive 2
4: Arm Right
5: Grabber Right
6: Grabber Left
7: Arm Left
8: Left Drive 1
9: Left Drive 2
10: Empty
*/

#define ROBOT_MOTOR_DRIVE_LEFT1 8
#define ROBOT_MOTOR_DRIVE_LEFT2 9

#define ROBOT_MOTOR_DRIVE_RIGHT1 2
#define ROBOT_MOTOR_DRIVE_RIGHT2 3

#define ROBOT_MOTOR_ARM_LEFT 7

#define ROBOT_MOTOR_ARM_RIGHT 4

#define ROBOT_MOTOR_GRABBER_LEFT  6
#define ROBOT_MOTOR_GRABBER_RIGHT 5
// END Motors

// END Robot Definitions

#endif
