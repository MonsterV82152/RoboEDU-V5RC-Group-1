#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void Clamp() {
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
}

void LoadRing() {
    LadyBrownState = 1;
    lbMech.set_brake_mode(HOLD);
}

void LowerLB() {
    LadyBrownState = 0;
    lbMech.set_brake_mode(COAST);
}

void Skills() {
    chassis.setPose(-58,0,90);
    hookSpeed = 127;
    intakeSpeed = 127;
    pros::delay(200);
    chassis.moveToPoint(-22,-26,1300,{.minSpeed = 50});
    hookSpeed = 0;
    chassis.moveToPoint(-48,-24,1000,{false});
    Clamp();
    chassis.follow(skills_txt,15,6000);
    chassis.waitUntilDone();
    chassis.turnToPoint(-1,-50,700);
    pros::delay(500);
    LoadRing();
    
    chassis.moveToPoint(-3,-50,1000);
    // for (int i = 0; i < 2; i++) {
    //     pros::delay(200);
    //     hookSpeed = 0;
    //     pros::delay(200);
    //     hookSpeed = 127;
    // }
    chassis.turnToPoint(-1,-70,700);
    
    chassis.moveToPoint(-1,-70,1000);
    pros::delay(700);
    LadyBrownState = 3;
    pros::delay(1000);
    chassis.moveToPoint(0,-50,1000,{false});
    LowerLB();
    chassis.turnToPoint(-48,-65,700);
    chassis.moveToPoint(-48,-65,1200);
    chassis.swingToPoint(0,0,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-66,-66,700,{false});
    chassis.waitUntilDone();
    pros::delay(500);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    chassis.moveToPoint(10,10,2000);
    pros::delay(500);
    hookSpeed = 0;
    // chassis.turnToPoint(-31,24,700,{.forwards = false});
    // chassis.moveToPoint(-31,24,1000,{.forwards = false, .earlyExitRange = 5});
    chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-48,24,1500,{false});
    Clamp();
    chassis.moveToPoint(-24,24,1000);
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,1000);
    chassis.turnToPoint(-48,48,700);
    chassis.moveToPoint(-53,48,1000);
    chassis.swingToHeading(90,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-66,66,700,{false});
    pros::delay(500);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    chassis.moveToPoint(0,58,1000);
    LoadRing();
    chassis.turnToPoint(0,70,700);
    chassis.moveToPoint(0,80,1000);
    pros::delay(700);
    LadyBrownState = 3;
    chassis.moveToPoint(0,55,1000,{false});
    LowerLB();

}


#endif