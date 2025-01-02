#include "globals.hpp"
#include "MovFunc.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"

void on_center_button() {
	
}	

void initialize() {
	
	pros::screen::erase();
	// Initializes
	MotorInit();
	SensorInit();
	pros::Task(mainWhileLoop, nullptr, "mainWhileLoop");
	pros::Task(ColourSorter, nullptr, "Colour");
	chassis.calibrate();
	}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	SkillsAuton();
}

void opcontrol() {
	driverControl = true;
	
	while (true) {
		// // Main While Loop

		// // Runs MovFunc Commands
		// mainMovement();
		// LadyBrown();
		// pnumatics();

		// // Run for 20 ms then update
		pros::delay(20);
		
	}
}