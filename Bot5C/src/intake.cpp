#ifndef INTAKE_CPP
#define INTAKE_CPP

#include "globals.hpp"

class Intake {
    private:
        pros::Motor *intake;
        double defaultSpeed;
        double overwriteSpeed;
        double timeOverwriteSpeed;
        double overwriteCountdown;
        bool isTimeOverwrite;
        bool isOverwrite;
    public:
        Intake(pros::Motor *intakeMotor) 
        :   intake(intakeMotor),
            defaultSpeed(0),
            overwriteSpeed(0),
            timeOverwriteSpeed(0),
            overwriteCountdown(0),
            isTimeOverwrite(false),
            isOverwrite(false)
        {}
        void init() {
            intake->set_brake_mode(MotorConfigs::COAST);
            intake->set_gearing(MOTOR_GEAR_GREEN);
            intake->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/

        void setSpeed(double speed) {
            if (!isOverwrite && !isTimeOverwrite) {
                intake->move(speed);
            }
            defaultSpeed = speed;
        }
        void stop() {
            setSpeed(0);
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/
        
        void setOverwriteSpeed(double speed, int countdown) {
            pros::Task([&]() {
                isTimeOverwrite = true;
                timeOverwriteSpeed = speed;
                intake->move(speed);
                while (countdown > 0 && isTimeOverwrite) {
                    pros::delay(5);
                    countdown -= 5;
                }
                isTimeOverwrite = false;
                if (isOverwrite) {
                    intake->move(overwriteSpeed);
                } else {
                    intake->move(defaultSpeed);
                }
            });
        }
        void setOverwriteSpeed(double speed) {
            isOverwrite = true;
            if (!isTimeOverwrite) {
                intake->move(speed);
            }
            overwriteSpeed = speed;
        }
    
        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/
        
        void waitUntilRotations(double rotations, double timeout) {
            intake->set_zero_position(0);
            while (intake->get_position() < rotations * 360) {
                pros::delay(5);
                if (timeout > 0) {
                    timeout -= 5;
                    if (timeout <= 0) {
                        break;
                    }
                }
            }
        }
        void waitUntilRotations(double rotations) {
            intake->set_zero_position(0);
            while (abs(intake->get_position()) < rotations * 360) {
                pros::delay(5);
            }
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/

        void clearOverwrite() {
            isOverwrite = false;
            intake->move(defaultSpeed);
        }

        void clearAllOverwrites() {
            isTimeOverwrite = false;
            isOverwrite = false;
            intake->move(defaultSpeed);
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/

        bool getIsMoving() {
            return abs(intake->get_actual_velocity()) > 5;
        }
        double getSpeed() {
            return intake->get_actual_velocity();
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
        
};


#endif