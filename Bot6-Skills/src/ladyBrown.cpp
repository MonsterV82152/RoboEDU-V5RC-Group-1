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
    double veloctiy;
    bool climbing;
    bool setPointMovement;
    lemlib::PID *LB_PID;
    ArmFeedForward *LB_FF;

public:
    LadyBrown(pros::MotorGroup *LB, pros::ADIAnalogIn *LBEncoder, lemlib::PID *LB_PID, ArmFeedForward *LB_FF, Intake *intake)
        : LB(LB),
          LBEncoder(LBEncoder),
          LB_PID(LB_PID),
          LB_FF(LB_FF),
          intake(intake),
          currentLBPosition(0),
          setPoint(0),
          veloctiy(0),
          climbing(false),
          setPointMovement(true) {
        // profile = new TrapezoidalProfile(1080, 1800.0, 360); // deg/s, deg/s^2
    }

    void init() {
        LB->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
        LB->set_brake_mode(MotorConfigs::COAST);
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
        LB->set_brake_mode(MotorConfigs::COAST);
        setPointMovement = false;
        this->setPoint = 0;
        this->veloctiy = velocity;
    }

    void update() {
        currentLBPosition = (LBEncoder->get_value() + LadyBrownConfigs::LBOFFSET) / LadyBrownConfigs::POT_TICK_2_DEGREE;
        double ff = LB_FF->update(currentLBPosition - LadyBrownConfigs::LB_HORIZONTAL);


        if (setPointMovement) {

            double error = setPoint - currentLBPosition;

            if (abs(error) < 5 && setPoint == 0) {
                LB->set_brake_mode(MotorConfigs::COAST);
                LB->move(0);
                return;
            }

            double output = LB_PID->update(error) + ff;
            if (climbing) output *= 3;

            LB->move(output);

            if (currentLBPosition < LadyBrownConfigs::NOCONTACTZONE &&
                currentLBPosition > LadyBrownConfigs::LOADING - 5 && setPoint - currentLBPosition > 30) {
                intake->setOverwriteSpeed(-300);
            } else if (intake->getOverwriteSpeed() == -300) {
                intake->clearOverwrite();
            }
        } else {
            LB->move(veloctiy+ff);
        }
    }

    double getPosition() { return currentLBPosition; }
    double getSetPoint() { return setPoint; }
    bool isAtSetPoint() { return abs(currentLBPosition - setPoint) < 2; }

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
