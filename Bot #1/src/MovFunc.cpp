#include "MovFunc.hpp"

inline void coloursorter(void *param) {
    
    
    
    while (true) {
        int speed = hookMotor.get_power();
        int mult = 2-(127/speed); // Calculate Delay Multiplier
        double a = optical_sensor.get_hue();
        pros::screen::set_pen(0x00DC143C);
        pros::screen::erase();
        pros::screen::draw_circle(a,a,10);
        if (speed != 0) {
            if (a >= 0 && a <= 30)
            {
                if (!team) {
                    pros::delay(200*mult);
                    hookMotor.move(-127);
                    pros::delay(100);
                    hookMotor.move(speed);
                }
            }
            if (a >= 150 && a <= 220)
            {
                if (team) {
                    pros::delay(200*mult);
                    hookMotor.move(-127);
                    pros::delay(100);
                    hookMotor.move(speed); 
                }
            }
        }
        pros::delay(50);
					
    }
}


// Definition & Constructor
MasterControl::MasterControl(bool ahook, bool acolourcheck, int aintakeSpeed) {
    intakeSpeed = aintakeSpeed;
    hook = ahook;
    colourcheck = acolourcheck;
    pros::Task colour(coloursorter, nullptr, "Wallstake Task");
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
    
    if (!hook) {
        hookMotor.move(speed);
    }
    hook = true;
}

// Stops Hook
void MasterControl::stopHook() {
    hookMotor.brake();
    hook = false;
}

void MasterControl::clampOn() {
    clawp.set_value(true);
}
void MasterControl::clampOff() {
    clawp.set_value(false);
}
