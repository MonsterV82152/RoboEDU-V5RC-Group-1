#ifndef LB_CPP
#define LB_CPP

#include "globals.hpp"
#include "intake.cpp"

class LadyBrown {
    private:
        pros::MotorGroup *LB;
        pros::ADIAnalogIn *LBEncoder;
        Intake *intake;
        double currentLBPosition;
        double setPoint;
        double velocity;
        bool climbing;
        bool setPointMovement;
        lemlib::PID *LB_PID;

    public:
        // Constructor to initialize all member variables
        LadyBrown(pros::MotorGroup *LB, pros::ADIAnalogIn *LBEncoder, lemlib::PID *LB_PID, Intake *intake) 
            : LB(LB), 
              LBEncoder(LBEncoder),
              LB_PID(LB_PID),  // Initializing PID with specific gains
              intake(intake), // Initializing hook
              currentLBPosition(0),    // Initialize to 0
              setPoint(0),           // Initialize to 0
              velocity(0),  
              climbing(false),         // Initialize to 0
              setPointMovement(true)            
        {}
        void init() {
            LB->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
            LB->set_brake_mode(MotorConfigs::HOLD);
            LB->set_gearing(MOTOR_GEAR_GREEN);
        }
        void setSetPoint(double setPoint, bool climb = false) {
            if (setPoint == 0) {
                LB->set_brake_mode(MotorConfigs::COAST);
            } else {
                LB->set_brake_mode(MotorConfigs::HOLD);
            }
            if (setPoint > 0 && setPoint < LadyBrownConfigs::HOLD) {
                LBState = "loading";
            } else if (setPoint > LadyBrownConfigs::HOLD) {
                LBState = "scoring";
            } else {
                LBState = "none";
            }
            climbing = climb;
            setPointMovement = true;
            this->setPoint = setPoint;
        }
        void setVelocity(double velocity) {
            LB->set_brake_mode(MotorConfigs::HOLD);
            setPointMovement = false;
            this->velocity = velocity;
        }
        void update() {
            currentLBPosition = (LBEncoder->get_value()+LadyBrownConfigs::LBOFFSET) / LadyBrownConfigs::POT_TICK_2_DEGREE;
            if (setPointMovement) {
                double error = setPoint - currentLBPosition;
                double output = LB_PID->update(error);
                if (climbing) {
                    output = output*3;
                }
                if (currentLBPosition > 120) {
                    output -= 1/3*(currentLBPosition-120);
                } else {
                    output += 1/3*(120-currentLBPosition);
                }
                LB->move(output);
                if (currentLBPosition < LadyBrownConfigs::NOCONTACTZONE && currentLBPosition > LadyBrownConfigs::LOADING-5 && error > 10) {
                    intake->setOverwriteSpeed(-300);
                // } else if (currentLBPosition > LadyBrownConfigs::NOCONTACTZONE) {
                //     intake->setOverwriteSpeed(0);
                } else if (intake->getOverwriteSpeed() == -300) {
                    intake->clearOverwrite();
                }
            } else {
                LB->move(velocity);
            }
        }
        double getPosition() {
            return currentLBPosition;
        }
        double getSetPoint() {
            return setPoint;
        }
        bool isAtSetPoint() {
            return abs(currentLBPosition - setPoint) < 2;
        }
        void waitUntilAtSetpoint(double timeout) {
            while (!isAtSetPoint() && timeout > 0) {
                timeout -= 5;
                pros::delay(5);
            }
        }
        void waitUntilAtSetpoint() {
            while (!isAtSetPoint()) {
                pros::delay(5);
            }
        }
};

#endif