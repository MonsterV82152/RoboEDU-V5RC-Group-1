#include "globals.hpp"



void skillsauton() {

    chassis.setPose(-60, 0, 90);

    bot.runIntake(127);
    bot.runHook(127);
    pros::delay(500);
    chassis.moveToPoint(-24, -24, 1500);
    bot.stopHook();
    chassis.waitUntilDone();
    
    chassis.moveToPoint(-48, -24, 1000,{false});
    //Clamp
    chassis.waitUntilDone();
    bot.clampOn();
    pros::delay(100);
    // chassis.moveToPoint(-23.607, -47.215, 2000);

    // pros::delay(500);
    bot.runHook(127);
    // chassis.moveToPoint(0, -59, 2000);
    // chassis.moveToPoint(23.607, -23.442, 2000);
    // pros::delay(500);

    chassis.follow(skillsV21_txt,15,6000);
    chassis.waitUntil(150);
    slow = true;
    // chassis.turnToPoint(24,-48,1000); 
    // chassis.moveToPoint(24, -48, 1000);
    
    chassis.moveToPoint(5, -68, 500);
    bot.stopHook();
    chassis.turnToHeading(270,1000);
    chassis.waitUntilDone();
    int time = 0;
    while (time < 300) {
        if (distance.get_distance() < 150) {
            chassis.cancelAllMotions();
            break;
        }
        if (time == 50) {
            chassis.moveToPoint(-15,chassis.getPose().y,1500,{.maxSpeed = 40});
        }
        time = time + 1;
        
        pros::delay(5);
    }
    left_dr.brake();
    right_dr.brake();
    chassis.cancelAllMotions();
    chassis.moveToPoint(chassis.getPose().x+2,chassis.getPose().y,700,{false});

                                                                                                                                                                                                                                                                                                                                                                 
    
    chassis.waitUntilDone();
    pros::delay(127);
    swallMotor.move(127);
    pros::delay(700);
    swallMotor.move(-127);
    pros::delay(700);
    swallMotor.brake();
    // slow = true;
    // bot.runHook(127);
    // pros::delay(4000);
    // bot.stopHook();
    // swallMotor.move(127);
    // pros::delay(1000);
    // swallMotor.move(-127);

    bot.runHook(127);
    chassis.moveToPoint(-56, -60, 1200);
    chassis.moveToPoint(-24,-44,750,{false});
    chassis.turnToHeading(270, 750);
    chassis.moveToPoint(-65,-44,1000);


    // chassis.moveToPoint(-58.771, -47.215, 1000);
    // chassis.moveToPoint(-58.771, -57.615, 1000,{false});
    // chassis.moveToPoint(-40.215, -40.38, 1000);
    chassis.turnToPoint(0,0,750);
    chassis.moveToPoint(-70, -70, 500,{false});
    // chassis.waitUntilDone();
    // pros::delay(00);
    bot.clampOff();
    //Unclamp
    // chassis.moveToPoint(0, 0, 3000);
    bot.stopHook();
    // chassis.moveToPoint(-24, 24, 2000);
    chassis.moveToPoint(-48, 0, 1000);
    chassis.turnToHeading(180,700);
    chassis.moveToPoint(-48,24,1400,{false});
    chassis.waitUntilDone();
    bot.clampOn();
    //Clamp
    pros::delay(200);
    bot.runHook(127);
    chassis.moveToPoint(-24,18,1000);
    chassis.turnToPoint(-24,40,1000);
    // chassis.follow(skillsV22_txt,15,3000);
    chassis.moveToPoint(-24, 40, 1000);
    chassis.moveToPoint(0,50,1000);
    chassis.moveToPoint(24,40,1400);
    pros::delay(700);
    slow = true;
    chassis.moveToPoint(0,65,1500,{false});
    
    chassis.turnToHeading(90,1000);
    chassis.waitUntilDone();
    time = 0;
    while (time < 200) {
        if (distance.get_distance() < 100) {
            chassis.cancelAllMotions();
            break;
        }
        if (time == 50) {
            chassis.moveToPoint(-15,chassis.getPose().y,1200,{false});
        }
        time = time + 1;
        
        pros::delay(5);
    }
    chassis.moveToPoint(chassis.getPose().x+3,chassis.getPose().y,700);
    chassis.waitUntilDone();
    pros::delay(127);
    swallMotor.move(127);
    pros::delay(700);
    swallMotor.move(-127);
    pros::delay(700);
    swallMotor.brake();

    chassis.moveToPoint(-24,40,1000,{false});
    chassis.turnToPoint(-60, 40,1000);
    chassis.moveToPoint(-60, 40, 1000);
    chassis.moveToPoint(-24,48,1000,{false});
    chassis.turnToHeading(270,750);
    chassis.moveToPoint(-55,58,1000);
    chassis.turnToHeading(90,1000,{.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.moveToPoint(-60.504, 60.339, 500, {false});
    chassis.waitUntilDone();
    bot.clampOff();
    //Unclamp
    chassis.moveToPoint(0, 48, 2000);
    bot.stopHook();
    chassis.waitUntilDone();    
    // chassis.follow(skillsV24_txt,15,4000);
    chassis.moveToPoint(24,20,1000);
    bot.runHook(127);
    pros::delay(250);
    bot.stopHook();
    chassis.moveToPoint(66,7,1000);
    chassis.turnToPoint(66,60,750,{.forwards=false});
    chassis.moveToPoint(68,60,1500,{false});
    chassis.moveToPoint(52,24,700);
    chassis.turnToHeading(15,700);
    // chassis.moveToPoint()
   

    // chassis.turnToHeading(315,1000);
    chassis.moveToPoint(48,-3,2000,{false});
    chassis.waitUntilDone();
    bot.clampOn();

    pros::delay(200);
    
    bot.runHook(127);
    // chassis.follow(skillsV23_txt,15,2500);
    chassis.turnToHeading(0,750);
    chassis.moveToPoint(50,58,1000,{.minSpeed = 80});
    // chassis.turnToHeading(0,1000);
    // chassis.moveToPoint(52,63,1000);
    chassis.moveToPoint(48,48,750,{false});
    chassis.turnToHeading(180,1000);
    chassis.moveToPoint(46,-60,3000,{.minSpeed = 70});
    // chassis.moveToPoint(52,-48,750,{.forwards = false});
    chassis.turnToHeading(270,750);
    
    // chassis.moveToPoint(70,-70,750,{false});
    
    // chassis.turnToHeading(90,1000);
    // chassis.moveToPoint(60,46,1000);
    // chassis.turnToHeading(180,1000);
    // chassis.moveToPoint(60,60,1000,{false});
    // chassis.waitUntilDone();
    // bot.clampOff();
    // chassis.moveToPoint(48,58,2000,{true, 80});
    // chassis.moveToPoint(48,48,1000,{false});
    // chassis.turnToPoint(0,0,1000);
    // chassis.moveToPoint(70,70,1000,{false});
    chassis.waitUntilDone();
    bot.clampOff();
    bot.runHook(-127);
    left_dr.move(-70);
    right_dr.move(-90);
    pros::delay(600);
    left_dr.move(70);
    right_dr.move(70);
    // chassis.moveToPoint(50,-50,500);
    // chassis.moveToPoint(-66,-66,500,{false});

    // bot.stopHook();
    // chassis.turnToHeading(180,1000);
    // chassis.moveToPoint(48,-58,3000);
    // chassis.moveToPoint(66,-66,1000);
    // chassis.waitUntilDone();
    // bot.clampOff();
    // chassis.moveToPoint(45,0,1500);
    // chassis.moveToPoint(60,-66,2000);
    // chassis.moveToPoint(-24,24,2000,{false,100,100});
    // chassis.waitUntilDone();
    // left_dr.move(60);
    // right_dr.move(60);
    // pros::delay(500);
    // left_dr.brake();
    // right_dr.brake();
}