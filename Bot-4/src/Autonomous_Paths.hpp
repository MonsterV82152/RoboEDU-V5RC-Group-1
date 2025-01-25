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
    chassis.setPose(-50,-30,270);
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
    chassis.turnToHeading(90,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.moveToPoint(-65,0,1000,{false});
    pros::delay(500);
    hookSpeed = 127;
    
}


void FinalsRedMogoRush() {
    
}

void RedRingRush() {
    chassis.setBrakeMode(BRAKE);
    BOOL_colourSorter = false;
    chassis.setPose(-58,36,90);
    intakeSpeed = 127;
    chassis.follow(Red_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(-28,20,1000,{false});
    chassis.waitUntilDone();
    chassis.setBrakeMode(COAST);
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-7,55,700);
    BOOL_colourSorter = true;
    chassis.moveToPoint(-7,55,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-46,50,1000,{.forwards = false,.earlyExitRange = 5});
    chassis.turnToPoint(-80,80,1000,{.maxSpeed = 70});
    
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(-80,80,1000,{.maxSpeed = 70}); 
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(-0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(-90,90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        chassis.moveToPoint(-50,50,700,{.forwards = false,.maxSpeed = 100});
    }
    chassis.moveToPoint(-48,0,1000,{false});
    
}
void BlueRingRush() {
    chassis.setBrakeMode(BRAKE);
    BOOL_colourSorter = false;
    chassis.setPose(58,36,270);
    intakeSpeed = 127;
    chassis.follow(Blue_Ring_Rush_txt,15,1100);
    pros::delay(1150);
    chassis.cancelAllMotions();
    
    // pros::delay(300);
    chassis.moveToPoint(28,20,1000,{false});
    chassis.waitUntilDone();
    chassis.setBrakeMode(COAST);
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(24,48,1000);
    chassis.turnToPoint(5,55,700);
    BOOL_colourSorter = true;
    chassis.moveToPoint(5,51,1000);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(46,50,1000,{.forwards = false,.earlyExitRange = 5});
    chassis.turnToPoint(80,80,1000,{.maxSpeed = 70});
    
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(80,80,1000,{.maxSpeed = 70}); 
        chassis.waitUntilDone();
        for (int j = 0; j < 3; j++) {
            chassis.moveToPoint(0,0,100,{.forwards = false,.maxSpeed = 60});
            chassis.moveToPoint(90,90,200,{.maxSpeed = 127});
        }
        pros::delay(1000);
        chassis.moveToPoint(50,50,700,{.forwards = false,.maxSpeed = 100});
    }
    chassis.moveToPoint(48,0,1000,{false});
    
}


#endif