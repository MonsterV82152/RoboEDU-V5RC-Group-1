#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void BlueMogoRush() {
    
    chassis.setPose(53,-36,270);
    chassis.follow(Blue_Mogo_Rush_txt,15,1000);
    chassis.waitUntil(28);
    BOOL_left_wing = true;
    chassis.moveToPoint(30,-33,1000,{.forwards = false,.maxSpeed = 80,.earlyExitRange = 2});
    chassis.waitUntilDone();
    BOOL_left_wing = false;
    pros::delay(200);
    chassis.turnToPoint(15,-44,1000,{.forwards=false});
    chassis.moveToPoint(15,-44,1000,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    
    hookSpeed = 127;
    intakeSpeed = 127;
    
    chassis.moveToPoint(30,-40,500);
    chassis.turnToHeading(270,700,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    pros::delay(500);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;

    chassis.moveToPoint(24,-54,800);
    
    hookSpeed = 0;
    chassis.turnToPoint(24,-24,800,{.forwards = false});
    
    chassis.moveToPoint(24,-24,1000,{.forwards = false,.maxSpeed = 70});
    
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(100);
    hookSpeed = 127;
    
    
    // pros::delay(5000);
    


    BOOL_colourSorter = false;
    chassis.moveToPose(44,-10,0,2000,{.lead = 0.5,.minSpeed = 90,.earlyExitRange = 2});
    chassis.moveToPoint(44,25,1800,{.maxSpeed = 55});
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    chassis.waitUntilDone();
    hookSpeed = 0;
    chassis.moveToPoint(53,6,700,{.forwards = false,.earlyExitRange = 2});
    chassis.turnToHeading(270,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(70,3,700,{false});
    pros::delay(200);
    hookSpeed = 127;
    chassis.waitUntilDone();
    pros::delay(800);
    
    
    chassis.moveToPoint(10,0,1000,{.maxSpeed = 60});
    // BOOL_right_wing = true;
    BOOL_colourSorter = true;
}

void FinalsBlueMogoRush() {
    chassis.setPose(53,-36,270);
    chassis.follow(Blue_Mogo_Rush_txt,15,720);
    chassis.waitUntil(28.5);
    BOOL_left_wing = true;
    pros::delay(200);
    chassis.moveToPoint(33,-33,1000,{.forwards = false,.maxSpeed = 80,.earlyExitRange = 2});
    chassis.waitUntilDone();
    BOOL_left_wing = false;
    pros::delay(200);
    right_dr.move(70);
    pros::delay(10);
    right_dr.brake();
    chassis.swingToPoint(24,-21,lemlib::DriveSide::LEFT,700,{.forwards = false});
    chassis.moveToPoint(24,-21,1000,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    intakeSpeed = 127;
    hookSpeed = 127;
    chassis.moveToPoint(24,-48,1000,{.minSpeed = 60,.earlyExitRange = 5});
    chassis.moveToPoint(50,-12,1000);
    chassis.moveToPoint(50,13,1700,{.maxSpeed = 60});
    chassis.swingToPoint(57,-48,lemlib::DriveSide::RIGHT,700);
    chassis.moveToPoint(57,-48,1000);
    chassis.moveToPoint(60,-60,1500);
    chassis.waitUntilDone();
    pros::delay(200);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(50,-50,300,{false});
        if (i == 0) {
            chassis.moveToPoint(70,-70,1000,{.minSpeed = 80});
        } else {
            chassis.moveToPoint(70,-70,700);
        }
        
        chassis.waitUntilDone();
        pros::delay(400);
    }
    chassis.moveToPoint(48,-48,500,{false});
    chassis.turnToPoint(0,0,700);
    chassis.moveToPoint(60,-60,500,{false});
}

void RedMogoRush() {
    chassis.setPose(-53,-36,90);
    chassis.follow(Red_Mogo_Rush_txt,15,1000);
    chassis.waitUntil(30);
    BOOL_right_wing = true;
    chassis.moveToPoint(-33,-33,1000,{.forwards = false,.maxSpeed = 80,.earlyExitRange = 2});
    chassis.waitUntilDone();
    BOOL_right_wing = false;
    pros::delay(200);
    chassis.turnToPoint(-19,-46,700,{.forwards=false});
    chassis.moveToPoint(-19,-46,700,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    
    hookSpeed = 127;
    intakeSpeed = 127;
    
    chassis.moveToPoint(-30,-40,500);
    chassis.turnToHeading(90,700,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    pros::delay(400);
    hookSpeed = 0;
    pros::delay(100);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    
    chassis.moveToPoint(-24,-54,800);
    
    
   
    chassis.turnToPoint(-21,-23,800,{.forwards = false});
    
    chassis.moveToPoint(-21,-23,1500,{.forwards = false,.maxSpeed = 60});
    
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(100);
    hookSpeed = 127;
    
    
    // pros::delay(1000);
    


    BOOL_colourSorter = false;
    chassis.moveToPose(-48,-10,0,2000,{.lead = 0.5,.minSpeed = 80,.earlyExitRange = 2});
    chassis.moveToPoint(-44,25,1300,{.maxSpeed = 60});
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    chassis.waitUntilDone();
    chassis.moveToPoint(-54,2,700,{.forwards = false,.earlyExitRange = 2});
    chassis.turnToHeading(90,1000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    hookSpeed = 0;
    chassis.moveToPoint(-70,-1,700,{false});
    pros::delay(200);
    hookSpeed = 127;
    chassis.waitUntilDone();
    pros::delay(800);
    
    
    left_dr.move(60);
    right_dr.move(60);
    // BOOL_right_wing = true;
    BOOL_colourSorter = true;

}

void FinalsRedMogoRush() {
    chassis.setPose(-53,-36,90);
    chassis.follow(Red_Mogo_Rush_txt,15,800);
    chassis.waitUntil(28.5);
    BOOL_right_wing = true;
    pros::delay(500);
    chassis.moveToPoint(-30,-33,1000,{.forwards = false,.maxSpeed = 80,.earlyExitRange = 2});
    chassis.waitUntilDone();
    BOOL_right_wing = false;
    pros::delay(200);
    right_dr.move(70);
    pros::delay(10);
    right_dr.brake();
    chassis.swingToPoint(-22,-21,lemlib::DriveSide::RIGHT,700,{.forwards = false});
    chassis.moveToPoint(-22,-21,1000,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    intakeSpeed = 127;
    hookSpeed = 127;
    chassis.moveToPoint(-24,-48,1000,{.minSpeed = 60,.earlyExitRange = 5});
    chassis.moveToPoint(-54,-12,700);
    chassis.moveToPoint(-54,13,2000,{.maxSpeed = 60});
    chassis.swingToPoint(-57,-48,lemlib::DriveSide::LEFT,700);
    chassis.moveToPoint(-57,-48,1000);
    chassis.moveToPoint(-60,-60,1500);
    chassis.waitUntilDone();
    pros::delay(200);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(-50,-50,300,{false});
        if (i == 0) {
            chassis.moveToPoint(-70,-70,1000,{.minSpeed = 80});
        } else {
            chassis.moveToPoint(-70,-70,700);
        }
        
        chassis.waitUntilDone();
        pros::delay(400);
    }
    chassis.moveToPoint(-48,-48,500,{false});
    chassis.turnToPoint(0,0,700);
    chassis.moveToPoint(-60,-60,500,{false});

}

void RedRingRush() {
    chassis.setPose(-60,36,90);
    intakeSpeed = 127;
    
    chassis.follow(Red_Ring_Rush_txt, 15, 2000);
    chassis.moveToPoint(-28,20,2000,{.forwards = false,.maxSpeed=70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(-24,48,1000);
    hookSpeed = 127;
    chassis.moveToPoint(-24,55,2000);
    chassis.turnToHeading(90,1000);
    chassis.moveToPoint(-9,55,2000);
    chassis.moveToPoint(-20,55,2000,{false});
    chassis.moveToPoint(-70,70,1500);
    chassis.moveToPoint(-48,24,1000,{.forwards = false, .maxSpeed = 70});
    // chassis.moveToPoint(-53,70,1000);
    // chassis.waitUntilDone();
    // BOOL_wing = true;
}
void BlueRingRush() {
    chassis.setPose(60,36,270);
    intakeSpeed = 127;
    
    chassis.follow(Blue_Ring_Rush_txt, 15, 2000);
    chassis.moveToPoint(28,20,1500,{.forwards = false,.maxSpeed=70});
    pros::delay(1000);
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(24,48,1000);
    hookSpeed = 127;
    chassis.moveToPoint(24,55,2000);
    chassis.turnToHeading(270,1000);
    chassis.moveToPoint(9,55,2000);
    chassis.moveToPoint(20,55,2000,{false});
    chassis.moveToPoint(70,70,1500);
    
    chassis.moveToPoint(48,24,1000,{.forwards = false, .maxSpeed = 70});
}


#endif