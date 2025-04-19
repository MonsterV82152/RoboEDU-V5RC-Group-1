#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"
#include "classes.hpp"


void on_center_button() {}	

void initialize() {
	pros::lcd::initialize();
	// pros::screen::erase();


	pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to sadve resources
            pros::delay(20);
        }
    });

	// pros::Task(AutonomousSelector, nullptr, "AutonSelector");
	if (500 < potmeterBot.get_value() && potmeterBot.get_value() < 1400) { // skills, point right
		skill = true;
	}

	chassis.calibrate();
	chassis.setPose(0,0,90);
	intake.init();
	ladyBrown.init();
	mogoClampP.init();
	hookTasks.init();
	controls.init();
	pros::delay(500);
	master.rumble(".");
	hookTasks.setDelay(70);
	hookTasks.start();
	controls.start();

}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	autonomousPeriod = true;
	driverControl = false;
	hookTasks.setSorting(true);
	redNeg();
	// chassis.setPose(0,0,0);
	// chassis.turnToHeading(90, 1000);
	// if (team) {
	// 	if (auton == 1) {
			
	// 	} else if (auton == 2) {

	// 	}
	// } else {
	// 	if (auton == 1) {

	// 	} else if (auton == 2) {

	// 	}
	// }
}

void opcontrol() {
	autonomousPeriod = false;
	driverControl = true;
	hookTasks.setSorting(true);	
	chassis.setPose(0,0,0);
	if (skill) {
		ladyBrown.setSetPoint(LadyBrownConfigs::ALLIANCE);
		ladyBrown.waitUntilAtSetpoint(700);
		chassis.moveToPoint(0,-13,700,{false});
		pros::delay(300);
		ladyBrown.setSetPoint(0);
	}
	while (true) {
		controls.driverControls();
		pros::delay(20);
		
	}
}