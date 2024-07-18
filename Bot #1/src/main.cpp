#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::ADIDigitalOut clawp ('A');
	pros::Motor intake(-5);
	pros::Motor hook(-17);
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::MotorGroup left_mg({-1, -2, -3});    // Creates a motor group with forwards ports 1 & 3 and reversed port 2
	pros::MotorGroup right_mg({10, 6, 7});  // Creates a motor group with forwards port 5 and reversed ports 4 & 6
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	left_mg.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	right_mg.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	bool boolintake = false;
	bool boolhook = false;

	while (true) {
		int dir = master.get_analog(ANALOG_LEFT_Y);
		int turn = master.get_analog(ANALOG_RIGHT_Y);
		left_mg.move(dir);
		right_mg.move(turn);
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
			
			if (boolintake) {
				intake.move(127);
			} else {
				intake.brake();
			}

			boolintake = !boolintake;

		}
				
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			if (boolhook) {
				hook.move(127);
			} else {
				hook.brake();
			}
			
			boolhook = !boolhook;

		}

	pros::delay(20);  
	}
	// int intakecooldown = 25;
	// int clawcooldown = 25;
	// bool boolintake = false;
	// bool claw = false;
	// while (true) {
	// 	pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  // Prints status of the emulated screen LCDs



	// 	if (intakecooldown != 0) {
	// 		intakecooldown = intakecooldown-1;
	// 		//pros::lcd::set_text(1, intakecooldown);
	// 		}
	// 	if (clawcooldown != 0) {
	// 		clawcooldown = clawcooldown-1;
	// 		}

	// 	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == true and intakecooldown == 0) {
	// 		boolintake = !boolintake;
	// 		intakecooldown = 25;
	// 	}
	// 	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A) == true and clawcooldown == 0) {
	// 		bool claw = !claw;
	// 		if (claw) {
	// 			clawp.set_value(true);
	// 		}
	// 		else {
	// 			clawp.set_value(false);
	// 		}
	// 		clawcooldown = 25;
	// 	}
		  // Gets the turn left/right from right joystick
	// 	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
	// 		intake.move(-127);
	// 	}
	// 	else if (boolintake) {
	// 		intake.move(127);
	// 	}
	// 	else {
	// 		intake.brake();
	// 	}
	// 	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
	// 		fourbar.move(127);
	// 	}
	// 	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
	// 		fourbar.move(-127);
	// 	}
	// 	else {
	// 		fourbar.brake();
	// 	}
	// 	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
	// 		fourbar.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	// 	}
	// 	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
	// 		fourbar.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	// 	}
		                  // Sets right motor voltage
	// 	                             // Run for 20 ms then update
	// }
}