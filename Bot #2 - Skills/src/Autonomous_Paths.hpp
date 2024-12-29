#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void SkillsAuton() {
    chassis.setPose(-62,0,90);
    hookSpeed = 127;
    intakeSpeed = 127;
    pros::delay(200);
    hookSpeed = 0;
    chassis.moveToPoint(-24,-24,1000);
    //Mogo #1
    chassis.moveToPoint(-48,-24,1000,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    mogo_clamp.set_value(true);
    pros::delay(300);
    hookSpeed = 127;
    chassis.follow(skillsV21_txt,15,4000);

    //Scoring Wall Stake 1
    chassis.turnToPoint(0,-50,700);
    pros::delay(100);
    lbMech.set_brake_mode(HOLD);
    LadyBrownState = 1;
    chassis.moveToPoint(5,-50,2000,{.minSpeed = 70,.earlyExitRange = 2});
    hookSpeed = 127;
    
    chassis.turnToHeading(180,500);
    chassis.moveToPoint(3,-75,1000);
    LadyBrownState = 3;
    lbMech.set_brake_mode(HOLD);
    pros::delay(500);
    

    chassis.moveToPoint(3,-48,1000,{false});
    pros::delay(400);
    lbMech.set_brake_mode(COAST);
    LadyBrownState = 0;
    chassis.turnToPoint(-40,-60,700);
    chassis.moveToPoint(-40,-60,1000,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.moveToPoint(-60,-44,1000);
    chassis.turnToHeading(0,700);
    // chassis.moveToPoint(-48,-60,700,{.forwards = false,.minSpeed = 60,.earlyExitRange = 4});
    // chassis.moveToPoint(-24,-48,700,{false});
    // chassis.turnToPoint(-48,-60,700);
    // chassis.moveToPoint(-48,-48,1000);
    // pros::delay(200);

    // //Corner #1
    // chassis.turnToPoint(0,0,1000);
    
    chassis.moveToPoint(-60,-60,500,{false});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    
    chassis.moveToPoint(-48,-48,500);
    pros::delay(1000);
    hookSpeed = 0;
    chassis.swingToPoint(-46,24,lemlib::DriveSide::RIGHT,1000,{false});
    chassis.moveToPoint(-44,0,2000,{.forwards = false, .minSpeed = 70,.earlyExitRange = 3});
    chassis.moveToPoint(-44,26,1000,{.forwards = false,.maxSpeed = 70});

    //Mogo #2
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(-24,24,700);
    chassis.turnToPoint(-24,48,500);
    chassis.moveToPoint(-24,50,700);
    chassis.turnToPoint(-48,50,500);
    chassis.moveToPoint(-48,50,1000);
    chassis.swingToHeading(45,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.turnToPoint(0,0,1000);
    chassis.waitUntilDone();
    pros::delay(300);
    chassis.moveToPoint(-70,70,500,{false});
    
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    hookSpeed = 0;
    

    chassis.moveToPoint(-36,66,1000,{.minSpeed = 70,.earlyExitRange = 3});
    chassis.moveToPoint(2,52,2000);
    LadyBrownState = 1;
    lbMech.set_brake_mode(HOLD);
    pros::delay(1000);
    hookSpeed = 127;
    chassis.turnToHeading(0,700);
    
    chassis.moveToPoint(1,70,1000);
    pros::delay(100);
    LadyBrownState = 3;
    lbMech.set_brake_mode(HOLD);
    chassis.waitUntilDone();
    pros::delay(500);
    

    chassis.moveToPoint(3,50,1000,{false});
    
    pros::delay(500);
    hookSpeed = 0;
    lbMech.set_brake_mode(COAST);
    LadyBrownState = 0;

    chassis.turnToPoint(28,28,1000);
    chassis.moveToPoint(28,28,1000,{.minSpeed = 60,.earlyExitRange = 3});

    
    chassis.moveToPoint(55,10,700,{.minSpeed = 60, .earlyExitRange = 3});
    chassis.moveToPoint(48,-10,700);
    chassis.moveToPoint(55,0,1000,{false});
    chassis.turnToPoint(75,0,700,{.forwards = false});
    chassis.moveToPoint(68,0,1000,{.forwards = false,.maxSpeed = 65});
    chassis.waitUntilDone();
    left_dr.move(-50);
    right_dr.move(-50);
    hookSpeed = 127;
    pros::delay(1500);
    chassis.moveToPoint(55,0,500);
    chassis.turnToHeading(220,1000);
    chassis.moveToPoint(70,50,1500,{false});
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,1000);
    pros::delay(800);
    hookSpeed = 0;
    chassis.turnToPoint(28,27,1000);
    chassis.moveToPoint(28,28,1000,{.minSpeed = 70,.earlyExitRange = 3});
    chassis.moveToPoint(50,0,1000);

    // Mogo #3
    chassis.turnToPoint(50,-24,1000,{false});
    chassis.moveToPoint(50,-24,1500,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(24,-42,1000,{.minSpeed = 70,.earlyExitRange = 3});
    chassis.swingToHeading(90,lemlib::DriveSide::LEFT,1000);
    chassis.moveToPoint(80,-50,1500);
    chassis.moveToPoint(48,-48,700,{false});
    chassis.turnToPoint(20,0,700);
    chassis.moveToPoint(80,-80,1000,{false});
    BOOL_mogo_clamp = false;
    hookSpeed = -50;
    LadyBrownState = 3;
    chassis.moveToPoint(36,-36,700);
    chassis.turnToPoint(70,-70,700);
    chassis.moveToPoint(-70,130,1500,{.forwards = false,.maxSpeed = 70});
    hookSpeed = 0;
    lbMech.set_brake_mode(BRAKE);
    chassis.waitUntilDone();
    BOOL_wing = true;
    left_dr.move(100);
    right_dr.move(100);
    pros::delay(700);
    left_dr.move(-70);
    right_dr.move(-70);
    
    pros::delay(200);
    left_dr.brake();
    right_dr.brake();

    


    



    

}

#endif