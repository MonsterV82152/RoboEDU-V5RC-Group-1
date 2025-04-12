#include "main.h"
#include "lemlib/api.hpp"
#include "drive.cpp"
#include "intake.cpp"
#include "clamp.cpp"
#include "misc.cpp"
#include "auton.cpp"
#include "high.cpp"
#include <list>
#include <iostream>
#include <stdlib.h>
using namespace pros;
using namespace lemlib;

void initialize() {
	lcd::initialize();
	master.clear();

	l_mg.set_brake_mode(E_MOTOR_BRAKE_COAST);
	r_mg.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
	high.set_brake_mode(E_MOTOR_BRAKE_HOLD);
 
	v_track.reset();
	chassis.calibrate();
	chassis.setPose(0, 0, 0);
	optical.set_led_pwm(100);



	if (3500 < potmeterBot.get_value()|| potmeterBot.get_value() < 500){ // red, point up
		redSide = true;

		colorMin = blueMin;
		colorMax = blueMax;
	} else if (500 < potmeterBot.get_value() && potmeterBot.get_value() < 1400) { // skills, point right
		skill = true;

		colorMin = blueMin;
		colorMax = blueMax;
	} else if (1400 < potmeterBot.get_value() && potmeterBot.get_value() < 2500) { // blue, point down
		redSide = false;
		
		colorMin = redMin;
		colorMax = redMax;
	}
	// } else if (2500 < potmeterTop.get_value() && potmeterTop.get_value() < 3500) { // red team, point left
	// 	redSide = false;
	// 	posSide = true;
		
	// 	colorMin = redMin;
	// 	colorMax = redMax;
	// }
	if (3500 < potmeterTop.get_value()|| potmeterTop.get_value() < 500){ // neg, point up
		posSide = false;
	} else if (1400 < potmeterTop.get_value() && potmeterTop.get_value() < 2500) { // pos, point down
		posSide = true;
	}
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	if (skill) {
		skills();
	}else if (redSide && !posSide) {
		redNeg();
	} else if (redSide && posSide) {
		redPos();
	} else if (!redSide && !posSide) {
		blueNeg();
	} else if (!redSide && posSide) {
		bluePos();
	}
}

void opcontrol() {

	// ext_adi_port_set_config(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT, E_ADI_ANALOG_IN);

	// angular awr
	// double tot = 0;
	// for (double i = 9.99; i <= 180; i += 10) {
	// 	double target = chassis.getPose().theta + i;
	// 	chassis.turnToHeading(target, 1500);
	// 	delay(2000);
	// 	tot += target - chassis.getPose().theta;
	// }

	// delay(500);
	// master.print(1, 0, "%.5f", tot);
	// lcd::print(6, 0, "%.5f", tot);
	// delay(3000);

	// int tar = 180;
	// chassis.turnToHeading(tar, 3000);
	// delay(2500);
	// master.print(1, 0, "%.3f", tar - chassis.getPose().theta);
	// delay(3000);


	// lateral awr
	// double tot = 0;
	// for (double i = 8; i <= 40; i += 8) {
	// 	double target = chassis.getPose().y + i;
	// 	chassis.moveToPoint(0, target, 4000);
	// 	delay(4050);
	// 	master.print(0, 0, "%f", target-chassis.getPose().y);
	// 	tot += target-chassis.getPose().y;
	// }
	// master.print(1, 0, "%.2f", tot);
	// delay(5000);

	// double tar = 24;
	// int time = 4000;
	// chassis.moveToPoint(0, tar, time);
	// delay(time+100);
	// master.print(1, 0, "%.2f", tar-chassis.getPose().y);
	// delay(100);
	// master.print(2, 0, "%.2f", chassis.getPose().y);

	// chassis.turnToHeading(90, 1500);
	// delay(2000);
	// master.print(1, 0, "%.2f", chassis.getPose().theta);
	// delay(1000);

	// int tar = 48;
	// chassis.moveToPoint(0, tar, 2000);
	// delay(2000);
	// master.print(1, 0, "%.2f", tar - chassis.getPose().y);
	// delay(1000);

	if (skill) {
		clampStat = false;
		highStat = 1;
		pros:delay(500);
		intake.move(-127);
		pros::delay(200);
		intake.move(0);
		highStat = 4;
		pros::delay(400);
		chassis.setPose(0, 0, 0);
		chassis.moveToPoint(0,-14, 500,{false});
		pros::delay(500);
		highStat = 0;
		clampStat = true;
		chassis.turnToHeading(125,700);
	}

	// chassis.setPose(55, 23.5, 90);
	// while (true) {
	// 	lcd::print(0, "X: %.3f, %.3f, %.3f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
	// 	delay(20);
	// }

	while (true) {
		// master.print(1, 0, "%.2f", tar - chassis.getPose().y);
		lcd::print(0, "X: %.3f, %.3f, %.3f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta); // x, y, theta
        // lcd::print(1, "Y: %.3f", ); // y
        // lcd::print(2, "Theta: %f.3", chassis.getPose().theta); // heading
		lcd::print(1, "High pos: %d", highPot.get_value());
		lcd::print(2, colorSort ? "CS: Yes" : "CS: No ");
		lcd::print(3, holdTop ? "HT: Yes" : "HT: No ");
		lcd::print(4, atTop ? "Top: Yes" : "Top: No ");
		lcd::print(5, reject ? "Rej: Yes" : "Rej: No ");

		drive_(); // move bot
		intake_(); // move intake
		clamp_(); // move clamp
		high_();
		misc_(); // misc features 

		delay(20);
	}
}