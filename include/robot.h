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
#define ROBOT_MOTOR_DRIVE_LEFT1 9

#define ROBOT_MOTOR_DRIVE_RIGHT1 2

#define ROBOT_MOTOR_ARM_LEFT1 5
#define ROBOT_MOTOR_ARM_LEFT2 6

#define ROBOT_MOTOR_ARM_RIGHT1 3
#define ROBOT_MOTOR_ARM_RIGHT2 4

#define ROBOT_MOTOR_GRABBER_LEFT  7
#define ROBOT_MOTOR_GRABBER_RIGHT 8
// END Motors

// Jumpers
#define ROBOT_JUMPER_AUTO_RED    1
#define ROBOT_JUMPER_AUTO_BLUE   2
#define ROBOT_JUMPER_AUTO_SKILLS 3
// END Jumpers

// END Robot Definitions

#endif
