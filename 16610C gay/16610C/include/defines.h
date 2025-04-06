#include "main.h"
#include "lemlib/api.hpp"
#include <list>

using namespace pros;
using namespace lemlib;


// controller
extern Controller master;

// drive motors + settings
extern MotorGroup l_mg; // left motor group
extern MotorGroup r_mg; // right motor group

extern Drivetrain drive; // drivetrain settings

// sub-system motors
extern Motor intake;
extern MotorGroup high;
// pneumatics
extern adi::DigitalOut clamp;
extern adi::DigitalOut wing;


// sensors
extern Imu imu;
extern Optical optical;
extern Distance dist;

extern ADIPotentiometer highPot;
extern ADIPotentiometer potmeterTop;
extern ADIPotentiometer potmeterBot;
extern Rotation v_track;


// odom + settings
extern adi::Encoder horz_enc; // horizontal encoder
extern adi::Encoder vert_enc; // vertical encoder

extern TrackingWheel horz_tc; // horizontal tracking wheel
extern TrackingWheel vert_tc; // vertical tracking wheel

extern OdomSensors odom; // odom settings

// PIDs
extern ControllerSettings lateral_controller; // lateral PID controller
extern ControllerSettings angular_controller; // angular PID controller

// chassis + settings
extern Chassis chassis; // chassis settings

extern ExpoDriveCurve t_curve; // throttle curve settings
extern ExpoDriveCurve s_curve; // steer curve settings

// drive.cpp
extern inline void drive_();
extern int leftY;
extern int rightX;

// intake.cpp
extern inline void intake_();
extern inline void intakeFun(void *param);
extern inline Task intakeTask(intakeFun, nullptr, TASK_PRIORITY_DEFAULT-2, TASK_STACK_DEPTH_DEFAULT, "lesbian");

extern bool unjamLB;
extern bool reject;
extern bool atTop;
extern bool colorSort;
extern bool holdTop;
extern int colorMin;
extern int colorMax;
extern int prevIntSpeed;

// high.cpp
extern inline void high_();
extern inline void highFun(void *param);
extern inline Task highTask(highFun, nullptr, TASK_PRIORITY_DEFAULT-1, TASK_STACK_DEPTH_DEFAULT, "gay");

extern PID highPID;
extern PID highPIDGay;
extern int highStat;
extern int prevHigh;
extern int dir;
extern int tar;
extern int base;
extern int tar0; // rest
extern int tar1; // load
extern int tar2; // hold
extern int tar3; // ws score
extern int tar4; // as score + tip
extern int tar5; // mg
extern int dt;
extern double kp;
extern double kd;

// clamp.cpp
extern inline void clamp_();
extern bool clampStat;

// misc.cpp
extern inline void misc_();
extern inline void printingFun(void *param);
extern inline Task printingTask(printingFun, nullptr, TASK_PRIORITY_DEFAULT-2, TASK_STACK_DEPTH_DEFAULT, "trans");

// auton.cpp
extern inline void moveTo(double x, double y, int t1, int t2, bool b1, bool b2);
extern inline void move(int speed);

extern inline void testCode();
extern inline void redPos();
extern inline void redNeg();
extern inline void bluePos();
extern inline void blueNeg();
extern inline void skills();

extern bool redSide;
extern bool posSide;
extern bool skill;

// color ranges
extern int redMin;
extern int redMax;
extern int blueMin;
extern int blueMax;


// randoms
extern bool wingStat;
extern int test;