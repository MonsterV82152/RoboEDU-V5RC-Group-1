#include "main.h"

using namespace pros;
using namespace lemlib;

void ptoFun(void *param) {
	while (true) {
		if (lift.get_position() > 1000 && hasStart) {
			pto.set_value(false);
		} else if (lift.get_position() < 1000 && hasStart) {
			pto.set_value(true);
		}
		delay(20);
	}
}


void pto_() {
}