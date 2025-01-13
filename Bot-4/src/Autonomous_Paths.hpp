#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void BlueMogoRush() {
    
    chassis.setPose(51,-30,90);
    chassis.follow(Blue_Mogo_Rush_txt,15,1500,false);
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    intakeSpeed = 127;
    chassis.moveToPoint(24,-60,1000);
    chassis.waitUntilDone();
    hookSpeed = 0;
    chassis.moveToPoint(24,-48,1000,{.forwards = false,.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToHeading(270,700);
    pros::delay(200);
    BOOL_mogo_clamp = false;
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(24,-24,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.turnToHeading(90,1000);
    chassis.moveToPose(48,12,0,3000,{.lead = 0.7,.minSpeed = 70});
    while (!(ring[0] == 2)) {
        pros::delay(10);
    }
    hookSpeed = 0;
    chassis.moveToPoint(60,0,1000,{false});
    chassis.turnToHeading(270,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.moveToPoint(65,0,1000,{false});
    pros::delay(500);
    hookSpeed = 127;
}

void FinalsBlueMogoRush() {
    
}

void RedMogoRush() {
    chassis.setPose(-51,-30,270);
    chassis.follow(Red_Mogo_Rush_txt,15,1500,false);
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    intakeSpeed = 127;
    chassis.moveToPoint(-24,-60,1000);
    chassis.waitUntilDone();
    hookSpeed = 0;
    chassis.moveToPoint(-24,-48,1000,{.forwards = false,.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToHeading(90,700);
    pros::delay(200);
    BOOL_mogo_clamp = false;
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(-24,-24,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.turnToHeading(270,1000);
    chassis.moveToPose(-48,12,0,3000,{.lead = 0.7,.minSpeed = 70});
    while (!(ring[0] == 1)) {
        pros::delay(10);
    }
    hookSpeed = 0;
    chassis.moveToPoint(-60,0,1000,{false});
    chassis.turnToHeading(90,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-65,0,1000,{false});
    pros::delay(500);
    hookSpeed = 127;
    
}


void FinalsRedMogoRush() {
    
}

void RedRingRush() {
    
    
}
void BlueRingRush() {
    chassis.setPose(58,36,270);
    intakeSpeed = 127;
    chassis.follow(Blue_Ring_Rush_txt,15,3000);
    chassis.moveToPoint(28,20,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(4,51,700);
    chassis.moveToPoint(4,51,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(48,48,1000,{.forwards = false,.earlyExitRange = 5});
    chassis.turnToPoint(70,70,700);
    
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(70,70,1000,{.maxSpeed = 80}); 
        chassis.waitUntilDone();
        pros::delay(1000);
        chassis.moveToPoint(50,50,700,{.forwards = false,.maxSpeed = 80});
    }
}


#endif