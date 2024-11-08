#include "main.h"
#include "lemlib/api.hpp"
#include "drive.cpp"
#include "intake.cpp"
#include "pto.cpp"
#include "clamp.cpp"
#include "lift.cpp"
#include "misc.cpp"
#include "auton.cpp"
#include <list>
#include <iostream>
#include <stdlib.h>
using namespace pros;
using namespace lemlib;

void initialize() {
	lcd::initialize();
	master.clear();

	highIntakeTask.suspend();

	l_mg.set_brake_mode(E_MOTOR_BRAKE_COAST);
	r_mg.set_brake_mode(E_MOTOR_BRAKE_COAST);
	lift.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
	chassis.calibrate();
	test.reset();
	optical.set_led_pwm(100);


	if (3500 < potmeter.get_value()|| potmeter.get_value() < 500){ // red neg, point up
		redSide = true;
		posSide = false;

		master.print(1, 0, "red neg");
		colorMin = blueMin;
		colorMax = blueMax;
	} else if (500 < potmeter.get_value() && potmeter.get_value() < 1400) { // red pos, point right
		redSide = true;
		posSide = true;

		master.print(1, 0, "red pos");
		colorMin = blueMin;
		colorMax = blueMax;
	} else if (1400 < potmeter.get_value() && potmeter.get_value() < 2500) {
		redSide = false;
		posSide = false;

		master.print(1, 0, "blue neg");
		
		colorMin = redMin;
		colorMax = redMax;
	} else if (2500 < potmeter.get_value() && potmeter.get_value() < 3500) { // red team, point left
		redSide = false;
		posSide = true;
		master.print(1, 0, "blue pos");
		
		colorMin = redMin;
		colorMax = redMax;
	}
}

void disabled() {}

void competition_initialize() {}

void autonomous() {	
	hasStart = true;
	skills();

	// if (redSide && !posSide) {
	// 	redNeg();
	// } else if (redSide && posSide) {
	// 	redPos();
	// } else if (!redSide && !posSide) {
	// 	blueNeg();
	// } else if (!redSide && posSide) {
	// 	bluePos();
	// }
}

void opcontrol() {
	hasStart = true;

	// ext_adi_port_set_config(ADI_EXPANDER_PORT, ANALOG_SENSOR_PORT, E_ADI_ANALOG_IN);


	// stopper.set_value(false);
	// delay(500);
	// stopper.set_value(true);
	// delay(500);
	// stopper.set_value(false);
	// delay(500);
	// stopper.set_value(true);
	// delay(500);
	// stopper.set_value(false);
	// delay(500);
	// stopper.set_value(true);
	// delay(500);


	// double tot = 0;
	// for (double i = 10.01; i <= 180; i += 10) {
	// 	double target = chassis.getPose().theta+i;
	// 	master.print(0, 0, "%d", i);
	// 	chassis.turnToHeading(target, 1500);
	// 	delay(3000);
	// 	tot += target - chassis.getPose().theta;
	// }

	// master.print(0, 0, "%.5f", tot);
	// delay(10000);

	// chassis.turnToHeading(-90, 3000);

	// chassis.moveToPoint(0, 48, 5000);
	// delay(5000);
	
	//chassis.moveToPoint(0,8,3000);

	// double tot = 0;
	// for (double i = 8; i <= 40; i += 8) {
	// 	double target = chassis.getPose().y + i;
	// 	master.print(0, 0, "%.2f", target);
	// 	chassis.moveToPoint(0, target, 4000);
	// 	delay(4050);
	// 	tot += fabs(target-chassis.getPose().y);
	// }
	// master.print(0, 0, "%.2f", tot);
	// delay(5000);

	// double tar = 48;
	// int time = 4000;
	// chassis.moveToPose(0, tar, 0, time);
	// delay(time+100);
	// master.print(0, 0, "%.2f", tar-chassis.getPose().y);
	


	while (true) {
		lcd::print(0, "X: %f", chassis.getPose().x); // x
        lcd::print(1, "Y: %f", chassis.getPose().y); // y
        lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
		// lcd::print(3, "hue: %f", optical.get_hue());
		// lcd::print(4, "PM: %d", potmeter.get_value());
		// lcd::print(5, "State: %f", lift.get_position());
		// lcd::print(6, "%d", int(liftTask.get_state()));
		lcd::print(3, "red: %d", intakeTask.get_state());
		lcd::print(4, "pos: %d", highIntakeTask.get_state());
		lcd::print(5, "gay: %f", lift.get_position());
		lcd::print(6, "les: %d", liftState);
		lcd::print(7, "rot: %d", test.get_position()/100);
		drive_(); // move bot
		lift_(); // move lift
		intake_(); // move intake
		pto_(); // move pto
		clamp_(); // move clamp
		misc_(); // misc features

		delay(20);
	}
}