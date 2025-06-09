#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"


void on_center_button() {}	

void initialize() {
	pros::lcd::initialize();


	pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
        }
    });
	
	chassis.calibrate();
	chassis.setPose(0,0,0);
}

void disabled() {}
   
void competition_initialize() {}

void autonomous() {

}
 
void opcontrol() {
	while (true) {

		pros::delay(20);
		
	}
}