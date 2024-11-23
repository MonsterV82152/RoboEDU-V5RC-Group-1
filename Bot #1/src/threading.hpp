#include "main.h"
#include "globals.hpp"

inline void wallstake(void *param)
{
	//Wall Stake Mechanism
	swallMotor.set_encoder_units(MOTOR_ENCODER_DEGREES);
	swallMotor.set_zero_position(0);
	bool wall = false;
	int pos = swallMotor.get_position();
	swallMotor.set_brake_mode(COAST);
	
	while (true)
	{
		if (master.get_digital(button_A)) { // If A is Pressed
			swallMotor.move(127);
			wall = true;
		} else if (wall) {
			swallMotor.move(-127);
			pros::delay(500);
			while (pos > 20) {
				pos = swallMotor.get_position();
				pros::delay(100);
			}
			swallMotor.brake();
			swallMotor.set_brake_mode(COAST);
			wall = false;
		// } else if (master.get_digital(button_RIGHT)) {
		// 	swallMotor.move(127);
		// 	swallMotor.set_brake_mode(BRAKE);
		} else {
			swallMotor.brake();
		}
		if (master.get_digital_new_press(button_LEFT)) {
			right_dr.move_velocity(50);
			left_dr.move_velocity(50);
			pros::delay(300);
			left_dr.brake();
			right_dr.brake();
		}
		pros::delay(100);
	}
}
