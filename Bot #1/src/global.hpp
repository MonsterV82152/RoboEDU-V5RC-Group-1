#include "main.h"
#include "odometry.h"
#include <string>
#include <stdlib.h>

/* ------------------------------------------------------------------------------------------------------------------------ */
// All #Defines


// Constants
#define PI 3.14159265
#define TWradius 1.375
#define driver pros::E_CONTROLLER_MASTER
#define driver_2 pros::E_CONTROLLER_PARTNER


// Pnumatic Ports
#define clawport 'H'
#define wingport 'E'


// Mechanism Motors
#define RIport 2
#define HSMport -8
#define WSSMport 15


// Drivetrain Motors
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

/* ------------------------------------------------------------------------------------------------------------------------ */
// Sensors & Calibration
pros::Imu imu_sensor(IMUport);
pros::Rotation verticaltracking(VTWport);
pros::Rotation horizontaltracking(HTWport);
verticaltracking.reset();
horizontaltracking.reset();
verticaltracking.set_position(0);
horizontaltracking.set_position(0);
imu_sensor.reset();
pros::delay(2000);

// Motors & Pnumatics

pros::ADIDigitalOut clawp(clawport);
pros::ADIDigitalOut wing(wingport);

pros::Motor intake(RIport);
pros::Motor hook(HSMport);
pros::Motor swall(HSSMport);

pros::MotorGroup right_mg({right_motor_1, right_motor_2, right_motor_3});
pros::MotorGroup left_mg({left_motor_1, left_motor_2, left_motor_3});

// Controllers

pros::Controller master(driver);
pros::Controller master2(driver_2);