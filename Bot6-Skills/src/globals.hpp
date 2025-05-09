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
#include "feedForward.hpp"

/*----------------------Defines----------------------*/

// Constants
constexpr double PI = 3.141592;

/*---Controller---*/
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Controller master2(pros::E_CONTROLLER_PARTNER);

inline int bot = 2;
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
    inline pros::ADIDigitalOut mogoClampPiston('C'); // BOT 1 - 'A', BOT 2 - 'H'
    inline pros::ADIDigitalOut ladyBrownPiston('B'); // BOT 1 - 'B', BOT 2 - 'E'
    inline pros::ADIDigitalOut PTOPiston('E'); // BOT 1 - 'D', BOT 2 - 'F'
    inline pros::ADIDigitalOut doinkerPiston('D'); // BOT 1 - 'C', BOT 2 - 'C'
}


namespace DriveTrain {
    inline pros::MotorGroup left({-17, -18, -20}); // BOT 1 - {-8, -9, -10}, BOT 2 - {-18, -19, -20}
    inline pros::MotorGroup right({12, 13, 14}); // BOT 1 - {1, 2, 3}, BOT 2 - {11, 12, 13}
    inline pros::Distance frontDS(99);
    inline pros::Distance backDS(99);
    inline pros::Distance rightDS(1); // BOT 1 - 12
    inline pros::Distance leftDS(10); // BOT 1 - 18
}

inline dist_sensor rightSensor = {&DriveTrain::rightDS, lemlib::Pose(5, 0, 90)};
inline dist_sensor leftSensor = {&DriveTrain::leftDS, lemlib::Pose(-5, 0, 270)};


namespace Manipulator {
    inline pros::Motor intakeMotor(19); // BOT 1 - 21, BOT 2 - 9

    inline pros::Optical colourSensor(99);
    inline pros::Distance distanceSensor(9);
}

namespace LadyBrownConfigs {
    struct PID {
        static constexpr double kP = 1.45;
        static constexpr double kI = 0.01;
        static constexpr double kD = 1.2;
        static constexpr double kG = 18;
        static constexpr double kA = 0;
        static constexpr double kV = 0;
        
        // static constexpr double kP = 0.7;
        // static constexpr double kI = 0;
        // static constexpr double kD = 0;
    };

    enum Setpoints {
        LOADING = 37,
        // LOADING = 25,
        HOLD = 60,
        TEST = 120,
        SCORING = 165,
        ALLIANCE = 220,
        MOGOTIP = 250,
        NOCONTACTZONE = 60

    };
    inline double LBOFFSET = -70;
    inline double POT_TICK_2_DEGREE = 10.2;
    inline double LB_HORIZONTAL = 30;

    inline pros::ADIAnalogIn potentiometer('A'); // BOT 1 - 'E', BOT 2 - 'D'
    inline pros::MotorGroup motor({-21}); // BOT 1 - {-9}, BOT 2 - {-10}
    inline ArmFeedForward feedForward(PID::kG);
    inline lemlib::PID PID(PID::kP, PID::kI, PID::kD, 0, true);
}

namespace OdometryConfigs {
    struct PID {
        static constexpr double lateralKp = 5.0;
        static constexpr double lateralKi = 0.01;
        static constexpr double lateralKd = 25.0;
        static constexpr double angularKp = 3.2;
        static constexpr double angularKi = 0.01;
        static constexpr double angularKd = 40.0;
    };
    inline pros::Rotation vertical_TWL(-11);
    // inline pros::Rotation vertical_TWR(-13);
    inline pros::Imu IMU(16);

    inline lemlib::Drivetrain LEMLIB_drivetrain(&DriveTrain::left, &DriveTrain::right, 13, lemlib::Omniwheel::NEW_275, 450, 2);
    inline lemlib::TrackingWheel LEMLIB_vertical_TWL(&vertical_TWL, 2, 0);
    // inline lemlib::TrackingWheel LEMLIB_vertical_TWR(&vertical_TWR, 2, 1.5);

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