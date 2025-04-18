#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "main.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "lemlib/api.hpp"
#include "sensor_loc.cpp"

/*----------------------Defines----------------------*/

// Constants
constexpr double PI = 3.141592;
inline bool skill = false;
/*---Controller---*/
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Controller master2(pros::E_CONTROLLER_PARTNER);

inline bool team = true;
inline bool driverControl = false, autonomousPeriod = false;
inline int user = 0;
inline int auton = 1;
inline bool driverTrain = true;



namespace Controller {
    constexpr auto button_R1 = pros::E_CONTROLLER_DIGITAL_R1;
    constexpr auto button_R2 = pros::E_CONTROLLER_DIGITAL_R2;
    constexpr auto button_L1 = pros::E_CONTROLLER_DIGITAL_L1;
    constexpr auto button_L2 = pros::E_CONTROLLER_DIGITAL_L2;
    constexpr auto button_A = pros::E_CONTROLLER_DIGITAL_A;
    constexpr auto button_B = pros::E_CONTROLLER_DIGITAL_B;
    constexpr auto button_Y = pros::E_CONTROLLER_DIGITAL_Y;
    constexpr auto button_X = pros::E_CONTROLLER_DIGITAL_X;
    constexpr auto button_UP = pros::E_CONTROLLER_DIGITAL_UP;
    constexpr auto button_DOWN = pros::E_CONTROLLER_DIGITAL_DOWN;
    constexpr auto button_LEFT = pros::E_CONTROLLER_DIGITAL_LEFT;
    constexpr auto button_RIGHT = pros::E_CONTROLLER_DIGITAL_RIGHT;
}

namespace MotorConfigs {
    constexpr auto BRAKE = pros::E_MOTOR_BRAKE_BRAKE;
    constexpr auto COAST = pros::E_MOTOR_BRAKE_COAST;
    constexpr auto HOLD = pros::E_MOTOR_BRAKE_HOLD;
}

namespace Pneumatics {
    inline pros::ADIDigitalOut mogoClampPiston('E');
    inline pros::ADIDigitalOut ladyBrownPiston('G');
    inline pros::ADIDigitalOut PTOPiston('A');
    inline pros::ADIDigitalOut doinkerPiston('D');
}


namespace DriveTrain {
    inline pros::MotorGroup left({-1, 2, -3});
    inline pros::MotorGroup right({-4, 5, 6});
    inline pros::Distance frontDS(17);
    // inline pros::Distance backDS(99);
    // inline pros::Distance rightDS(99);
    inline pros::Distance leftDS(16);
}
inline pros::ADIPotentiometer potmeterBot('G');

inline dist_sensor frontSensor = {&DriveTrain::frontDS, lemlib::Pose(-5, 2.5, 0)};
inline dist_sensor leftSensor = {&DriveTrain::leftDS, lemlib::Pose(-6, 0, 270)};

namespace Manipulator {
    inline pros::Motor intakeMotor(-15);

    inline pros::Optical colourSensor(11);
    inline pros::Distance dist(14);
}

namespace LadyBrownConfigs {
    struct PID {
        static constexpr double kP = 1;
        static constexpr double kI = 0;
        static constexpr double kD = 0;
    };

    enum Setpoints {
        LOADING = 35,
        HOLD = 60,
        SCORING = 170,
        ALLIANCE = 200,
        DESCORE1 = 170,
        DESCORE2 = 180,
        DESCORE3 = 190,
        DESCORE4 = 205,
        DESCORE5 = 215,
        NOCONTACTZONE = 60
    };
    inline double LBOFFSET = -300;
    inline double POT_TICK_2_DEGREE = 12;

    inline pros::ADIAnalogIn potentiometer('F');
    inline pros::MotorGroup motor({12,-13});
    inline lemlib::PID PID(PID::kP, PID::kI, PID::kD);
}

namespace OdometryConfigs {
    inline pros::Rotation vertical_TWL(-7);
    inline pros::Imu IMU(20);

    inline lemlib::Drivetrain LEMLIB_drivetrain(&DriveTrain::left, &DriveTrain::right, 11.5, lemlib::Omniwheel::NEW_275, 450, 2);
    inline lemlib::TrackingWheel LEMLIB_vertical_TWL(&vertical_TWL, 2, 0);

    inline lemlib::OdomSensors LEMLIB_sensors(&LEMLIB_vertical_TWL, nullptr, nullptr, nullptr, &IMU);
    inline lemlib::ControllerSettings LEMLIB_lateral_controller(15,      // proportional gain (kP)
        0.76,      // integral gain (kI)
        95,      // derivative gain (kD)
        0.5725,      // anti windup 2,53
        0,      // small error range, in inches
        0,      // small error range timeout, in milliseconds
        0,      // large error range, in inches
        0,      // large error range timeout, in milliseconds
        0      // maximum acceleration (slew)
    );

    inline lemlib::ControllerSettings LEMLIB_angular_controller(
        2.5,      // proportional gain (kP)   2.5
        0.078,      // integral gain (kI)   0.1   0.078
        20.25,      // derivative gain (kD)    19.2
        38.88,      // anti windup 6.95   38.88
        0,      // small error range, in degrees
        0,      // small error range timeout, in milliseconds
        0,      // large error range, in degrees
        0,      // large error range timeout, in milliseconds
        0      // maximum acceleration (slew)
    );
}
inline lemlib::Chassis chassis(OdometryConfigs::LEMLIB_drivetrain,         // drivetrain settins
                               OdometryConfigs::LEMLIB_lateral_controller, // lateral PID settings
                               OdometryConfigs::LEMLIB_angular_controller, // angular PID settings
                               OdometryConfigs::LEMLIB_sensors             // odometry sensors
);

/*----------------------LEMLIB INIT----------------------*/



#endif