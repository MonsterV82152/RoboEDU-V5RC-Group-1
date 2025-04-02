#include "globals.hpp"
#include "intake.cpp"
#include "colourSorter.cpp"

#ifndef LB_CPP
#define LB_CPP

class LadyBrown {
    private:
        pros::MotorGroup *LB;
        pros::ADIAnalogIn *LBEncoder;
        Intake *intake;
        ColourSorter *colourSorter;
        double currentLBPosition;
        double setPoint;
        double velocity;
        bool setPointMovement;
        lemlib::PID *LB_PID;

    public:
        // Constructor to initialize all member variables
        LadyBrown(pros::MotorGroup *LB, pros::ADIAnalogIn *LBEncoder, lemlib::PID *LB_PID, Intake *intake, ColourSorter *colourSorter) 
            : LB(LB), 
              LBEncoder(LBEncoder),
              LB_PID(LB_PID),  // Initializing PID with specific gains
              intake(intake), // Initializing hook
              colourSorter(colourSorter), // Initializing colourSorter
              currentLBPosition(0),    // Initialize to 0
              setPoint(0),           // Initialize to 0
              velocity(0),           // Initialize to 0
              setPointMovement(true)            
        {}
        void init() {
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
            currentLBPosition = LBEncoder->get_value() + LadyBrownConfigs::LBOFFSET;
            if (setPointMovement) {
                double error = setPoint - currentLBPosition;
                double output = LB_PID->update(error);
                LB->move(output);
                if (currentLBPosition < LadyBrownConfigs::NOCONTACTZONE && currentLBPosition > LadyBrownConfigs::LOADING-2 && error > 10) {
                    intake->setOverwriteSpeed(-40);
                } else if (currentLBPosition > LadyBrownConfigs::NOCONTACTZONE && colourSorter->getRing(0) != 0) {
                    intake->setOverwriteSpeed(0);
                } else if (intake->getOverwriteSpeed() == -40 || intake->getOverwriteSpeed() == 0) {
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
};

#endif