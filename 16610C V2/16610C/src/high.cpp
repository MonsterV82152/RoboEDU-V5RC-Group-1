#include "main.h"
using namespace pros;
using namespace lemlib;

void highFun(void *param) {
    while (true) {
        if (highStat == 0) {
            intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
            tar = tar0;
        } else if (highStat == 1) {
            intake.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
            tar = tar1;
        } else if (highStat == 2) {
            intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
            tar = tar2;
			if (prevHigh == 1) {
				unjamLB = true;
			}
        } else if (highStat == 3) {
            intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
            tar = tar3;
			if (prevHigh == 1) {
				unjamLB = true;
			}
        } else if (highStat == 4) {
            intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
            tar = tar4;
			if (prevHigh == 1) {
				unjamLB = true;
			}
        } else if (highStat == 5) {
            intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
            tar = tar5;
			if (prevHigh == 1) {
				unjamLB = true;
			}
        }
		prevHigh = highStat;

        if (highStat == 2) {
            high.move_velocity(highPIDGay.update(tar - highPot.get_value()) * dir);
        } else {
            high.move_velocity(highPID.update(tar - highPot.get_value()) * dir);
        }
        delay(20);
    }
}

void high_() {
    if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_DOWN)) {
		if (highStat == 1) {
			highStat = 0;
		} else {
			highStat = 1;
		}
	}

	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
		if (highStat == 2) {
			highStat = 0;
		} else {
			// if (highStat == 1) {
			// 	unjamLB = true;
			// }
			highStat = 2;
		}
	}
	

	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
		if (highStat == 3) {
			highStat = 0;
		} else {
			// if (highStat == 1) {
			// 	unjamLB = true;
			// }
			highStat = 3;
			
		}
	}
	if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
		if (skill) {
			pros::Task([&] () {
				highStat = 3;
				pros::delay(300);
				highStat = 1;
				pros::delay(400);
				intake.move_velocity(-550);
				while (dist.get_distance() > 30) {
					pros::delay(10);
				}
				pros::delay(100);
				intake.move_velocity(0);
				highStat = 3;
				pros::delay(400);
				highStat = 0;

			});
		}
	}
    if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_L2)) {
		if (highStat == 4) {
			highStat = 0;
		} else {
			// if (highStat == 1) {
			// 	unjamLB = true;
			// }
			highStat = 4;
		}
	}

	// if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_Y)) {
	// 	if (highStat == 5) {
	// 		highStat = 0;
	// 	} else {
	// 		// if (highStat == 1) {
	// 		// 	unjamLB = true;
	// 		// }
	// 		highStat = 5;
	// 	}
	// }

    //-------------------------------------------pid stuff-----------------------------------

}