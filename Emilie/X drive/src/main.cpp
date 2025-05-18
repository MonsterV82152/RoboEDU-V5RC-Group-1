#include "main.h"

#include "pros/adi.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "pros/adi.hpp"


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
 *//* 
void opcontrol() {
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    
    // Create motor objects
    pros::Motor FrontRight(2); // Port 1
    pros::Motor BackRight(19);  // Port 2
    pros::Motor BackLeft(20);   // Port 3
    pros::Motor FrontLeft(4);  // Port 4

    while (true) {
        // Arcade control scheme for X drive on right joystick
        int ch3 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y); // Forward/Backward (Y-axis of right joystick)
        int ch4 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); // Strafing (X-axis of right joystick)
        
        // Turn using left and right buttons
        int turn = 0;
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            turn = -100;  // Turn left (negative speed)
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            turn = 100;   // Turn right (positive speed)
        }

        // Calculate the motor speeds for each motor
        int frontLeftSpeed = ch3 + ch4 + turn;
        int frontRightSpeed = ch3 - ch4 - turn;
        int backLeftSpeed = ch3 - ch4 + turn;
        int backRightSpeed = ch3 + ch4 - turn;

        // Set the motor speeds
        FrontRight.move_velocity(frontRightSpeed);
        BackRight.move_velocity(backRightSpeed);
        BackLeft.move_velocity(backLeftSpeed);
        FrontLeft.move_velocity(frontLeftSpeed);

        pros::delay(10);  // Small delay for control update rate
    }
}

 */
/* 
void opcontrol() {
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    
    // Create motor objects
    pros::Motor FrontRight(-2);  // Port 1
    pros::Motor BackRight(-19);  // Port 2
    pros::Motor BackLeft(20);   // Port 3
    pros::Motor FrontLeft(4);   // Port 4

    while (true) {
        // Initialize motor speeds for all directions (starting at 0)
        int frontLeftSpeed = 0;
        int frontRightSpeed = 0;
        int backLeftSpeed = 0;
        int backRightSpeed = 0;

        // Get Right Joystick inputs for X-drive
        int ch3 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y); // Forward/Backward (Y-axis of right joystick)
        int ch4 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); // Strafing (X-axis of right joystick)

        // Use buttons for movement (8 buttons + diagonal control)
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            // Move forward
            frontLeftSpeed = 100;
            frontRightSpeed = 100;
            backLeftSpeed = 100;
            backRightSpeed = 100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            // Move backward
            frontLeftSpeed = -100;
            frontRightSpeed = -100;
            backLeftSpeed = -100;
            backRightSpeed = -100;
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            // Strafe left
            frontLeftSpeed = -100;
            frontRightSpeed = 100;
            backLeftSpeed = 100;
            backRightSpeed = -100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            // Strafe right
            frontLeftSpeed = 100;
            frontRightSpeed = -100;
            backLeftSpeed = -100;
            backRightSpeed = 100;
        }

        // Diagonal movements
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            // Move forward-left (diagonal)
            frontLeftSpeed = 100;
            frontRightSpeed = 0;
            backLeftSpeed = 0;
            backRightSpeed = 100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            // Move forward-right (diagonal)
            frontLeftSpeed = 0;
            frontRightSpeed = 100;
            backLeftSpeed = 100;
            backRightSpeed = 0;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            // Move backward-left (diagonal)
            frontLeftSpeed = -100;
            frontRightSpeed = 0;
            backLeftSpeed = 0;
            backRightSpeed = -100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            // Move backward-right (diagonal)
            frontLeftSpeed = 0;
            frontRightSpeed = -100;
            backLeftSpeed = -100;
            backRightSpeed = 0;
        }

        // Now use the right joystick for X-drive
        // Add X-drive control logic for forward/backward and strafing
        frontLeftSpeed += ch3 + ch4;
        frontRightSpeed += ch3 - ch4;
        backLeftSpeed += ch3 - ch4;
        backRightSpeed += ch3 + ch4;

        // Set the motor speeds
        FrontRight.move_velocity(frontRightSpeed);
        BackRight.move_velocity(backRightSpeed);
        BackLeft.move_velocity(backLeftSpeed);
        FrontLeft.move_velocity(frontLeftSpeed);

        pros::delay(10);  // Small delay for control update rate
    }
}

 */

void opcontrol() {
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    
    // Create motor objects
    pros::Motor FrontRight(-2);  // Port 1
    pros::Motor BackRight(-19);  // Port 2
    pros::Motor BackLeft(20);   // Port 3
    pros::Motor FrontLeft(4);   // Port 4

    while (true) {
        // Initialize motor speeds for all directions (starting at 0)
        int frontLeftSpeed = 0;
        int frontRightSpeed = 0;
        int backLeftSpeed = 0;
        int backRightSpeed = 0;

        // Get left Joystick inputs for X-drive
        int ch3 = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y); // Forward/Backward (Y-axis of right joystick)
        int ch4 = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); // Strafing (X-axis of right joystick)

        // Use buttons for movement (8 buttons + diagonal control)
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            // Move forward
            frontLeftSpeed = 100;
            frontRightSpeed = 100;
            backLeftSpeed = 100;
            backRightSpeed = 100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            // Move backward
            frontLeftSpeed = -100;
            frontRightSpeed = -100;
            backLeftSpeed = -100;
            backRightSpeed = -100;
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            // Strafe left
            frontLeftSpeed = -100;
            frontRightSpeed = 100;
            backLeftSpeed = 100;
            backRightSpeed = -100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            // Strafe right
            frontLeftSpeed = 100;
            frontRightSpeed = -100;
            backLeftSpeed = -100;
            backRightSpeed = 100;
        }

        // Diagonal movements
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            // Move forward-left (diagonal)
            frontLeftSpeed = 100;
            frontRightSpeed = 0;
            backLeftSpeed = 0;
            backRightSpeed = 100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            // Move forward-right (diagonal)
            frontLeftSpeed = 0;
            frontRightSpeed = 100;
            backLeftSpeed = 100;
            backRightSpeed = 0;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            // Move backward-left (diagonal)
            frontLeftSpeed = -100;
            frontRightSpeed = 0;
            backLeftSpeed = 0;
            backRightSpeed = -100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            // Move backward-right (diagonal)
            frontLeftSpeed = 0;
            frontRightSpeed = -100;
            backLeftSpeed = -100;
            backRightSpeed = 0;
        }

        // Rotation with A and Y buttons
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            // Rotate clockwise (A button)
            frontLeftSpeed = 100;
            frontRightSpeed = -100;
            backLeftSpeed = 100;
            backRightSpeed = -100;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
            // Rotate counterclockwise (Y button)
            frontLeftSpeed = -100;
            frontRightSpeed = 100;
            backLeftSpeed = -100;
            backRightSpeed = 100;
        }

        // Now use the right joystick for X-drive
        // Add X-drive control logic for forward/backward and strafing
        frontLeftSpeed += ch3 + ch4;
        frontRightSpeed += ch3 - ch4;
        backLeftSpeed += ch3 - ch4;
        backRightSpeed += ch3 + ch4;

        // Set the motor speeds
        FrontRight.move_velocity(frontRightSpeed);
        BackRight.move_velocity(backRightSpeed);
        BackLeft.move_velocity(backLeftSpeed);
        FrontLeft.move_velocity(frontLeftSpeed);

        pros::delay(10);  // Small delay for control update rate
    }
}
