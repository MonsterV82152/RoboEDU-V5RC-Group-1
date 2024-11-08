#include "main.h"
#include "lemlib/api.hpp"
#include <thread>

using namespace pros;
using namespace lemlib;

// controller
Controller master(E_CONTROLLER_MASTER);

// drive motors + settings
MotorGroup l_mg({-1, 2, -3}, MotorGearset::blue); // left motor group
MotorGroup r_mg({4, -5, 6}, MotorGearset::blue); // right motor group

Drivetrain drive(&l_mg, &r_mg, // left, right motor group
                 12.6, // track width 12.6 inch
                 Omniwheel::OLD_325, // wheel size is 3.25 inch
                 400, // drive rpm is 400
                 2 // horizontal slip is 2
);

// sub-system motors
Motor lift(21, MotorGearset::red);
Motor intake(7, MotorGearset::blue);

// pneumatics
ADIDigitalOut clamp('A');
ADIDigitalOut pto('B');


// sensors
Imu imu(10);
Optical optical(14);
ADIPotentiometer potmeter('H');
ADIDigitalIn top_switch('G');      
Rotation test(9); 


// encoder + settings
// adi::Encoder horz_enc('C', 'D', true); // horizontal encoder
// adi::Encoder vert_enc('E', 'F', true); // vertical encoder

// TrackingWheel horz_tc(&horz_enc, // horizontal encoder
//                       Omniwheel::OLD_275_HALF, // old halfcut 2.75 omniwheel
//                       0.75 // offset of 0.75 inch
// );

TrackingWheel vert_tc(&test, // vertical encoder
                      2, // old halfcut 2.75 omniwheel
                      0.375 // offset of 0.375 inch
);

OdomSensors odom(&vert_tc, // vertical tracking wheel
                 nullptr, // using one vertical tracking wheel
                 nullptr, // horizontal tracking wheel
                 nullptr, // using one horizontal tracking wheel
                 &imu // imu
);

// PIDs
// ControllerSettings lateral_controller(20,      // proportional gain (kP)
//                                       0,      // integral gain (kI)
//                                       3,      // derivative gain (kD)
//                                       3,      // anti windup
//                                       1,      // small error range, in inches
//                                       100,      // small error range timeout, in milliseconds
//                                       3,      // large error range, in inches
//                                       500,      // large error range timeout, in milliseconds
//                                       50      // maximum acceleration (slew)
// );

// test code for tuning 10 65
// 30 330
ControllerSettings lateral_controller(5,      // proportional gain (kP)
                                      0.2,      // integral gain (kI)
                                      20,      // derivative gain (kD)
                                      1.275,      // anti windup
                                      0,      // small error range, in inches
                                      0,      // small error range timeout, in milliseconds
                                      0,      // large error range, in inches
                                      0,      // large error range timeout, in milliseconds
                                      3      // maximum acceleration (slew)
);


// ControllerSettings lateral_controller(5,      // proportional gain (kP)
//                                       1,      // integral gain (kI)
//                                       20,      // derivative gain (kD)
//                                       1.275,      // anti windup
//                                       0,      // small error range, in inches
//                                       0,      // small error range timeout, in milliseconds
//                                       0,      // large error range, in inches
//                                       0,      // large error range timeout, in milliseconds
//                                       2.5      // maximum acceleration (slew)
// );




ControllerSettings angular_controller(2,      // proportional gain (kP)
                                      0,      // integral gain (kI)
                                      13.7,      // derivative gain (kD)
                                      0,      // anti windup
                                      0,      // small error range, in degrees
                                      0,      // small error range timeout, in milliseconds
                                      0,      // large error range, in degrees
                                      0,      // large error range timeout, in milliseconds
                                      0      // maximum acceleration (slew)
);




// test code for tuning
// ControllerSettings angular_controller(3,      // proportional gain (kP)
//                                       1,      // integral gain (kI)
//                                       18.376,      // derivative gain (kD)
//                                       0.75,      // anti windup
//                                       0,      // small error range, in degrees
//                                       0,      // small error range timeout, in milliseconds
//                                       0,      // large error range, in degrees
//                                       0,      // large error range timeout, in milliseconds
//                                       0      // maximum acceleration (slew)
// );


// create chassis
Chassis chassis(drive, // drive settings
                lateral_controller, // lateral PID settings
                angular_controller, // angular PID settings
                odom, // odom sensors
                &t_curve, // throttle curve
                &s_curve // steer curve
);

ExpoDriveCurve t_curve(15, // joystick deadband out of 127
                       10, // minimum output where drivetrain will move out of 127
                       1.1 // expo curve gain
);

ExpoDriveCurve s_curve(15, // joystick deadband out of 127
                       10, // minimum output where drivetrain will move out of 127
                       1.1 // expo curve gain
);



// .cpp
bool intakeStat = false;
bool intakeDir = false;
bool ptoStat = false;
bool clampStat = false;
int liftStat = 0;
int rightX = 0;
int leftY = 0;
int colorMin;
int colorMax;
bool hasIntakeThread = false;
bool posSide = false; // false = negative, true = positive
bool redSide = false; // false = blue, true = red
int liftState = 1;
bool hasStart = false;

// color values
int redMin = 0;
int redMax = 20;
int blueMin = 180;
int blueMax = 240;

