#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void BlueMogoRush() {
    chassis.setPose(51,-36,270);
    chassis.follow(Blue_Mogo_Rush_txt,15,800);
    chassis.waitUntil(26);
    BOOL_left_wing = true;
    chassis.moveToPoint(30,-33,1000,{.forwards = false,.maxSpeed = 80,.earlyExitRange = 2});
    chassis.waitUntilDone();
    BOOL_left_wing = false;
    pros::delay(200);
    chassis.turnToPoint(20,-40,700,{.forwards=false});
    chassis.moveToPoint(20,-40,1500,{.forwards = false,.maxSpeed = 70});
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
    chassis.turnToPoint(28,-24,800,{.forwards = false});
    
    chassis.moveToPoint(28,-24,2000,{.forwards = false,.maxSpeed = 70});
    
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(100);
    hookSpeed = 127;
    
    
    pros::delay(1000);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;


    BOOL_colourSorter = false;
    chassis.moveToPose(44,-10,0,2000,{.lead = 0.5,.minSpeed = 70,.earlyExitRange = 2});
    chassis.moveToPoint(44,15,1000,{.maxSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(400);
    hookSpeed = 0;
    chassis.moveToPoint(50,5,700,{false});
    chassis.turnToHeading(270,1400,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(70,5,700,{false});
    pros::delay(200);
    hookSpeed = 127;
    chassis.waitUntilDone();
    pros::delay(400);
    
    
    chassis.moveToPoint(10,0,1000);
    BOOL_left_wing = true;
    BOOL_right_wing = true;
    BOOL_colourSorter = true;
}

void FinalsBlueMogoRush() {
    chassis.setPose(51,-36,270);
    chassis.follow(Blue_Mogo_Rush_txt,15,800);
    chassis.waitUntil(31);
    BOOL_left_wing = true;
    chassis.moveToPoint(30,-35,1200,{false});
    chassis.waitUntil(15);
    BOOL_left_wing = false;
    chassis.turnToPoint(24,-24,1000,{.forwards = false});
    chassis.moveToPoint(24,-24,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    intakeSpeed = 127;
    hookSpeed = 127;
    chassis.moveToPoint(24,-48,1000,{.minSpeed = 60,.earlyExitRange = 5});
    chassis.moveToPoint(53,-53,2000);
    chassis.turnToPoint(60,-60,1000);
    chassis.waitUntilDone();
    BOOL_left_wing = true;
    chassis.swingToHeading(180,lemlib::DriveSide::LEFT,1000);
    chassis.waitUntilDone();
    BOOL_left_wing = false;
}

void RedMogoRush() {
    chassis.setPose(-51,-36,90);
    chassis.follow(Red_Mogo_Rush_txt,15,800);
    chassis.waitUntil(26);
    BOOL_right_wing = true;
    chassis.moveToPoint(-30,-33,1000,{.forwards = false,.maxSpeed = 80,.earlyExitRange = 2});
    chassis.waitUntilDone();
    BOOL_right_wing = false;
    pros::delay(200);
    chassis.turnToPoint(-20,-40,700,{.forwards=false});
    chassis.moveToPoint(-20,-40,1500,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    
    hookSpeed = 127;
    intakeSpeed = 127;
    
    chassis.moveToPoint(-30,-40,500);
    chassis.turnToHeading(90,700,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    pros::delay(500);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;

    chassis.moveToPoint(-24,-54,800);
    
    hookSpeed = 0;
    chassis.turnToPoint(-28,-24,800,{.forwards = false});
    
    chassis.moveToPoint(-28,-24,2000,{.forwards = false,.maxSpeed = 70});
    
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(100);
    hookSpeed = 127;
    
    
    pros::delay(1000);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;


    BOOL_colourSorter = false;
    chassis.moveToPose(-44,-10,0,2000,{.lead = 0.5,.minSpeed = 70,.earlyExitRange = 2});
    chassis.moveToPoint(-44,15,1000,{.maxSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(400);
    hookSpeed = 0;
    chassis.moveToPoint(-50,5,700,{false});
    chassis.turnToHeading(90,1400,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.moveToPoint(-70,5,700,{false});
    pros::delay(200);
    hookSpeed = 127;
    chassis.waitUntilDone();
    pros::delay(400);
    
    
    chassis.moveToPoint(-10,0,1000);
    BOOL_left_wing = true;
    BOOL_right_wing = true;
    BOOL_colourSorter = true;

}

void FinalsRedMogoRush() {
    chassis.setPose(-51,-36,90);
    chassis.follow(Red_Mogo_Rush_txt,15,800);
    chassis.waitUntil(31);
    BOOL_right_wing = true;
    chassis.moveToPoint(-30,-35,1200,{false});
    chassis.waitUntil(15);
    BOOL_right_wing = false;
    chassis.turnToPoint(-24,-24,1000,{.forwards = false});
    chassis.moveToPoint(-24,-24,1000,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    intakeSpeed = 127;
    hookSpeed = 127;
    chassis.moveToPoint(-24,-48,1000,{.minSpeed = 60,.earlyExitRange = 5});
    chassis.moveToPoint(-53,-53,2000);
    chassis.turnToPoint(-60,-60,1000);
    chassis.waitUntilDone();
    BOOL_right_wing = true;
    chassis.swingToHeading(180,lemlib::DriveSide::LEFT,1000);
    chassis.waitUntilDone();
    BOOL_right_wing = false;
}

void RedRingRush() {
    chassis.setPose(-60,36,90);
    intakeSpeed = 127;
    
    chassis.follow(Red_Ring_Rush_txt, 15, 3000);
    chassis.moveToPoint(-28,20,2000,{.forwards = false,.maxSpeed=70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(-24,48,1000);
    hookSpeed = 127;
    chassis.moveToPoint(-24,55,2000);
    chassis.turnToHeading(90,1000);
    chassis.moveToPoint(-9,55,2000);
    chassis.moveToPoint(-17,55,2000,{false});
    chassis.moveToPoint(-53,24,1000,{false});
    chassis.turnToHeading(0,1000);
    // chassis.moveToPoint(-53,70,1000);
    // chassis.waitUntilDone();
    // BOOL_wing = true;
}
void BlueRingRush() {
    chassis.setPose(60,36,270);
    intakeSpeed = 127;
    
    chassis.follow(Blue_Ring_Rush_txt, 15, 3000);
    chassis.moveToPoint(28,20,2000,{.forwards = false,.maxSpeed=70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    chassis.turnToPoint(24,48,2000);
    hookSpeed = 127;
    chassis.moveToPoint(24,55,2000);
    chassis.turnToPoint(12,55,1000);
    chassis.moveToPoint(9,55,2000);
    chassis.moveToPoint(17,55,2000,{false});
}



#endif