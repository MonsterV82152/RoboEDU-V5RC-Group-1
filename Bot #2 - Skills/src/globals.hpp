#include "main.h"

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

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
#define PORT_right_dr_1 1
#define PORT_right_dr_2 -2
#define PORT_right_dr_3 3

#define PORT_left_dr_1 -4
#define PORT_left_dr_2 5
#define PORT_left_dr_3 -6

//Mechanisms
#define PORT_intake 7
#define PORT_hook 8
#define PORT_lbMech -9

//Pnuematics
#define PORT_mogo_clamp 'A'
#define PORT_wing 'B'

//Sensors
#define PORT_lbRotation 10

#define PORT_IMU 14
#define PORT_Vertical_TW 12
#define PORT_Colour 13

//Lady Brown

#define lbfirst 32
#define lbsecond 130
#define lbthird 150

/*---PID Values---*/

#define lateralKp 10
#define lateralKi 0
#define lateralKd 0

#define angularKp 5.95
#define angularKi 0
#define angularKd 70

/*----------------------GLOBAL VARIABLES----------------------*/

bool SelectedTeam = true;
int SelectedAuton = 5, user = 0;;

int left_controller_position_Y, left_controller_position_X, right_controller_position_Y, right_controller_position_X;
int p_left_controller_position_Y, p_left_controller_position_X, p_right_controller_position_Y, p_right_controller_position_X;

int intakeSpeed = 0, hookSpeed = 0, hookOverwriteSpeed = 0, intakeOverwriteSpeed = 0;
bool hookIntake = false;

int intakeDefaultSpeed = 127, hookDefaultSpeed = 127;

int LadyBrownState = 0;

double LadyBrownPosition;

bool BOOL_mogo_clamp = false, BOOL_wing = false;

bool driverControl = false;

int mogoOverwriteCountdown = 20;

int unjamCountdown = 10, unjamCooldown = 20;

int colourSorterCountdown = 8, colourSorterCooldown = 20;

int currentColour = 0;

bool loadedRing = false;

/*----------------------PROS INIT----------------------*/

ASSET(skillsV21_txt)

//DriveTrain
inline pros::MotorGroup left_dr({PORT_left_dr_1,PORT_left_dr_2,PORT_left_dr_3});
inline pros::MotorGroup right_dr({PORT_right_dr_1,PORT_right_dr_2,PORT_right_dr_3});

//Mechanisms
inline pros::Motor intake(PORT_intake);
inline pros::Motor hook(PORT_hook);
inline pros::Motor lbMech(PORT_lbMech);

//Pnuematics
inline pros::ADIDigitalOut mogo_clamp(PORT_mogo_clamp);
inline pros::ADIDigitalOut wing(PORT_wing);

//Controller
inline pros::Controller master(driver);
inline pros::Controller master2(driver_2);

//Sensors
inline pros::Rotation lbRotation(PORT_lbRotation);

inline pros::Imu IMU(PORT_IMU);
inline pros::Rotation vertical_TW(PORT_Vertical_TW);
inline pros::Optical colour(PORT_Colour);

/*----------------------LEMLIB INIT----------------------*/

inline lemlib::Drivetrain LEMLIB_drivetrain(&left_dr, &right_dr, 13, lemlib::Omniwheel::NEW_275, 450, 2);
inline lemlib::TrackingWheel LEMLIB_vertical_TW(&vertical_TW, lemlib::Omniwheel::NEW_2, 0.75);

inline lemlib::OdomSensors LEMLIB_sensors(&LEMLIB_vertical_TW, nullptr, nullptr, nullptr, &IMU);

inline lemlib::ControllerSettings LEMLIB_lateral_controller(
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

inline lemlib::ControllerSettings LEMLIB_angular_controller(
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

inline lemlib::Chassis chassis(LEMLIB_drivetrain, // drivetrain settins
                        LEMLIB_lateral_controller, // lateral PID settings
                        LEMLIB_angular_controller, // angular PID settings
                        LEMLIB_sensors // odometry sensors
);



#endif