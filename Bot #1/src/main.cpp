// Includes all libraries that we use

/* 

main.h - Default (Nessesary)
globals.hpp - All global variables such as motors and team colour are situated here & motor initialization
odometry.hpp - Odometry File (Calculates Position & Movement)
threading.hpp - Threading Functions such as the wallstake mechanism
MovFunc.hpp - Master Control for the bot (All functions for the bot are here)
technical.hpp - Misc Functions & functions related to sensors.

*/

#include "main.h"
#include "globals.hpp"
#include "threading.hpp"
#include "technical.hpp"


#include <string>
#include <stdlib.h>

ASSET(startofauton2_txt)
ASSET(middleofauton_txt)
ASSET(startofauton2blue_txt)
ASSET(mogorushred_txt)
ASSET(mogorushredbluetxt_txt)







void on_center_button() {}

void initialize()
{
	pros::Task selection([&]() {
		InitalizeSetup();
	});
	
	swallMotor.set_zero_position(0);
	swallMotor.get_encoder_units(MOTOR_ENCODER_DEGREES);
	swallMotor.set_brake_mode(HOLD);

	left_dr.set_gearing_all(pros::E_MOTOR_GEAR_BLUE);
	right_dr.set_gearing_all(pros::E_MOTOR_GEAR_BLUE);
	chassis.calibrate();

	pros::Task colour(coloursorter, nullptr, "Bob");

	clawp.set_value(false);
	

	// Position Update
	// pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen

	// 		pros::screen::print(TEXT_SMALL,1, "X: %f", chassis.getPose().x);
	// 		pros::screen::print(TEXT_SMALL,2, "Y: %f", chassis.getPose().y);
	// 		pros::screen::print(TEXT_SMALL,3, "Theta: %f", chassis.getPose().theta);

			
			
    //         // delay to save resources
    //         pros::delay(20);
    //     }
    // });
}

void disabled() {}
//Runs when the robot is disabled

void competition_initialize() {}
//Runs when the match starts

void autonomous()
{
	
	//Motor & Sensor Settings
	// vertical_tracking.reset();
	// horizontal_tracking.reset();
	// vertical_tracking.set_position(0);
	// horizontal_tracking.set_position(0);
	pros::screen::print(TEXT_SMALL,3, "auton: %d", autonselector);
	while (autonselector == 5){
		pros::delay(50);
		
	}
	//Autonomous
	if (!team && autonselector == 1) {
		chassis.setPose(58,-36,90);
		// chassis.moveToPoint(-18,-36,1000,{false});
		// chassis.turnToHeading(0,1000);
		// chassis.moveToPoint(-18,-48,1000,{false});
		// chassis.turnToHeading(270,1000);
		chassis.follow(mogorushredbluetxt_txt,15,3000,false);
		// chassis.moveToPoint(-18,-48,1000,{false});
		
		chassis.waitUntilDone();
		bot.clampOn();
		pros::delay(200);
		bot.runHook(127);
		bot.runIntake(127);
		pros::delay(500);
		bot.clampOff();
		chassis.moveToPoint(24,-60,2000);
		bot.stopHook();
		chassis.waitUntilDone();
		
		bot.clampOff();

		chassis.turnToHeading(180,1000);
		
		chassis.moveToPoint(24,-20,2000,{false});
		chassis.waitUntilDone();
		bot.clampOn();
		pros::delay(500);
		bot.runHook(127);
		// pros::delay(1000);
		// bot.clampOff();
		chassis.turnToHeading(90,1000);
		// chassis.moveToPose(34,8,0,3000,{true,0,0.8,127});
		// chassis.waitUntilDone();
		// wing.set_value(true);
		// chassis.moveToPoint(36,-30,1000,{false});
		// chassis.waitUntilDone();
		// // bot.stopHook();
		// wing.set_value(false);
		// chassis.moveToPoint(47,-6,2000);

	} else if (team && autonselector == 1) {
		chassis.setPose(-58,-36,270);
		// chassis.moveToPoint(-18,-36,1000,{false});
		// chassis.turnToHeading(0,1000);
		// chassis.moveToPoint(-18,-48,1000,{false});
		// chassis.turnToHeading(270,1000);
		chassis.follow(mogorushred_txt,15,3000,false);
		// chassis.moveToPoint(-18,-48,1000,{false});
		
		chassis.waitUntilDone();
		bot.clampOn();
		bot.runHook(127);
		bot.runIntake(127);
		pros::delay(500);
		bot.clampOff();
		chassis.moveToPoint(-24,-60,2000);
		bot.stopHook();
		chassis.waitUntilDone();
		
		bot.clampOff();

		chassis.turnToHeading(180,1000);
		
		chassis.moveToPoint(-24,-20,2000,{false});
		chassis.waitUntilDone();
		bot.clampOn();
		pros::delay(500);
		bot.runHook(127);
		// pros::delay(1000);
		// bot.clampOff();
		chassis.turnToHeading(270,1000);
		chassis.moveToPose(-34,8,0,3000,{true,70,0.8,127});
		chassis.waitUntilDone();
		wing.set_value(true);
		chassis.moveToPoint(-36,-30,1000,{false});
		chassis.waitUntilDone();
		// bot.stopHook();
		wing.set_value(false);
		chassis.moveToPoint(-47,-6,1000);
		// chassis.moveToPoint(-58,0,2000);
		chassis.turnToHeading(90,2000);

	} else if (team && autonselector == 2) {
		
		chassis.setPose(-60,36,90);
		bot.runIntake(127);
		
		chassis.follow(startofauton2_txt, 15, 3000);
		chassis.moveToPoint(-24,20,2000,{false});
		chassis.waitUntilDone();
		bot.clampOn();
		pros::delay(200);
		chassis.turnToPoint(-24,48,1000);
		bot.runHook(127);
		chassis.moveToPoint(-24,55,2000);
		chassis.turnToHeading(90,1000);
		chassis.moveToPoint(-9,55,2000);
		chassis.moveToPoint(-17,55,2000,{false});
		chassis.moveToPoint(-53,24,1000,{false});
		chassis.turnToHeading(0,1000);
		chassis.moveToPoint(-53,70,1000);
		chassis.waitUntilDone();
		wing.set_value(true);
		// chassis.moveToPoint(0,0,2000,{false});

		// chassis.moveToPose(-56,66,360,3000,{true,0,0.7,127,60});
		// chassis.waitUntilDone();
		// wing.set_value(true);
		// pros::delay(500);
		// chassis.moveToPoint(-50,48,2000,{false});
		// chassis.moveToPoint(-70,70,1000);
		// chassis.turnToHeading(270,1000);
		// chassis.waitUntilDone();
		// pros::delay(400);
		// chassis.moveToPoint(-50,50,1000,{false});
		
		// chassis.follow(middleofauton_txt,15,4000,false);
		// pros::delay(300);
		// wing.set_value(true);

	} else if (!team && autonselector == 2) {
		
		chassis.setPose(60,36,270);
		bot.runIntake(127);
		
		chassis.follow(startofauton2blue_txt, 15, 3000);
		chassis.moveToPoint(24,20,2000,{false});
		chassis.waitUntilDone();
		bot.clampOn();
		pros::delay(200);
		chassis.turnToPoint(24,48,2000);
		bot.runHook(127);
		chassis.moveToPoint(24,55,2000);
		chassis.turnToPoint(12,55,1000);
		chassis.moveToPoint(9,55,2000);
		chassis.moveToPoint(17,55,2000,{false});
		

		// chassis.follow(middleofauton_txt,15,4000,false);
		// pros::delay(300);
		// wing.set_value(true);



	}else if (team && autonselector == 3) {
		chassis.setPose(0,0,0);

		chassis.moveToPose(0,24,270,10000,{true,0,0.9,127});
	}

}

void opcontrol()
{
	// TO DO: Macro to move forward 5 inch

	// chassis.setPose(0,0,0);
	// chassis.turnToHeading(90,10000);



	//Motor & Sensor Settings
	intakeMotor.set_brake_mode(COAST);
	right_dr.set_brake_mode(COAST);
	left_dr.set_brake_mode(COAST);


	/* -------------------------------------------------------------------- */

	// Variable Definition
	bool boolintake = false;
	bool boolhook = false;
	bool boolwing = true;
	bool boolclaw = true;
	bool detect = true;
	int counter = 10;
	int opcolourcounter = 0;
	bool opcolour = false;
	int alcolourcounter = 0;
	bool alcolour = false;
	bool redteam = false;

	optical_sensor.set_led_pwm(100);
	pros::Task wallscore(wallstake, nullptr, "Wallstake Task");
	bool brake = true;

	/* -------------------------------------------------------------------- */
	// While True Loop
	while (true)
	{

		/* Drivetrain Code */
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_X);
		
		

		// Team Toggle - B
		if (master.get_digital_new_press(button_B)) // If B is Pressed
		{
			team = !team;
			if (team)
			{
				master.print(1, 1, "Red Team ");
			}
			else
			{
				master.print(1, 1, "Blue Team ");
			}
		}
		if (distance.get_distance() < 100 && stop) {
			master.rumble("-");
			
			left = left/5;
			right = right/5;
			left_dr.set_brake_mode(HOLD);
			right_dr.set_brake_mode(HOLD);
			pros::delay(100);
		} else {
			right_dr.set_brake_mode(COAST);
			left_dr.set_brake_mode(COAST);
		}
		// Intake Toggle - R1
		if (master.get_digital_new_press(button_R1)) // If R1 is Pressed
		{
			boolintake = !boolintake;
		}

		// Claw Piston Toggle - X
		if (master.get_digital_new_press(button_X)) // If X is Pressed
		{

			boolclaw = !boolclaw;
		}

		// Hook Toggle - R2
		if (master.get_digital_new_press(button_R2)) // If R2 is Pressed
		{

			boolhook = !boolhook;
		}

		// Wing Piston Toggle - Y
		if (master.get_digital_new_press(button_Y)) // If Y is Pressed
		{
			boolwing = !boolwing;
		}
		
		// Toggle Activation
		if (master.get_digital(button_L1)) // If L1 is Pressed
		{
			bot.runHook(-127);
			
		}
		else if (master.get_digital(button_UP)) // If UP is pressed
		{
			bot.runHook(50);
			bot.runIntake(50);
		} else if (master.get_digital(button_L2)) { // If L2 is Pressed
			bot.runIntake(-127);
		}
		else
		{
			//Toggle Hook On/Off
			if (boolhook) {
				bot.runHook(127);
			} else {
				bot.stopHook();
			}
			if (boolintake)
			{
				bot.runIntake(127);
			}
			else
			{

				bot.stopIntake();
			}
		}

		//Toggle Claw On/Off
		if (!boolclaw)
		{
			bot.clampOn();
		}
		else
		{
			bot.clampOff();
		}
		//Toggle Wing On/Off
		if (!boolwing)
		{
			wing.set_value(true);
		}
		else
		{
			wing.set_value(false);
		}

		// Odometry Update Code

		if (abs(left) > 10 || abs(right) > 10) {
			left_dr.move(left + (right * 1.05));
			right_dr.move(left - (right * 1.05));
			brake = true;
		} else if (brake){
			left_dr.brake();
			right_dr.brake();
			brake = false;
		}
	}
}