#include "main.h"
#include "lemlib/api.hpp"
#include <thread>

using namespace pros;
using namespace lemlib;


// controller
Controller master(E_CONTROLLER_MASTER);

// drive motors + settings
MotorGroup l_mg({-1, 2, -3}, MotorGearset::blue); // fronts are reversed
MotorGroup r_mg({-4, 5, 6}, MotorGearset::blue); // fronts are reversed

Drivetrain drive(&l_mg, &r_mg, // left, right motor group
    11.5, // track width 12.6 inch
    Omniwheel::NEW_275, // wheel size is 2.75 inch
    450, // drive rpm is 400
    2 // horizontal slip is 2
);

// sub-system motors
Motor intake(15, MotorGearset::blue);
MotorGroup high({12, -13});

// pneumatics
ADIDigitalOut clamp('E');
ADIDigitalOut wing('D');

// sensors
Imu imu(20);
Optical optical(11);
Distance dist(14);

ADIPotentiometer highPot('F');
ADIPotentiometer potmeterTop('H'); 
ADIPotentiometer potmeterBot('G'); 
Rotation v_track(-7);

// ---------
TrackingWheel vert_tc(&v_track, // vertical encoder
                      2, // old 2 omniwheel
                      0 // offset of 0 inch
);

OdomSensors odom(&vert_tc, // vertical tracking wheel
                 nullptr, // using one vertical tracking wheel
                 nullptr, // horizontal tracking wheel
                 nullptr, // using one horizontal tracking wheel
                 &imu // imu
);

ControllerSettings lateral_controller(15,      // proportional gain (kP)
                                      0.76,      // integral gain (kI)
                                      95,      // derivative gain (kD)
                                      0.5725,      // anti windup 2,53
                                      0,      // small error range, in inches
                                      0,      // small error range timeout, in milliseconds
                                      0,      // large error range, in inches
                                      0,      // large error range timeout, in milliseconds
                                      0      // maximum acceleration (slew)
);

ControllerSettings angular_controller(2.5,      // proportional gain (kP)   2.5
                                      0.078,      // integral gain (kI)   0.1   0.078
                                      20.25,      // derivative gain (kD)    19.2
                                      38.88,      // anti windup 6.95   38.88
                                      0,      // small error range, in degrees
                                      0,      // small error range timeout, in milliseconds
                                      0,      // large error range, in degrees
                                      0,      // large error range timeout, in milliseconds
                                      0      // maximum acceleration (slew)
);

// create chassis
Chassis chassis(drive, // drive settings
                lateral_controller, // lateral PID settings
                angular_controller, // angular PID settings
                odom, // odom sensors
                &t_curve, // throttle curve
                &s_curve // steer curve
);

ExpoDriveCurve t_curve(3, // joystick deadband out of 127
                       3, // minimum output where drivetrain will move out of 127
                       1 // expo curve gain
);

ExpoDriveCurve s_curve(3, // joystick deadband out of 127
                       3, // minimum output where drivetrain will move out of 127
                       1.01 // expo curve gain
);

// drive.cpp
int rightX = 0;
int leftY = 0;

// intake.cpp
bool unjamLB = false;
bool reject = false;
bool atTop = false;
bool colorSort = true;
bool holdTop = false;
int colorMin;
int colorMax;
int prevIntSpeed;

// high.cpp
PID highPID(kp, 0, kd);
PID highPIDGay(0.21, 0, 0);
int highStat = 0;
int prevHigh = 0;

int dir = -1;
int tar;
int base = 3800;
int tar0 = base-100; // rest
int tar1 = base-450; // load
int tar2 = base-800; // hold
int tar3 = base-2000; // ws score
int tar4 = base-2600; // as score + tip
int tar5 = base-3000; // mg
int dt = 20;
double kp = 0.3;
double kd = 0.62;
// double kp = 0.21;
// double kd = 0;

// clamp.cpp
bool clampStat = false;

// auton.cpp
bool posSide = false; // false = negative, true = positive
bool redSide = false; // false = blue, true = red
bool skill = false;

// color ranges
int redMin = 0;
int redMax = 40;
int blueMin = 140;
int blueMax = 220;

// randoms
bool wingStat = false;
int test = 90; // angle for turning when testing gyro