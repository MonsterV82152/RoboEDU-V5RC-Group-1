#include "main.h"
#include <cmath>



#ifndef CONFIG_HPP
#define CONFIG_HPP


#include <string>
#include <stdlib.h>
#include <iostream>

/* ------------------------------------------------------------------------------------------------------------------------ */
// All #Defines

// Constants
#define PI 3.1415//92653589793238462643383279502884197169399375105820
#define TWradius 1.375

#define driver pros::E_CONTROLLER_MASTER
#define driver_2 pros::E_CONTROLLER_PARTNER

#define button_R1 pros::E_CONTROLLER_DIGITAL_R1
#define button_R2 pros::E_CONTROLLER_DIGITAL_R2
#define button_L1 pros::E_CONTROLLER_DIGITAL_L1
#define button_L2 pros::E_CONTROLLER_DIGITAL_L2
#define button_A pros::E_CONTROLLER_DIGITAL_A
#define button_B pros::E_CONTROLLER_DIGITAL_B
#define button_Y pros::E_CONTROLLER_DIGITAL_Y
#define button_X pros::E_CONTROLLER_DIGITAL_X
#define button_UP pros::E_CONTROLLER_DIGITAL_UP
#define button_DOWN pros::E_CONTROLLER_DIGITAL_DOWN
#define button_LEFT pros::E_CONTROLLER_DIGITAL_LEFT
#define button_RIGHT pros::E_CONTROLLER_DIGITAL_RIGHT
#define COAST pros::E_MOTOR_BRAKE_COAST
#define BRAKE pros::E_MOTOR_BRAKE_BRAKE
#define HOLD pros::E_MOTOR_BRAKE_HOLD



// Pnumatic Ports
#define clawport 'H'
#define wingport 'E'


// Mechanism Motors
#define RIport 2
#define HSMport -8
#define WSSMport 15


// Drivetrain Motors

// Assume clamp is front, 1 is front, 3 is back
#define right_motor_1 12
#define right_motor_2 -10
#define right_motor_3 6

#define left_motor_1 -14
#define left_motor_2 18
#define left_motor_3 -16


// Sensors
#define IMUport 19
#define VTWport 20
#define HTWport 4

//PID Values
//Odom Pid
#define odomKp 5.5
#define odomKi 0.2
#define odomKd 2

#define turnKp 4.2
#define turnKi 0.1
#define turnKd 2

// #define odomKp 5
// #define odomKi 0
// #define odomKd 2

// #define turnKp 3
// #define turnKi 0
// #define turnKd 0

//Team
inline bool team = false;

inline int autonselector = 0;

/* --------------- s--------------------------------------------------------------------------------------------------------- */
// Sensors & Calibration
inline pros::Imu imu_sensor(IMUport);
inline pros::Rotation verticaltracking(VTWport);
inline pros::Rotation horizontaltracking(HTWport);
inline pros::Optical optical_sensor(17);


// Motors & Pnumatics

inline pros::ADIDigitalOut clawp(clawport);
inline pros::ADIDigitalOut wing(wingport);

inline pros::Motor intakeMotor(RIport);
inline pros::Motor hookMotor(HSMport);
inline pros::Motor swallMotor(WSSMport);


inline pros::MotorGroup right_mg({right_motor_1, right_motor_2, right_motor_3});
inline pros::MotorGroup left_mg({left_motor_1, left_motor_2, left_motor_3});


// Controllers

inline pros::Controller master(driver);
inline pros::Controller master2(driver_2);




template <typename T> constexpr T sgn(T value) { return value < 0 ? -1 : 1; }


#endif 