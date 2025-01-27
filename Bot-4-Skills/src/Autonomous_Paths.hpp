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
/*     chassis.setPose(-58,0,90);
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
    chassis.turnToPoint(4,-70,700);
    hookSpeed = 0;
    
    chassis.moveToPoint(4,-70,700);
    pros::delay(700);
    LadyBrownState = 3;
    hookSpeed = 127;
    pros::delay(300);
    chassis.moveToPoint(0,-45,1000,{false});
    chassis.turnToPoint(-48,-65,700);
    LowerLB();
    chassis.moveToPoint(-48,-65,1200);
    chassis.swingToPoint(0,0,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-66,-66,700,{false});
    // chassis.turnToPoint(-24,-48,700);
    chassis.waitUntilDone();
    pros::delay(700);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    
    chassis.moveToPoint(10,10,2000);
    pros::delay(500);
    hookSpeed = 0;
    chassis.turnToPoint(-48,18,700,{.forwards = false});
    chassis.moveToPoint(-48,18,1000,{.forwards = false, .earlyExitRange = 5});
    // chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-48,24,700,{false});
    Clamp();
    chassis.moveToPoint(-24,24,700);
    chassis.turnToPoint(-24,48,700);
    chassis.moveToPoint(-24,48,700);
    chassis.turnToPoint(-48,48,700);
    chassis.moveToPoint(-53,48,1000);
    chassis.swingToHeading(90,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-66,66,700,{false});
    chassis.waitUntilDone();
    pros::delay(500);
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    chassis.moveToPoint(0,53,1500);
    LoadRing();
    chassis.turnToPoint(0,70,700);
    LadyBrownState = 2;
    chassis.moveToPoint(0,80,1000);
    pros::delay(700);
    LadyBrownState = 3;
 */
    //SCORED // Scored 2 on NEG wall stake 
    chassis.setPose(0,58,360);
       LoadRing();
    hookSpeed = 127;
    pros::delay(300);
    hookSpeed = 0;
    chassis.turnToPoint(0,70,700);
    LadyBrownState = 2;
    chassis.moveToPoint(0,80,1000);
    pros::delay(700);
    LadyBrownState = 3;

    chassis.moveToPoint(3,55,1000,{false}); // Backup

    pros::delay(500);
    hookSpeed = 0;
    lbMech.set_brake_mode(COAST);
    //chassis.moveToPoint(0,55,1000);
    LadyBrownState = 0;

    chassis.turnToPoint(24,24,1000); // Turn towards alliance Stake
    intakeSpeed = 127;
    chassis.moveToPoint(24,24,1000,{.minSpeed = 60,.earlyExitRange = 3});

    
    chassis.moveToPoint(55,10,700,{.minSpeed = 60, .earlyExitRange = 3});
    chassis.moveToPoint(48,-7,700);
    chassis.moveToPoint(55,-2,1000,{false});
    chassis.turnToPoint(72,-2,1000,{.forwards = false}); //alliance stake
    chassis.waitUntilDone();
    LadyBrownState = 0;
    lbMech.move_velocity(5); // stay down wtf bro 
    pros::delay(20);
    lbMech.set_brake_mode(HOLD);

    while (true) {
        double distance2 = BackDistance2.get_distance();
        double distance = BackDistance.get_distance();
        chassis.arcade((97-(distance+distance2)/2)*0.5,(distance2-distance)*0.5,false,0.5); //97 works the best
        if (abs(97-distance) < 5) {
            break;
        }
        pros::delay(5);
    }
    chassis.waitUntilDone();
    hookSpeed = 127;
    pros::delay(1500);
    chassis.moveToPoint(55,5,500);
    chassis.turnToHeading(175,1000);
    chassis.moveToPoint(60,55,1500,{false});
    chassis.turnToPoint(24,43,700);//-24,55 before
    chassis.moveToPoint(42,47,1000);
    pros::delay(500);
    hookSpeed = 20;
    chassis.moveToPoint(50,46,500);
    chassis.turnToPoint(46,63,700);
    hookSpeed = 127;
    pros::delay(300);
    hookSpeed = 0;
    chassis.moveToPoint(46,63,750);
    chassis.moveToPoint(50,46,500);

    hookSpeed = 50;
    pros::delay(100);
    hookSpeed = 0;
    //chassis.turnToPoint(27,27,1000);
    //chassis.moveToPoint(27,27,1000,{.minSpeed = 70,.earlyExitRange = 3});
    chassis.turnToPoint(38,11,1000);
    chassis.moveToPoint(38,11,1000);//48 if mogo on orgin spot, 38 if moved consistently

    // Mogo #3
    chassis.turnToPoint(40,-24,1000,{false}); //50 -24
    chassis.moveToPoint(40,-24,1500,{.forwards = false,.maxSpeed = 70});
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
    
    
// New BLue Positive

chassis.moveToPoint(47,-70, 800);
chassis.swingToHeading(90,lemlib::DriveSide::LEFT,1000);
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
    left_dr.move(100);
    right_dr.move(100);
    pros::delay(350);
     left_dr.move(50);
    right_dr.move(50);
    pros::delay(350);
    left_dr.move(-70);
    right_dr.move(-70);
    
    pros::delay(200);
    left_dr.brake();
    right_dr.brake();

/*     chassis.moveToPoint(24,-42,1000,{.minSpeed = 70,.earlyExitRange = 3});
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
    left_dr.move(100);
    right_dr.move(100);
    pros::delay(350);
     left_dr.move(50);
    right_dr.move(50);
    pros::delay(350);
    left_dr.move(-70);
    right_dr.move(-70);
    
    pros::delay(200);
    left_dr.brake();
    right_dr.brake(); */
}


#endif