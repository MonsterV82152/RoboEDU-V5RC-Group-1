#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP

void SkillsAuton() {
    chassis.setPose(-58.5,0,90);
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
    chassis.follow(skillsV21_txt,15,7000);


    //Scoring Wall Stake 1
    chassis.moveToPoint(4,-50,2000,{.minSpeed = 70,.earlyExitRange = 2});
    lbMech.set_brake_mode(HOLD);
    LadyBrownState = 1;
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(3.1,-65,800);
    LadyBrownState = 3;
    lbMech.set_brake_mode(HOLD);

    chassis.moveToPoint(0,-50,1000,{false});
    pros::delay(400);
    lbMech.set_brake_mode(COAST);
    LadyBrownState = 0;
    chassis.turnToPoint(-40,-60,700);
    chassis.moveToPoint(-40,-60,1000,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.moveToPoint(-55,-44,1000);
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
    
    chassis.moveToPoint(0,0,1500);
    pros::delay(1000);
    hookSpeed = 0;
    chassis.turnToPoint(-24,24,700);
    
    chassis.moveToPoint(-24,24,1000);
    chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-48,24,1000,{.forwards = false,.maxSpeed = 70});

    //Mogo #2
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(-24,24,700,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,700,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.turnToPoint(-58,48,700);
    chassis.moveToPoint(-50,48,1000);
    chassis.swingToPoint(-48,58,lemlib::DriveSide::RIGHT,1000);
    chassis.turnToPoint(0,0,1000);
    // chassis.moveToPoint(-60,-60,500,{false});
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    hookSpeed = 0;

    chassis.moveToPoint(-1,50,2000);
    pros::delay(1000);
    hookSpeed = 127;
    LadyBrownState = 1;
    lbMech.set_brake_mode(HOLD);
    chassis.turnToHeading(0,700);
    
    chassis.moveToPoint(0,65,1000);
    pros::delay(100);
    LadyBrownState = 3;
    lbMech.set_brake_mode(HOLD);
    chassis.waitUntilDone();
    pros::delay(500);
    

    chassis.moveToPoint(-1,50,1000,{false});
    pros::delay(200);
    hookSpeed = 0;
    pros::delay(200);
    lbMech.set_brake_mode(COAST);
    LadyBrownState = 0;
    chassis.moveToPoint(24,24,1000);
    chassis.moveToPoint(50,-10,700);
    chassis.moveToPoint(50,0,700,{false});
    chassis.turnToHeading(90,700);
    chassis.moveToPoint(60,0,1000,{false});
    chassis.waitUntilDone();
    hookSpeed = 127;
    pros::delay(1000);
    chassis.moveToPoint(50,0,500);
    chassis.swingToHeading(180,lemlib::DriveSide::RIGHT,1000);
    chassis.moveToPoint(55,50,1500,{false});

    


    



    

}

#endif