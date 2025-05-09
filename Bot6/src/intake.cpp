#ifndef INTAKE_CPP
#define INTAKE_CPP

#include "globals.hpp"

class Intake {
    private:
        pros::Motor *intake;
        pros::Motor *roller;
        double defaultSpeed;
        double overwriteSpeed;
        double timeOverwriteSpeed;
        double overwriteCountdown;
        double currentSpeed;
        bool isTimeOverwrite;
        bool isOverwrite;
    public:
        Intake(pros::Motor *intakeMotor, pros::Motor *roller) 
        :   intake(intakeMotor),
            roller(roller),
            defaultSpeed(0),
            overwriteSpeed(0),
            timeOverwriteSpeed(0),
            overwriteCountdown(0),
            currentSpeed(0),
            isTimeOverwrite(false),
            isOverwrite(false)
        {}
        void init() {
            intake->set_brake_mode(MotorConfigs::COAST);
            intake->set_gearing(MOTOR_GEAR_BLUE);
            roller->set_gearing(MOTOR_GEAR_GREEN);
            intake->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/

        void setSpeed(double speed) {
            if (!isOverwrite && !isTimeOverwrite) {
                intake->move_velocity(speed);
                hookAtFullSpeed = false;
                currentSpeed = speed;
            }
            roller->move_velocity(speed/3);
            defaultSpeed = speed;
        }
        void stop() {
            setSpeed(0);
        }
        void setIntakeSpeed(double speed) {
            roller->move_velocity(speed/3);
        }
        void resetRoller() {
            roller->move_velocity(intake->get_target_velocity());
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/
        
        void setOverwriteSpeed(double speed, double countdown) {
            double count = countdown;
            isTimeOverwrite = true;
            timeOverwriteSpeed = speed;
            intake->move_velocity(speed);
            hookAtFullSpeed = false;
            currentSpeed = speed;
            // pros::delay(countdown);
            while (count > 0 && isTimeOverwrite) {
                pros::delay(10);
                count = count - 10;
            }
            
            if (isOverwrite) {
                intake->move_velocity(overwriteSpeed);
                hookAtFullSpeed = false;
                currentSpeed = overwriteSpeed;
            // pros::delay(countdown
            } else {
                intake->move_velocity(defaultSpeed);
                hookAtFullSpeed = false;
                currentSpeed = defaultSpeed;
            // pros::delay(countdown
            }
            isTimeOverwrite = false;
            
        }
        void setOverwriteSpeed(double speed) {
            isOverwrite = true;
            if (!isTimeOverwrite) {
                intake->move_velocity(speed);
                roller->move_velocity(speed/3);
                hookAtFullSpeed = false;
                currentSpeed = speed;
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
            if (!isTimeOverwrite) {
                hookAtFullSpeed = false;
                intake->move_velocity(defaultSpeed);
                roller->move_velocity(defaultSpeed/3);
                currentSpeed = defaultSpeed;
            }
            
        }

        void clearAllOverwrites() {
            isTimeOverwrite = false;
            isOverwrite = false;
            hookAtFullSpeed = false;
            intake->move_velocity(defaultSpeed);
            roller->move_velocity(defaultSpeed/3);
            currentSpeed = defaultSpeed;
        }

        /*------------------------------------------------------------*/
        /*------------------------------------------------------------*/
        
        pros::Motor* getMotor() {
            return intake;
        }
        bool getIsMoving() {
            return abs(intake->get_actual_velocity()) > 20;
        }
        bool atTargetSpeed() {
            return abs(intake->get_target_velocity() - intake->get_actual_velocity()) < 50;
        }
        double getTargetSpeed() {
            return intake->get_target_velocity();;
        }
        double getSpeed() {
            // pros::lcd::print(0, "Intake Speed: %f", intake->get_actual_velocity());
            return intake->get_actual_velocity();
        }
        double getOverwriteSpeed() {
            if (isOverwrite) {
                return overwriteSpeed;
            }
            return 0;
        }
        double getTimeOverwriteSpeed() {
            if (isTimeOverwrite) {
                return timeOverwriteSpeed;
            }
            return 0;
        }
        double getDefaultSpeed() {
            return defaultSpeed;
        }

        
};


#endif