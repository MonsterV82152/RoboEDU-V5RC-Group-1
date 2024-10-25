#include "globals.hpp"



void skillsauton() {
    chassis.setPose(-60,0,90);
    bot.runHook(127);
    pros::delay(500);
    bot.runIntake(127);

    
    
    chassis.moveToPoint(-24,-24,2000);
    chassis.waitUntilDone();
    bot.stopHook();
    chassis.moveToPoint(-48,-24,2000,{false,70});
    
    chassis.waitUntilDone();
    bot.clampOn();
    bot.runHook(127);
    bot.runIntake(127);
    chassis.moveToPoint(-24,-48,2000);
    chassis.moveToPoint(0,-58,2000);
    chassis.turnToPoint(27,-24,1000);
    chassis.moveToPoint(27,-24,4000);
    pros::delay(1000);
    slow = true;
    chassis.moveToPoint(25,-48,2000);
    bot.stopHook();

    chassis.moveToPose(4,-55,270,5000,{true,0,0.8,127,20});
    chassis.waitUntilDone();
    pros::delay(127);
    swallMotor.move(127);
    pros::delay(1000);
    swallMotor.move(-127);
    pros::delay(1000);
    swallMotor.brake();
    slow = true;
    bot.runHook(127);
    pros::delay(2000);
    bot.stopHook();
    swallMotor.move(127);
    pros::delay(1000);
    swallMotor.move(-127);
    chassis.moveToPoint(-48,-60,3000);
    bot.runHook(127);
    pros::delay(1000);
    swallMotor.brake();

    chassis.moveToPoint(-60,-48,1000);
    chassis.moveToPoint(-57,-57,2000,{false});
    chassis.moveToPoint(-48,-48,2000);
    chassis.moveToPoint(-60,-60,2000,{false});
    chassis.waitUntilDone();
    bot.clampOff();
    chassis.moveToPoint(0,0,5000);
    bot.stopHook();

    chassis.moveToPoint(-24,24,2000);
    bot.runHook(70);
    pros::delay(500);
    bot.stopHook();
    chassis.moveToPoint(-48,24,2000,{false});
    chassis.waitUntilDone();
    bot.clampOn();
    pros::delay(100);
    bot.runHook(127);
    chassis.moveToPoint(-24,48,3000);
    chassis.moveToPoint(-60,48,5000);
    chassis.moveToPoint(-27,50,1000,{false});
    chassis.moveToPoint(-48,60,5000);
    chassis.moveToPoint(-60,60,5000,{false});
    chassis.waitUntilDone();
    bot.clampOff();
}