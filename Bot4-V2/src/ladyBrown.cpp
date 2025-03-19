#include "globals.hpp"
#include "hook.cpp"

#ifndef LB_CPP
#define LB_CPP

class LadyBrown {
    private:
        pros::Motor *LB;
        pros::Rotation *LBEncoder;
        Hook *hook;
        double currentMotorPosition;
        double currentLBPosition;
        double setPoint;
        double velocity;
        bool setPointMovement;
        lemlib::PID *LB_PID;

    public:
        // Constructor to initialize all member variables
        LadyBrown(pros::Motor *LB, pros::Rotation *LBEncoder, lemlib::PID *LB_PID, Hook *hook) 
            : LB(LB), 
              LBEncoder(LBEncoder),
              LB_PID(LB_PID),  // Initializing PID with specific gains
              hook(hook), // Initializing hook
              currentMotorPosition(0), // Initialize to 0
              currentLBPosition(0),    // Initialize to 0
              setPoint(0),           // Initialize to 0
              velocity(0),           // Initialize to 0
              setPointMovement(true)            
        {}
        void init() {
            LBEncoder->set_position(0);
            LBEncoder->set_reversed(true);
            LB->set_reversed(true);
            LB->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
            LB->set_brake_mode(MotorConfigs::HOLD);
            LB->set_gearing(MOTOR_GEAR_GREEN);
        }
        void setSetPoint(double setPoint) {
            if (setPoint == 0) {
                LB->set_brake_mode(MotorConfigs::COAST);
            } else {
                LB->set_brake_mode(MotorConfigs::HOLD);
            }
            setPointMovement = true;
            this->setPoint = setPoint;
        }
        void setVelocity(double velocity) {
            LB->set_brake_mode(MotorConfigs::HOLD);
            setPointMovement = false;
            this->velocity = velocity;
        }
        void update() {
            currentMotorPosition = LBEncoder->get_position();
            currentLBPosition = currentMotorPosition / 300; // Convert to degrees
            if (setPointMovement) {
                double error = setPoint - currentLBPosition;
                double output = LB_PID->update(error);
                LB->move(output);
                if (currentLBPosition < LadyBrownConfigs::NOCONTACTZONE && currentLBPosition > LadyBrownConfigs::LOADING-2 && error > 10) {
                    hook->setOverwriteSpeed(-40);
                } else if (hook->getOverwriteSpeed() == -20) {
                    hook->clearOverwrite();
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
};

#endif