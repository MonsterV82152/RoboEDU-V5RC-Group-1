#include "main.h"

using namespace pros;
using namespace lemlib;

void liftFun (void *param) {
	// just added this to a thread instead so that it is usable during skills and auton
	while (true) {
		if (!hasStart) {
			lift.move_velocity(0);
		} else if (liftState == 0 && 100 < lift.get_position()) {
			lift.set_brake_mode(MOTOR_BRAKE_COAST);
			lift.move_velocity(-100);
		} else if (liftState == 1 && !(200 < lift.get_position() && lift.get_position() < 400)) {
			lift.set_brake_mode(MOTOR_BRAKE_HOLD);
			lift.move_velocity(sgn(300-lift.get_position())*100);
		} else if (liftState == 2 && !(1200 < lift.get_position() && lift.get_position() < 1400)) {
			lift.set_brake_mode(MOTOR_BRAKE_HOLD);
			lift.move_velocity(sgn(1300-lift.get_position())*100);
		} else if (liftState == 3 && !(2000 < lift.get_position() && lift.get_position() < 2200)) {
			lift.set_brake_mode(MOTOR_BRAKE_HOLD);
			lift.move_velocity(sgn(2100-lift.get_position())*100);
		} else if (liftState == 4 && !(600 < lift.get_position() && lift.get_position() < 800)) {
			lift.set_brake_mode(MOTOR_BRAKE_HOLD);
			lift.move_velocity(sgn(700-lift.get_position())*100);
		} else {
			lift.move_velocity(0);
		}
		delay(20);
		// Position Update
	
	}
}


void lift_() {
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) {
		if (liftState == 3) {
			liftState = 1;
		} else {
			liftState = 3;
		}
	}
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
		if (liftState == 2) {
			liftState = 1;
		} else {
			liftState = 2;
		}
	}


}
