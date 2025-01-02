#include "main.h"

using namespace pros;
using namespace lemlib;

void clampFun(void *param) {
	bool newClamp = true;
	while (true) {
		if (clampStat && newClamp) {
			newClamp = false;
			int speed = intake.get_target_velocity();
			intake.move_velocity(100);
			clamp.set_value(true);
			delay(750);
			intake.move_velocity(speed);
		} else if (clampStat == false) {
			newClamp = true;
			clamp.set_value(false);
		}
		delay(20);
	}
}

void clamp_() {
	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
		if(clampStat) {
			clampStat = false;
		}
		else {
			clampStat = true;
		}
	}
}