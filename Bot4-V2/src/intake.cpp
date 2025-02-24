#include "globals.hpp"

#ifndef INTAKE_CPP
#define INTAKE_CPP

class Intake {
    private:
        pros::Motor intake;
        double defaultSpeed;
        double currentSpeed;
        double overwriteSpeed;
        double overwriteCountdown;
        bool isOverwrite;
        bool isMoving;
    public:
        Intake() 
        :   intake(PORT_intake),
            defaultSpeed(0),
            currentSpeed(0),
            overwriteSpeed(0),
            overwriteCountdown(0),
            isOverwrite(false),
            isMoving(false)

        {}
        void init() {
            intake.set_brake_mode(COAST);
            intake.set_gearing(MOTOR_GEAR_GREEN);
            intake.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        }
        void setSpeed(double speed) {
            defaultSpeed = speed;
        }
        void setOverwriteSpeed(double speed, int countdown) {
            overwriteSpeed = speed;
            overwriteCountdown = countdown;
            isOverwrite = true;
        }
        void update() {
            if (isOverwrite) {
                if (overwriteCountdown > 0) {
                    overwriteCountdown = overwriteCountdown - cycleSpeeds;
                    intake.move(overwriteSpeed);
                } else {
                    isOverwrite = false;
                }
            } else {
                intake.move(defaultSpeed);
            }
            currentSpeed = intake.get_actual_velocity();
            if (abs(currentSpeed) > 5) {
                isMoving = true;
            } else {
                isMoving = false;
            }
        }
        bool getIsMoving() {
            return isMoving;
        }
        double getSpeed() {
            return currentSpeed;
        }
        double getOverwriteSpeed() {
            if (isOverwrite) {
                return overwriteSpeed;
            } else {
                return 0;
            }
        }
        double getDefaultSpeed() {
            return defaultSpeed;
        }
        void stop() {
            defaultSpeed = 0;
        }
};


#endif