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
    chassis.moveToPoint(-24,-24,2000);

    //Mogo #1
    chassis.turnToPoint(-48,-24,700,{.forwards = false});
    chassis.moveToPoint(-48,-24,1000,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    mogo_clamp.set_value(true);
    pros::delay(300);
    hookSpeed = 127;
    chassis.follow(skillsV21_txt,15,7000);


    //Scoring Wall Stake 1
    chassis.waitUntilDone();
    lbMech.set_brake_mode(HOLD);
    LadyBrownState = 1;
    chassis.moveToPoint(3,-50,3000,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.turnToHeading(180,1000);
    chassis.moveToPoint(3,-65,1000);
    LadyBrownState = 3;
    lbMech.set_brake_mode(HOLD);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPoint(0,-55,1000,{false});
    lbMech.set_brake_mode(COAST);
    LadyBrownState = 0;
    chassis.turnToPoint(-60,-60,1000);
    chassis.moveToPoint(-60,-60,1000);
    chassis.moveToPoint(-48,-60,700,{.forwards = false,.minSpeed = 60,.earlyExitRange = 4});
    chassis.moveToPoint(-24,-48,700,{false});
    chassis.turnToPoint(-48,-60,700);
    chassis.moveToPoint(-48,-48,1000);
    pros::delay(200);

    //Corner #1
    chassis.turnToPoint(0,0,1000);
    
    chassis.moveToPoint(-60,-60,1000,{false});
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    
    chassis.moveToPoint(0,0,2000);

    pros::delay(400);
    hookSpeed = 0;
    chassis.turnToPoint(-24,24,1000);
    chassis.moveToPoint(-24,24,1000);
    chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-48,24,1000,{false});

    //Mogo #2
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    chassis.moveToPoint(-24,24,1000,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.turnToPoint(-24,-48,700);
    chassis.moveToPoint(-24,48,1000,{.minSpeed = 70,.earlyExitRange = 2});
    chassis.turnToPoint(-58,48,700);
    chassis.moveToPoint(-50,48,1500);
    chassis.swingToPoint(-48,58,lemlib::DriveSide::RIGHT,1000);
    chassis.turnToPoint(0,0,1000);
    chassis.moveToPoint(-60,-60,700,{false});
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    hookSpeed = 0;


    



    

}

#endif