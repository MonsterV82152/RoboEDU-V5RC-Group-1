#include "globals.hpp"

// Main Movement Function File
#ifndef AUTON_HPP
#define AUTON_HPP


/**
 * Turns on the clamp
 */
void Clamp() {
    chassis.waitUntilDone();
    BOOL_mogo_clamp = true;
    pros::delay(200);
    hookSpeed = 127;
}

/**
 * Loads the ring into the LB
 */
void LoadRing() {
    LadyBrownState = 1;
    lbMech.set_brake_mode(HOLD);
}

/**
 * Lowers the LB
 */
void LowerLB() {
    LadyBrownState = 0;
    lbMech.set_brake_mode(COAST);
}

void Skills() {     
    // Set starting position (we should totally use an aligning tool because nathan's eyes suck)
    chassis.setPose(-62,0,90);

    // Turn hook and intake on to score on alliance stake
    // LadyBrownState = 3;
    hookSpeed = 127;
    intakeSpeed = 127;
    pros::delay(300);

    // Drives to get first mogo
    chassis.moveToPoint(-22,-26,1300,{.minSpeed = 50});
    hookSpeed = 0;
    chassis.moveToPoint(-48,-24,1000,{.forwards = false, .maxSpeed = 80});
    
    // Gets the first mogo
    Clamp();
    // chassis.turnToHeading(90,700);

    LadyBrownState = 0;

    // Follow predetermined skills route
    chassis.follow(skills_txt,15,6000);
    chassis.waitUntilDone();
    chassis.turnToPoint(-5,-50,400);
    // pros::delay(100);

    // Loads ring into LB
    LoadRing();

    // Moves to first wall stake
    chassis.moveToPoint(-5,-50,1000,{.minSpeed = 70,.earlyExitRange = 5});
    chassis.turnToPoint(-5,-70,400);
    chassis.moveToPoint(-5,-70,700);
    hookSpeed = -5;    
    // Score first wall stake
    LadyBrownState = 3;
    hookSpeed = 127;
    chassis.waitUntilDone();
    // pros::delay(100);

    // Our pullout game is strong
    chassis.moveToPoint(-5,-45,700,{false});

    // Lowers LB before moving
    LowerLB();

    // Turn to first positive corner
    chassis.turnToPoint(-48,-65,400);
    
    // Drive to first positive corner
    // chassis.moveToPoint(-54,-65,1200);
    // chassis.swingToPoint(0,0,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed = 70,.earlyExitRange = 5});
    chassis.follow(skills3_txt,15,3000);
    chassis.moveToPoint(-70,-70,700,{.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    pros::delay(700);

    // Drops first mogo into the first positive corner
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    hookSpeed = 60;
    chassis.moveToPoint(-48,-48,1000,{.minSpeed = 80, .earlyExitRange = 5});
    chassis.moveToPoint(0,19,3400);
    pros::delay(600);
    hookSpeed = 0;
    chassis.turnToPoint(-48,24,700,{.forwards = false});
    chassis.moveToPoint(-48,24,1000,{.forwards = false, .earlyExitRange = 5});
    // chassis.turnToPoint(-48,24,700,{false});
    chassis.moveToPoint(-54,38,1000,{false});

    // Grabs second mogo
    Clamp();
    // chassis.moveToPoint(-24,24,700);
    // chassis.turnToPoint(-24,48,700);
    // chassis.moveToPoint(-24,48,700);
    // chassis.turnToPoint(-48,48,700);
    // chassis.moveToPoint(-53,48,1000);
    chassis.follow(skills2_txt, 15, 4000);
    chassis.waitUntilDone();
    lemlib::Pose pose = chassis.getPose();
    chassis.setPose(pose.x+5,pose.y-10,pose.theta);
    chassis.moveToPoint(-48,48,700,{.forwards = false});
    chassis.swingToHeading(90,lemlib::DriveSide::RIGHT,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-76,76,700,{false});
    chassis.waitUntilDone();
    LoadRing();

    pros::delay(300);

    // Releases second mogo
    BOOL_mogo_clamp = false;
    hookOverwriteSpeed = -50;
    



    chassis.moveToPoint(-48,60,1000,{.minSpeed = 80, .earlyExitRange = 5});
    // Drive to second wall stake
    chassis.moveToPoint(0,58,1500);
    chassis.waitUntilDone();
    pros::delay(400);
    chassis.turnToPoint(0,80,700);
    LadyBrownState = 2;

    chassis.moveToPoint(0,80,1000);
    pros::delay(1200);
    LadyBrownState = 3;
    pros::delay(1000);
    
    

    // REMOVE THIS if you want to add the first half back
    // Scored 2 on SECOND wall stake 
    pose = chassis.getPose();
    chassis.setPose(pose.x,pose.y-3,pose.theta);
    // LoadRing();
    // hookSpeed = 127;
    // pros::delay(300);
    hookSpeed = 0;
    // //chassis.turnToPoint(0,70,700);
    // //LadyBrownState = 2;
    // chassis.moveToPoint(0,80,1000);
    // pros::delay(300);
    // LadyBrownState = 3;
    // REMOVE THIS if you want to add the first half back

    // Backs up
    chassis.moveToPoint(3,55,1000,{false}); 

    //chassis.moveToPoint(0,55,1000);
    LadyBrownState = 0;
    lbMech.set_brake_mode(COAST);

    // Turn to face red ring ahead of alliance stake
    chassis.turnToPoint(24,24,1000);
    intakeSpeed = 127;

    // Drive to get red ring ahead of alliance stake
    chassis.moveToPoint(24,24,1000,{.minSpeed = 60,.earlyExitRange = 3});
    
    // Adjusts drive position to dodge the mid mogo
    chassis.moveToPoint(55,10,700,{.minSpeed = 60, .earlyExitRange = 3});
    chassis.moveToPoint(48,-7,700);
    chassis.moveToPoint(55,-1,1000,{false});

    // Turns to face alliance stake
    chassis.turnToPoint(72,-1,1000,{.forwards = false}); //alliance stake
    chassis.moveToPoint(72,-1,1000,{.forwards = false});
    chassis.waitUntilDone();

    // KEEP THAT LB DOWNNNNNN
    //LadyBrownState = 0;
    //lbMech.move_velocity(55); // stay down wtf bro -Big Al
    //pros::delay(200);

    lemlib::PID PIDdistance = lemlib::PID(0.8, 0.01, 0.5);
    // BOOL_right_wing = true;
    // Use distance sensors to back up
    for(int i = 0; i < 200; i++) {
        double distance2 = BackDistance2.get_distance();
        double distance = BackDistance.get_distance();
        double pidvalue = PIDdistance.update((95-((distance+distance2)/2)));
        chassis.arcade(pidvalue,0,false,0.5); //97 works the best but we send it for 96
        // (distance2-distance)*0.5
        pros::delay(10);
    }
    // chassis.moveToPoint(70,-4,1000,{.forwards = false, .maxSpeed = 60});
    // Wait until the bot is done moving
    chassis.waitUntilDone();

    // Score that alliance stake
    hookSpeed = 127;
    // BOOL_right_wing = false;
    pros::delay(1500);

    // Drive forwards a bit
    chassis.moveToPoint(55,5,500);
    
//    chassis.moveToPoint(60,24,1500,{false});
//    chassis.waitUntilDone();
//    BOOL_mogo_clamp = true;

    // Turns to face Blue Negative Corner
    chassis.turnToHeading(200,1000);

    // Drives to Blue Negative Corner backwards
    chassis.moveToPoint(60,55,1500,{false});
    // BOOL_mogo_clamp = false;

    hookSpeed = 127;
    
    // Turn to face first red ring
    chassis.turnToPoint(41,47,700);//-24,55 before, then changed to 24,43

    // Drive to get first red ring
    chassis.moveToPoint(41,47,1000);
    pros::delay(200);

    // Back up
    //chassis.moveToPoint(55,46,500);

    // Stop hook
    hookSpeed = 0;

    // Face second red ring
    chassis.turnToPoint(48,62,700);

//Bring up first ring
hookSpeed = 127;
pros::delay(300);
// Stop hook
hookSpeed = 0;

    // Intake second red ring
    chassis.moveToPoint(46,61,850);

    //chassis.moveToPoint(50,46,500);

    //hookSpeed = 50;
    //pros::delay(100);
    //hookSpeed = 0;
    //chassis.turnToPoint(27,27,1000);
    //chassis.moveToPoint(27,27,1000,{.minSpeed = 70,.earlyExitRange = 3});
    //chassis.turnToPoint(38,11,1000);

    // Drive to be near the last Mogo
    //chassis.moveToPoint(38,11,700,{.forwards = false});//48 if mogo on orgin spot, 38 if moved consistently

    // Last Mogo
    // Note: You should tune the position to be roughly where it ends up, good deal of margin of error

    // Point at last Mogo
    chassis.turnToPoint(42,-24,700,{.forwards = false}); //50 -24
    BOOL_colourSorter = true;

    // Drive at last Mogo
    chassis.moveToPoint(42,-24,1500,{.forwards = false,.maxSpeed = 80});
    chassis.waitUntilDone();

    hookSpeed = 0;
    LowerLB(); // Trust me we need this here for some reason
    pros::delay(300);
    // Clamp last Mogo
    BOOL_mogo_clamp = true;
    pros::delay(300);

    // Score 2 red rings
    hookSpeed = 127;
    // Drive to get the first red ring

    //chassis.turnToHeading(359,1000);
    //chassis.moveToPoint(47,-35, 1000,{.maxSpeed = 70});
    hookSpeed = 127; // Adding again bc it keeps running auto unjam
    //pros::delay(100);

    chassis.turnToPoint(48,-47, 700);
    chassis.moveToPoint(48,-67, 1500);

    // // Drive to get the second red ring
    // chassis.turnToPoint(43,-67, 400);
    // chassis.moveToPoint(43,-67, 1000,{.maxSpeed = 50});

    // Back up the robot
    hookSpeed = 127;
    chassis.moveToPoint(35,-47, 1000,{.forwards = false});
    // Point to the next red ring
    chassis.turnToPoint(61, -47.5, 700);
    chassis.moveToPoint(61, -47.5, 1000,{.maxSpeed = 50});

    // Turn so the back of the robot is facing the Blue Positive Corner
    chassis.turnToPoint(45, -20, 1000);
    hookSpeed = 127;
    chassis.waitUntilDone();
    
    // Back into that corner and release the goal
    chassis.moveToPoint(60, -60, 1000, {.forwards = false});
    BOOL_mogo_clamp = false;
    hookSpeed = 127;
    pros::delay(2000);

    // Raise LB (note for eddy the hardstop was adjusted but not the target value so the motor screams)
    chassis.moveToPoint(26,-26,800,{.minSpeed = 70, .earlyExitRange = 5});
    LadyBrownState = 3;
    chassis.turnToPoint(0,0,700,{.forwards = false});
    chassis.moveToPoint(0,0,1000,{ .forwards = false, .maxSpeed = 80});
    // chassis.waitUntilDone();
    // left_dr.move(30);
    // right_dr.move(30);
    // LadyBrownState = 2;
    // pros::delay(200);
    // // LadyBrownState = 0;
    // left_dr.brake();
    // right_dr.brake();

    // pros::delay(2000);
    // chassis.turnToPoint(0,0,1000, {.forwards = false});
    // chassis.moveToPoint(-18,18,2000, {.forwards = false,.maxSpeed = 40});
    // hookSpeed = -50;
    
    // chassis.moveToPoint(70,-70,500, {.forwards = false,.maxSpeed = 70});
    // LadyBrownState = 0;
    // left_dr.brake();
    // right_dr.brake();

    /*   
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