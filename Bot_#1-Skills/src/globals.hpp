#include "main.h"
#include <cmath>



#ifndef CONFIG_HPP
#define CONFIG_HPP



#include <string>
#include <stdlib.h>
#include <iostream>
#include "lemlib/api.hpp"
#include "MovFunc.hpp"

/* ------------------------------------------------------------------------------------------------------------------------ */
// All #Defines

// Master Control for All Bot Functions
inline MasterControl bot(false, true, 0);

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
#define clawport 'E'
#define wingport 'H'


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

#define DS 11

//PID Values
//Odom Pid
#define odomKp 5
#define odomKi 0
#define odomKd 25

//4,25

#define turnKp 4
#define turnKi 0
#define turnKd 50

//Team
inline bool team = true;

inline int autonselector = 5;

inline int HookSpeed = 0;

inline bool slow = false;

inline int step = 0;


/* --------------- s--------------------------------------------------------------------------------------------------------- */
// Sensors & Calibration
inline pros::Imu imu_sensor(IMUport);
inline pros::Rotation vertical_tracking(VTWport);
inline pros::Rotation horizontal_tracking(HTWport);
inline pros::Optical optical_sensor(17);
inline pros::Rotation rotate(DS);

// Motors & Pnumatics

inline pros::ADIDigitalOut clawp(clawport);
inline pros::ADIDigitalOut wing(wingport);

inline pros::Motor intakeMotor(RIport);
inline pros::Motor hookMotor(HSMport);
inline pros::Motor swallMotor(WSSMport);

inline pros::MotorGroup left_dr({left_motor_1,left_motor_2,left_motor_3});
inline pros::MotorGroup right_dr({right_motor_1,right_motor_2,right_motor_3});




// Controllers

inline pros::Controller master(driver);
inline pros::Controller master2(driver_2);


// Lemlib Initialization
inline lemlib::Drivetrain drivetrain(&left_dr, &right_dr, 13, lemlib::Omniwheel::NEW_325, 360, 2);
inline lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_tracking, lemlib::Omniwheel::NEW_2, -2);
inline lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracking, 2 , 1.5);
inline lemlib::OdomSensors sensors(&vertical_tracking_wheel, nullptr, &horizontal_tracking_wheel, nullptr, &imu_sensor);
inline lemlib::ControllerSettings lateral_controller(
											odomKp, // proportional gain (kP)
											odomKi, // integral gain (kI)
											odomKd, // derivative gain (kD)
											3, // anti windup

											1, // small error range, in inches
											100, // small error range timeout, in milliseconds
											3, // large error range, in inches
											500, // large error range timeout, in milliseconds
											20 // maximum acceleration (slew)
);
inline lemlib::ControllerSettings angular_controller(turnKp, // proportional gain (kP)
                                              turnKi, // integral gain (kI)
                                              turnKd, // derivative gain (kD)
                                              3, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
inline lemlib::Chassis chassis(drivetrain, // drivetrain settins
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);



// inline lemlib::ExitCondition ec(0.1, 1000);


template <typename T> constexpr T sgn(T value) { return value < 0 ? -1 : 1; }


#endif 