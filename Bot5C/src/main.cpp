#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"
#include "classes.hpp"


void on_center_button() {}	

void initialize() {
	pros::lcd::initialize();
	pros::screen::erase();


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
	
	chassis.calibrate();
	chassis.setPose(0,0,90);
	intake.init();
	ladyBrown.init();
	mogoClampP.init();
	colourSorter.init();
	controls.init();
	pros::delay(500);
	master.rumble(".");
	colourSorter.setDelay(70);
	colourSorter.start();
	controls.start();

}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	autonomousPeriod = true;
	driverControl = false;
	colourSorter.setSorting(true);
	if (team) {
		if (auton == 1) {
			
		} else if (auton == 2) {

		}
	} else {
		if (auton == 1) {

		} else if (auton == 2) {

		}
	}
}

void opcontrol() {
	autonomousPeriod = false;
	driverControl = true;
	chassis.setPose(30,52,0);
	while (true) {
		controls.driverControls();
		if (master.get_digital_new_press(Controller::button_R1)) {
			double heading = OdometryConfigs::IMU.get_heading();
    		lemlib::Pose newPose = sensorLoc.correct_position_with_sensors();
			pros::lcd::print(3, "X: %f", newPose.x); // x
			pros::lcd::print(4, "Y: %f", newPose.y); // y
			pros::lcd::print(5, "Theta: %f", newPose.theta); // heading
		}
		pros::delay(20);
		
	}
}