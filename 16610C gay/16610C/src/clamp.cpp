#include "main.h"

using namespace pros;
using namespace lemlib;

void clamp_() {
	// if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_X)) {
	// 	if(clampStat) {
	// 		clampStat = false;
	// 	}
	// 	else {
	// 		clampStat = true;
	// 	}
	// }
	if(master.get_digital(E_CONTROLLER_DIGITAL_R2)) {
		clampStat = false;
	} else {
		clampStat = true;
	}
}