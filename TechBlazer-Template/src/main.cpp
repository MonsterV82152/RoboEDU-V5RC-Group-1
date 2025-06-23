#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"


void on_center_button() {}	

void initialize() {
    // Code to run when the code is started - initialization code
	pros::lcd::initialize();
}

void disabled() {}
   
void competition_initialize() {}

void autonomous() {
    // Code to run during the autonomous period
    exampleAuton();
}
 
void opcontrol() {
	while (true) {
        double rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        double leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        leftDT.move_velocity(leftY+rightX);
        rightDT.move_velocity(leftY-rightX);
        
		pros::delay(20);
		
	}
}