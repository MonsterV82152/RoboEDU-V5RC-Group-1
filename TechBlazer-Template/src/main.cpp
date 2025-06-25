#include "globals.hpp"
#include "AutonSelector.hpp"
#include "Autonomous_Paths.hpp"

AutonSelector autonSelector;

void on_center_button() {}	

void initialize() {
    pros::screen::erase();
    // pros::screen::set_pen(pros::Color::white); 
    // pros::screen::draw_rect(30,30,120,120);
    pros::delay(1000);
    autonSelector.setAutons({
        {"red", "Red Auton 1", redAuton1},
        {"red", "Red Auton 2", redAuton2},
        {"blue", "Blue Auton 1", blueAuton1},
        {"blue", "Blue Auton 2", blueAuton2}
    });
    autonSelector.start();
    // pros::screen::set_pen(pros::Color::white); 
    // pros::screen::draw_rect(30,30,120,120);
    
    // Code to run when the code is started - initialization code
    
}

void disabled() {}
   
void competition_initialize() {}

void autonomous() {
    // Code to run during the autonomous period
    exampleAuton();
}
 
void opcontrol() {
	while (true) {

        // double rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // double leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        // leftDT.move_velocity(leftY+rightX);
        // rightDT.move_velocity(leftY-rightX);
        
		pros::delay(20);
		
	}
}