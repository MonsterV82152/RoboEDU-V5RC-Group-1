#include "MovFunc.hpp"

// Definition & Constructor
MasterControl::MasterControl(bool ahook, bool acolourcheck, int aintakeSpeed) {
    intakeSpeed = aintakeSpeed;
    hook = ahook;
    colourcheck = acolourcheck;
    hookMotor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    hookMotor.set_zero_position(0);
    
}

// Intake Control
void MasterControl::runIntake(int speed = 127) {
    intakeMotor.move(speed);
    intakeSpeed = speed;
}

// Stops Intake
void MasterControl::stopIntake() {
    intakeMotor.brake();
}

// Hook Control & Colour Check
void MasterControl::runHook(int speed) {
    // pros::screen::erase();
    if (!hook || speed != HookSpeed) {
        hookMotor.move(speed);
        HookSpeed = speed;
        // pros::screen::draw_circle(100,100,10);
    }
    hook = true;
}

// Stops Hook
void MasterControl::stopHook() {
    hookMotor.brake();
    HookSpeed = 0;
    hook = false;
}

void MasterControl::clampOn() {
    clawp.set_value(true);
}
void MasterControl::clampOff() {
    clawp.set_value(false);
}
