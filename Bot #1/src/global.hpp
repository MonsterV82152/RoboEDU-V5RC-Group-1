#include "main.h"
#include "odometry.h"
#include <string>
#include <stdlib.h> 


// Constants
#define PI 3.14159265
#define wheel


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



pros::Imu imu_sensor(IMUport);
pros::Rotation verticaltracking(20);
pros::Rotation horizontaltracking(4);
verticaltracking.reset();
horizontaltracking.reset();
verticaltracking.set_position(0);
horizontaltracking.set_position(0);
imu_sensor.reset();
pros::delay(2000);
odom thisbot(0,0,0,0,0,1.375);


pros::ADIDigitalOut clawp (clawport);
pros::ADIDigitalOut wing (wingport);
pros::Motor intake(2); 
pros::Motor hook(-8);
pros::Motor swall(15);
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller master2(pros::E_CONTROLLER_PARTNER);
pros::MotorGroup right_mg({12, -10, 6});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
pros::MotorGroup left_mg({-14, 18, -16});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6
