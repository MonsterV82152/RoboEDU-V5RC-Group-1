#include "main.h"
using namespace pros;
using namespace lemlib;

void colorCheck (void *param) {
	bool reject = false;
	while (true) {
		if (colorMin < optical.get_hue() && optical.get_hue() < colorMax) {
			reject = true;
		}

		if (reject && top_switch.get_value() == 1) {
			reject = false;
			intake.move_velocity(0);
			intake.move_velocity(600);
			delay(400);
			intake.move_velocity(-600);
		}
		delay(20);
	}
}

void intakeMode (void *param) {
	bool flag = false;
	while (true) {
		if (hasStart) {
			intakeTask.suspend();
		}
		if (redMin < optical.get_hue() && optical.get_hue() < redMax || blueMin < optical.get_hue() && optical.get_hue() < blueMax){
			intake.move_velocity(-200);
			flag = true;
		}
		if (flag && top_switch.get_value() == 1) {
			intake.move_velocity(300);
			delay(1500);
			intake.move_velocity(-600);
			flag = false;
			liftState = 1;
			master.print(0, 0, "les");
			intakeTask.resume();
			highIntakeTask.suspend();
		}
		if (flag) {
			liftState = 0;
		}
		delay(20);
	}
}



void intake_() {
	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1)) {
		if(intakeStat && intakeDir && !hasIntakeThread) {
			intakeTask.suspend();
			intake.move_velocity(0);
			intakeStat = false;	
		}
		else {
			// the location of the resume may cause issues, watch out
			intakeTask.resume();
			intake.move_velocity(-600);
			intakeStat = true;
			intakeDir = true;
		}	
	}
	else if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_R2)) {
		if(intakeStat && !intakeDir) {
			intakeTask.suspend();
			intake.move_velocity(0);
			intakeStat = false;
		}
		else {
			intakeTask.suspend();
			intake.move_velocity(600);
			intakeStat = true;
			intakeDir = false;
		}
	} 
	else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_B)) {
		if (highIntakeTask.get_state() != E_TASK_STATE_SUSPENDED) {
			highIntakeTask.suspend();
			intakeTask.resume();
			master.print(0, 0, "les");
		} 
		else if (highIntakeTask.get_state() == E_TASK_STATE_SUSPENDED) {
			highIntakeTask.resume();
			intakeTask.suspend();
			master.print(0, 0, "gay");
		} 
	}
	// if (highIntakeTask.get_state() != E_TASK_STATE_SUSPENDED) {
		
	// }
	// else if (highIntakeTask.get_state() == E_TASK_STATE_SUSPENDED) {
	// 	master.print(0, 0, "les");
	// }
}