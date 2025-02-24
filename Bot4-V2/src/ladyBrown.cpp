#include "globals.hpp"

#ifndef LB_CPP
#define LB_CPP

class LadyBrown {
    private:
        pros::Motor LB;
        pros::Rotation LBEncoder;
        double currentMotorPosition;
        double currentLBPosition;
        double setPoint;
        double velocity;
        bool setPointMovement;
        lemlib::PID LB_PID;

    public:
        // Constructor to initialize all member variables
        LadyBrown() 
            : LB(PORT_lbMech), 
              LBEncoder(PORT_lbRotation),
              LB_PID(LBKp, LBKi, LBKd),  // Initializing PID with specific gains
              currentMotorPosition(0), // Initialize to 0
              currentLBPosition(0),    // Initialize to 0
              setPoint(0),           // Initialize to 0
              velocity(0),           // Initialize to 0
              setPointMovement(true)            
        {}
        void init() {
            LBEncoder.set_position(0);
            LBEncoder.set_reversed(false);
            LB.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
            LB.set_brake_mode(HOLD);
            LB.set_gearing(MOTOR_GEAR_GREEN);
        }
        void setSetPoint(double setPoint) {
            setPointMovement = true;
            this->setPoint = setPoint;
        }
        void setVelocity(double velocity) {
            setPointMovement = false;
            this->velocity = velocity;
        }
        void update() {
            currentMotorPosition = LB.get_position();
            currentLBPosition = currentMotorPosition / 600; // Convert to degrees
            if (setPointMovement) {
                double error = setPoint - currentLBPosition;
                double output = LB_PID.update(error);
                LB.move(output);
            } else {
                LB.move(velocity);
            }
        }
        // You can add other functions here, like PID control, etc.
};

#endif