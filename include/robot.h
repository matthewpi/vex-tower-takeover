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
#define CONTROLLER_JOYSTICK_THRESHOLD 12//16
// END Controller

// Motors
#define ROBOT_MOTOR_DRIVE_LEFT  1
#define ROBOT_MOTOR_DRIVE_LEFT2 2

#define ROBOT_MOTOR_DRIVE_RIGHT  10
#define ROBOT_MOTOR_DRIVE_RIGHT2 3

#define ROBOT_MOTOR_ARM_LEFT1 6
#define ROBOT_MOTOR_ARM_LEFT2 7

#define ROBOT_MOTOR_ARM_RIGHT1 4
#define ROBOT_MOTOR_ARM_RIGHT2 5

#define ROBOT_MOTOR_INTAKE_LEFT  8
#define ROBOT_MOTOR_INTAKE_RIGHT 9
// END Motors

// Jumpers
#define ROBOT_JUMPER_AUTO_RED    1
#define ROBOT_JUMPER_AUTO_BLUE   2
#define ROBOT_JUMPER_AUTO_SKILLS 3
// END Jumpers

// END Robot Definitions

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
