#include "main.h"
using namespace pros;
using namespace lemlib;

void intakeFun (void *param) {
	bool newClamp = true;
	bool newDrop = false;
	bool wasLoading = false;
	bool newRej = true;
	int unjam = 0;
	int run = 0;
	int jamCount = 0;
	while (true) {
		// -----------------------------------------unjam--------------------------------------------------
		// if (intake.get_target_velocity() != 0 && abs(intake.get_actual_velocity()) > 10) {
		// 	run += 20;
		// }

		// if ((highStat != 1 || !atTop) && intake.get_target_velocity() != 0 && abs(intake.get_actual_velocity()) < 10) {
		// 	unjam += 20;
		// 	run = 0;
		// } else if (run >= 200) { // IMPORTANT DURATION OF THIS MAY CAUSE CLAMP REVERSE TO INTERFERE
		// 	unjam = 0;
		// 	jamCount = 0;
		// }

		// if (jamCount > 3) {
		// 	intake.move_velocity(0);
		// 	unjam = 0;
		// 	jamCount = 0;
		// 	run = 0;
		// }
		// else if (unjam > 500 + jamCount*50) {
		// 	jamCount += 1;
		// 	int prevSpeed = intake.get_target_velocity();
		// 	intake.move_velocity(550);
		// 	delay(250);
		// 	intake.move_velocity(prevSpeed);
		// }

		if (unjamLB) {
			intake.move_velocity(100);
			delay(300);
			intake.move_velocity(0);
			unjamLB = false;
		}

		// ----------------------------------clamp----------------------------------
		if (clampStat && newClamp) {
			newClamp = false;
			newDrop = true;
			clamp.set_value(true);
			if (intake.get_target_velocity() != 0) {
				int prevSpeed = intake.get_target_velocity();
				intake.move_velocity(600);
				delay(200);
				intake.move_velocity(prevSpeed);
			}
		} else if (!clampStat && newDrop) {
			newClamp = true;
			newDrop = false;
			clamp.set_value(false);
			if (intake.get_target_velocity() != 0) {
				int prevSpeed = intake.get_target_velocity();
				intake.move_velocity(600);
				delay(200);
				intake.move_velocity(prevSpeed);
			}
		}
		// -----------------------------------------color sort---------------------------------------------
		if (dist.get_distance() < 30) {
			atTop = true;
		} else {
			atTop = false;
		}
		
		if (colorMin < optical.get_hue() && optical.get_hue() < colorMax && newRej && colorSort) {
			reject = true;
			newRej = false;
			if (highStat == 1) {
				wasLoading = true;
				highStat = 3;
			}
		}

		if (reject && atTop) {
			reject = false;
			if (wasLoading) {
				wasLoading = false;
				highStat = 1;
			} 
			delay(50);
			intake.move_velocity(0);
			delay(200);
			intake.move_velocity(-550);
			delay(300);
			newRej = true;
		} else if (!reject && highStat == 1 && atTop) {
			intake.move_velocity(-550);
			delay(250);
			intake.move_velocity(0);
		} else if (!reject && highStat != 1 && atTop && holdTop) { // prioritizes color sorting and loading lb
			holdTop = false;
			intake.move_velocity(150);
			delay(500);
			intake.move_velocity(0);
		}

		// master.print(1, 0, atTop ? "at top" : "no top");
		delay(20);

		// print out highStat and reject when running color sort to see if they interfere
	}
}

void intake_() {
	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
		if (intake.get_target_velocity() == -550) {
			intake.move_velocity(0);
		} else {
			intake.move_velocity(-550);
		}
	}
	
	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
		if (intake.get_target_velocity() == 550) {
			intake.move_velocity(0);
		} else {
			intake.move_velocity(550);
		}
	}

	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
		if (holdTop) {
			holdTop = false;
			intake.move_velocity(prevIntSpeed);
		} else if (!holdTop) {
			holdTop = true;
			prevIntSpeed = intake.get_target_velocity();
			intake.move_velocity(-300);
		}
	}
}