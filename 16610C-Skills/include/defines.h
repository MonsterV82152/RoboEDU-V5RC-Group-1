#include "main.h"
#include "lemlib/api.hpp"
#include <list>

using namespace pros;
using namespace lemlib;

ASSET(bottomstart_txt)
ASSET(abcdefg_txt)

// controller
extern Controller master;

// drive motors + settings
extern MotorGroup l_mg; // left motor group
extern MotorGroup r_mg; // right motor group

extern Drivetrain drive; // drivetrain settings

// sub-system motors
extern Motor lift;
extern Motor intake;

// pneumatics
extern adi::DigitalOut clamp;
extern adi::DigitalOut pto;


// sensors
extern Imu imu;
extern Optical optical;
extern ADIPotentiometer potmeter;
extern ADIDigitalIn top_switch;
extern Rotation test;

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
extern inline void colorCheck(void *param);
extern inline void intakeMode(void *param);
extern inline void liftFun(void *param);
extern inline void clampFun(void *param);
extern inline void ptoFun(void *param);


// extern inline Task intakeTask(colorCheck, nullptr, TASK_PRIORITY_MIN+3, TASK_STACK_DEPTH_DEFAULT, "gay");
// extern inline Task highIntakeTask(intakeMode, nullptr, TASK_PRIORITY_MIN+4, TASK_STACK_DEPTH_DEFAULT, "lesbian");
extern inline Task liftTask(liftFun, nullptr, TASK_PRIORITY_MIN+6, TASK_STACK_DEPTH_DEFAULT, "trans");
// extern inline Task clampTask(clampFun, nullptr, TASK_PRIORITY_MIN+5, TASK_STACK_DEPTH_DEFAULT, "bi");
// extern inline Task ptoTask(ptoFun, nullptr, TASK_PRIORITY_MIN+1, TASK_STACK_DEPTH_DEFAULT, "pan");


extern bool intakeStat;
extern bool intakeDir;
extern int colorMin;
extern int colorMax;
extern bool hasIntakeThread;

// lift.cpp
extern inline void lift_();
extern int liftStat;

// pto.cpp
extern inline void pto_();
extern bool ptoStat;

// clamp.cpp
extern inline void clamp_();
extern bool clampStat;

// misc.cpp
extern inline void misc_();

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

// color ranges
extern int redMin;
extern int redMax;
extern int blueMin;
extern int blueMax;


// randoms
extern std::list<double> xs;
extern std::list<double> ys;
extern std::list<double> ts;
extern double t;
extern int liftState; // 0 down, 1 low, 2 med, 3 top
extern bool hasStart;