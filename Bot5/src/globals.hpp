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
constexpr double PI = 3.141592;

/*---Controller---*/
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Controller master2(pros::E_CONTROLLER_PARTNER);

inline bool team = true;
inline bool driverControl = false, autonomousPeriod = false;
inline int user = 0;
inline int auton = 1;



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
    inline pros::ADIDigitalOut mogoClampPiston('A');
    inline pros::ADIDigitalOut ladyBrownPiston('B');
    inline pros::ADIDigitalOut PTOPiston('C');
    inline pros::ADIDigitalOut doinkerPiston('D');
}


namespace DriveTrain {
    inline pros::MotorGroup left({-11, -13, 17});
    inline pros::MotorGroup right({14, 15, 16});
}

namespace Manipulator {
    inline pros::Motor intakeMotor(10);

    inline pros::Optical colourSensor(99);
}

namespace LadyBrownConfigs {
    struct PID {
        static constexpr double kP = 2;
        static constexpr double kI = 0;
        static constexpr double kD = 5;
    };

    enum Setpoints {
        LOADING = 16,
        LOADING2 = 0,
        SCORING = 125,
        SCORING2 = 0,
        NOCONTACTZONE = 60
    };
    inline double LBOFFSET = 0;

    inline pros::ADIAnalogIn potentiometer('Z');
    inline pros::MotorGroup motor({99});
    inline lemlib::PID PID(PID::kP, PID::kI, PID::kD);
}

namespace OdometryConfigs {
    struct PID {
        static constexpr double lateralKp = 3.0;
        static constexpr double lateralKi = 0.0;
        static constexpr double lateralKd = 0.0;
        static constexpr double angularKp = 3.5;
        static constexpr double angularKi = 0.01;
        static constexpr double angularKd = 50.0;
    };
    inline pros::Rotation vertical_TWL(9);
    inline pros::Rotation vertical_TWR(8);
    inline pros::Imu IMU(11);

    inline lemlib::Drivetrain LEMLIB_drivetrain(&DriveTrain::left, &DriveTrain::right, 13, lemlib::Omniwheel::NEW_275, 450, 2);
    inline lemlib::TrackingWheel LEMLIB_vertical_TWL(&vertical_TWL, 2, -1.25);
    inline lemlib::TrackingWheel LEMLIB_vertical_TWR(&vertical_TWR, 2, -1.25);

    inline lemlib::OdomSensors LEMLIB_sensors(&LEMLIB_vertical_TWL, &LEMLIB_vertical_TWR, nullptr, nullptr, &IMU);
    inline lemlib::ControllerSettings LEMLIB_lateral_controller(
        PID::lateralKp, // proportional gain (kP)
        PID::lateralKi, // integral gain (kI)
        PID::lateralKd, // derivative gain (kD)
        3,         // anti windup

        1,   // small error range, in inches
        100, // small error range timeout, in milliseconds
        3,   // large error range, in inches
        500, // large error range timeout, in milliseconds
        20   // maximum acceleration (slew)
    );

    inline lemlib::ControllerSettings LEMLIB_angular_controller(
        PID::angularKp, // proportional gain (kP)
        PID::angularKi, // integral gain (kI)
        PID::angularKd, // derivative gain (kD)
        0,         // anti windup
        0,         // small error range, in inches
        0,         // small error range timeout, in milliseconds
        0,         // large error range, in inches
        0,         // large error range timeout, in milliseconds
        0          // maximum acceleration (slew)
    );
}
inline lemlib::Chassis chassis(OdometryConfigs::LEMLIB_drivetrain,         // drivetrain settins
                               OdometryConfigs::LEMLIB_lateral_controller, // lateral PID settings
                               OdometryConfigs::LEMLIB_angular_controller, // angular PID settings
                               OdometryConfigs::LEMLIB_sensors             // odometry sensors
);

/*----------------------LEMLIB INIT----------------------*/



#endif