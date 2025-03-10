#include "globals.hpp"

#ifndef HOOK_CPP
#define HOOK_CPP

class Hook {
    private:
        pros::Motor *hook;
        double defaultSpeed;
        double currentSpeed;
        double overwriteSpeed;
        double timeOverwriteSpeed;
        double overwriteCountdown;
        bool isTimeOverwrite;
        bool isOverwrite;
        bool isMoving;
    public:
        Hook(pros::Motor *hookMotor) 
        :   hook(hookMotor),
            defaultSpeed(0),
            currentSpeed(0),
            overwriteSpeed(0),
            timeOverwriteSpeed(0),
            overwriteCountdown(0),
            isTimeOverwrite(false),
            isOverwrite(false),
            isMoving(false)

        {}
        void init() {
            hook->set_brake_mode(MotorConfigs::COAST);
            hook->set_gearing(MOTOR_GEAR_GREEN);
            hook->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        }
        void setSpeed(double speed) {
            defaultSpeed = speed;
        }
        void setOverwriteSpeed(double speed, int countdown = 0) {
            if (countdown == 0) {
                overwriteSpeed = speed;
                isOverwrite = true;
            } else {
                timeOverwriteSpeed = speed;
                overwriteCountdown = countdown;
                isTimeOverwrite = true;
            }
        }
        void clearOverwrite() {
            overwriteSpeed = 0;
            isOverwrite = false;
        }
        void clearAllOverwrites() {
            overwriteSpeed = 0;
            timeOverwriteSpeed = 0;
            isOverwrite = false;
            isTimeOverwrite = false;
        }
        void update() {
            if (isTimeOverwrite) {
                if (overwriteCountdown > 0) {
                    overwriteCountdown--;
                    hook->move(timeOverwriteSpeed);
                } else {
                    isTimeOverwrite = false;
                }
            } else if (isOverwrite) {
                hook->move(overwriteSpeed);
            } else {
                hook->move(defaultSpeed);
            }
            currentSpeed = hook->get_actual_velocity();
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
            if (isTimeOverwrite) {
                return timeOverwriteSpeed;
            } else if (isOverwrite) {
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