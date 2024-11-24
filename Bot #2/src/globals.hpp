#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "main.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "lemlib/api.hpp"

/*----------------------Defines----------------------*/

// Constants
#define PI 3.141592
#define TWradius 1.375

/*---Controller---*/
#define driver pros::E_CONTROLLER_MASTER
#define driver_2 pros::E_CONTROLLER_PARTNER

//Buttons
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

/*---Motors---*/

//DriveTrain
#define PORT_left_dr_1 1
#define PORT_left_dr_2 -2
#define PORT_left_dr_3 3

#define PORT_right_dr_1 4
#define PORT_right_dr_2 -5
#define PORT_right_dr_3 6

//Mechanisms
#define PORT_intake 7
#define PORT_hook 8
#define PORT_lbMech 9

/*---PID Values---*/

#define lateralKp 5
#define lateralKi 0
#define lateralKd 25

#define angularKp 4
#define angularKi 0
#define angularKd 50

/*----------------------PROS INIT----------------------*/

//DriveTrain
inline pros::MotorGroup left_dr({PORT_left_dr_1,PORT_left_dr_2,PORT_left_dr_3});
inline pros::MotorGroup right_dr({PORT_right_dr_1,PORT_right_dr_2,PORT_right_dr_3});

//Mechanisms
inline pros::Motor intake(PORT_intake);
inline pros::Motor hook(PORT_hook);
inline pros::Motor lbMech(PORT_lbMech);

/*----------------------LEMLIB INIT----------------------*/

inline lemlib::Drivetrain drivetrain(&left_dr, &right_dr, 13, lemlib::Omniwheel::NEW_275, 450, 2);
inline lemlib::ControllerSettings lateral_controller(
											lateralKp, // proportional gain (kP)
											lateralKi, // integral gain (kI)
											lateralKd, // derivative gain (kD)
											3, // anti windup

											1, // small error range, in inches
											100, // small error range timeout, in milliseconds
											3, // large error range, in inches
											500, // large error range timeout, in milliseconds
											20 // maximum acceleration (slew)
);

inline lemlib::ControllerSettings angular_controller(
                                            angularKp, // proportional gain (kP)
                                            angularKi, // integral gain (kI)
                                            angularKd, // derivative gain (kD)
                                            3, // anti windup
                                            0, // small error range, in inches
                                            0, // small error range timeout, in milliseconds
                                            0, // large error range, in inches
                                            0, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);

#endif