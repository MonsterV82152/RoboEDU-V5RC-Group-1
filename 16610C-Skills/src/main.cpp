#include "main.h"
#include "lemlib/api.hpp"
#include "lift.cpp"
#include "auton.cpp"
#include <list>
#include <iostream>
#include <stdlib.h>
using namespace pros;
using namespace lemlib;

void initialize() {
	test.reverse();
	lcd::initialize();
	master.clear();


	l_mg.set_brake_mode(E_MOTOR_BRAKE_COAST);
	r_mg.set_brake_mode(E_MOTOR_BRAKE_COAST);
	lift.set_brake_mode(E_MOTOR_BRAKE_COAST);
	intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
	chassis.calibrate();
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
}

void opcontrol() {
	hasStart = true;
}