#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "main.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "lemlib/api.hpp"
#include "sensor_loc.cpp"

/*----------------------Defines----------------------*/

// Constants
constexpr double PI = 3.141592;

/*---Controller---*/
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Controller master2(pros::E_CONTROLLER_PARTNER);

inline bool skills = false;
inline bool team = true;
inline bool driverControl = false, autonomousPeriod = false;
inline int auton = 1;
inline bool moveChassis = true;
inline bool isClimbing = false;
inline bool safeMode = false;
inline bool hookAtFullSpeed = false;
inline std::string LBState = "none";
inline std::string ringPos = "none";



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
    inline pros::ADIDigitalOut PTOPiston('D');    
    inline pros::ADIDigitalOut doinkerPiston('C');
}


namespace DriveTrain {
    inline pros::MotorGroup left({-8, -9, -10});
    inline pros::MotorGroup right({1, 2, 3});
    inline pros::Distance frontDS(99);
    inline pros::Distance backDS(99);
    inline pros::Distance rightDS(12);
    inline pros::Distance leftDS(18);
}

inline dist_sensor rightSensor = {&DriveTrain::rightDS, lemlib::Pose(5, 0, 90)};
inline dist_sensor leftSensor = {&DriveTrain::leftDS, lemlib::Pose(-5, 0, 270)};


namespace Manipulator {
    inline pros::Motor intakeMotor(21);

    inline pros::Optical colourSensor(5);
    inline pros::Distance distanceSensor(4);
}

namespace LadyBrownConfigs {
    struct PID {
        static constexpr double kP = 2;
        static constexpr double kI = 0.02;
        static constexpr double kD = 2;
        // static constexpr double kP = 0.7;
        // static constexpr double kI = 0;
        // static constexpr double kD = 0;
    };

    enum Setpoints {
        LOADING = 37,
        // LOADING = 25,
        HOLD = 60,
        SCORING = 165,
        ALLIANCE = 220,
        MOGOTIP = 250,
        NOCONTACTZONE = 60

    };
    inline double LBOFFSET = -140;
    inline double POT_TICK_2_DEGREE = 11.11;

    inline pros::ADIAnalogIn potentiometer('E');
    inline pros::MotorGroup motor({-19});
    inline lemlib::PID PID(PID::kP, PID::kI, PID::kD, 0, true);
}

namespace OdometryConfigs {
    struct PID {
        static constexpr double lateralKp = 5.0;
        static constexpr double lateralKi = 0.01;
        static constexpr double lateralKd = 30.0;
        static constexpr double angularKp = 3.2;
        static constexpr double angularKi = 0.01;
        static constexpr double angularKd = 40.0;
    };
    inline pros::Rotation vertical_TWL(6);
    inline pros::Rotation vertical_TWR(-13);
    inline pros::Imu IMU(7);

    inline lemlib::Drivetrain LEMLIB_drivetrain(&DriveTrain::left, &DriveTrain::right, 13, lemlib::Omniwheel::NEW_275, 450, 2);
    inline lemlib::TrackingWheel LEMLIB_vertical_TWL(&vertical_TWL, 2, -1.5);
    inline lemlib::TrackingWheel LEMLIB_vertical_TWR(&vertical_TWR, 2, 1.5);

    inline lemlib::OdomSensors LEMLIB_sensors(&LEMLIB_vertical_TWL, nullptr, nullptr, nullptr, &IMU);
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