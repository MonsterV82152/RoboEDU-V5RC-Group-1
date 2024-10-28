#include "globals.hpp"



void skillsauton() {
    chassis.setPose(-60.752, 0, 90);
    bot.runIntake(127);
    bot.runHook(127);
    pros::delay(500);
    chassis.moveToPoint(-23.607, -23.442, 2000);
    bot.stopHook();
    chassis.moveToPoint(-47.049, -23.607, 2000,{false});
    //Clamp
    chassis.waitUntilDone();
    bot.clampOn();
    pros::delay(200);
    chassis.moveToPoint(-23.607, -47.215, 2000);
    
    pros::delay(500);
    bot.runHook(127);
    chassis.moveToPoint(0, -59, 2000);
    chassis.moveToPoint(23.607, -23.442, 2000);
    pros::delay(500);
    slow = true;
    chassis.moveToPoint(24, -48, 2000);
    chassis.moveToPoint(3, -62, 2000);
    bot.stopHook();
    chassis.turnToHeading(270,2000);

                                                                                                                                                                                                                                                                                                                                                                 
    
    chassis.waitUntilDone();
    pros::delay(127);
    swallMotor.move(127);
    pros::delay(1000);
    swallMotor.move(-127);
    pros::delay(1000);
    swallMotor.brake();
    slow = true;
    bot.runHook(127);
    pros::delay(4000);
    bot.stopHook();
    swallMotor.move(127);
    pros::delay(1000);
    swallMotor.move(-127);

    bot.runHook(127);
    chassis.moveToPoint(-50, -60, 2000);
    chassis.moveToPoint(-24,-48,2000,{false});
    chassis.turnToHeading(270, 1000);
    chassis.moveToPoint(-65,-48,1000);


    // chassis.moveToPoint(-58.771, -47.215, 1000);
    // chassis.moveToPoint(-58.771, -57.615, 1000,{false});
    // chassis.moveToPoint(-40.215, -40.38, 1000);
    chassis.moveToPoint(-58.605, -57.78, 1000,{false});
    chassis.waitUntilDone();
    bot.clampOff();
    //Unclamp
    chassis.moveToPoint(0.165, -0.33, 2000);
    bot.stopHook();
    chassis.moveToPoint(-24, 24, 2000);
    chassis.moveToPoint(-48, 24, 2000, {false});
    chassis.waitUntilDone();
    bot.clampOn();
    //Clamp
    pros::delay(200);
    bot.runHook(127);
    chassis.moveToPoint(-23, 49, 2000);
    chassis.moveToPoint(-59.183, 47.132, 2000);
    chassis.moveToPoint(-47.297, 58.853, 2000);
    chassis.moveToPoint(-60.504, 60.339, 2000, {false});
    chassis.waitUntilDone();
    bot.clampOff();
    //Unclamp
    chassis.moveToPoint(0.284, 58.704, 2000);
    chassis.moveToPoint(24.723, 46.571, 2000);
    chassis.moveToPoint(-0.063, 59.051, 2000,{false});
    chassis.moveToPoint(23.51, 23.865, 2000);
    chassis.moveToPoint(46.736, -0.055, 2000,{false});
    chassis.waitUntilDone();
    bot.clampOn();
    //Clamp
    chassis.moveToPoint(47.256, 58.877, 2000);
    chassis.moveToPoint(46.736, 34.438, 2000, {false});
    chassis.moveToPoint(59.216, 47.264, 2000);
    chassis.moveToPoint(46.909, 34.264, 2000);
    chassis.moveToPoint(47.348, -58.923, 2000);
    chassis.moveToPoint(58.788, -46.963, 2000);
    chassis.moveToPoint(61.561, -58.576, 2000,{false});
    chassis.waitUntilDone();
    bot.clampOff();
    //Unclamp



    // chassis.setPose(-63,0,90);
    // bot.runHook(127);
    // pros::delay(500);
    // bot.runIntake(127);

    
    // bot.stopHook();
    // chassis.moveToPoint(-24,-24,2000);

    // chassis.moveToPoint(-48,-24,2000,{false,70});
    
    // chassis.waitUntilDone();
    // bot.clampOn();
    // bot.runHook(127);
    // bot.runIntake(127);
    // chassis.turnToPoint(-24,-48,1000);
    // chassis.moveToPoint(-24,-48,1000);
    // chassis.turnToPoint(0,-58,1000);
    // chassis.moveToPoint(0,-58,1000);
    // chassis.turnToPoint(24,-24,2000);
    // chassis.moveToPoint(24,-24,4000);
    // pros::delay(1000);
    // slow = true;
    // chassis.turnToPoint(25,-48,1000);
    // chassis.moveToPoint(25,-48,2000);
    // bot.stopHook();

    // chassis.moveToPose(8,-55,270,5000,{true,0,0.8,127,20});
    // chassis.waitUntilDone();
    // pros::delay(127);
    // swallMotor.move(127);
    // pros::delay(1000);
    // swallMotor.move(-127);
    // pros::delay(1000);
    // swallMotor.brake();
    // slow = true;
    // bot.runHook(127);
    // pros::delay(2000);
    // bot.stopHook();
    // swallMotor.move(127);
    // pros::delay(1000);
    // swallMotor.move(-127);
    // chassis.moveToPoint(-48,-60,3000);
    // bot.runHook(127);
    // pros::delay(1000);
    // swallMotor.brake();

    // chassis.moveToPoint(-60,-48,1000);
    // chassis.moveToPoint(-57,-57,2000,{false});
    // chassis.moveToPoint(-48,-48,2000);
    // chassis.moveToPoint(-60,-60,2000,{false});
    // chassis.waitUntilDone();
    // bot.clampOff();
    // chassis.moveToPoint(0,0,5000);
    // bot.stopHook();

    // chassis.moveToPoint(-24,24,2000);
    // bot.runHook(70);
    // pros::delay(500);
    // bot.stopHook();
    // chassis.moveToPoint(-48,24,2000,{false});
    // chassis.waitUntilDone();
    // bot.clampOn();
    // pros::delay(100);
    // bot.runHook(127);
    // chassis.moveToPoint(-24,48,3000);
    // chassis.moveToPoint(-60,48,5000);
    // chassis.moveToPoint(-27,50,1000,{false});
    // chassis.moveToPoint(-48,60,5000);
    // chassis.moveToPoint(-60,60,5000,{false});
    // chassis.waitUntilDone();
    // bot.clampOff();
}