#include "main.h"

using namespace pros;
using namespace lemlib;

void printingFun (void *param) {
    while (true) {
        if (!colorSort) {
            master.print(0, 0, "neutral   ");
        } else if (colorSort && colorMax == redMax && colorMin == redMin) {
            master.print(0, 0, "blue team ");
        } else if (colorSort && colorMax == blueMax && colorMin == blueMin) {
            master.print(0, 0, "red team  ");
        } else {
            master.print(0, 0, "error Sort");
        }

        delay(100);

        if (holdTop) {
            master.print(2, 0, "hold");
        } else {
            master.print(2, 0, "    ");
        }
        delay(100);
    }
}

void misc_() {
    
    // if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
    //     chassis.turnToHeading(test, 750);
    //     test += 90;
    // }
	if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)) {
		if(wingStat) {
			wingStat = false;
            wing.set_value(false);
		}
		else {
			wingStat = true;
            wing.set_value(true);
		}
	}

    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
        if (colorSort) {
            colorSort = false;
        } else {
            if (redSide) {
                colorMin = blueMin;
                colorMax = blueMax;
            } else if (!redSide) {
                colorMin = redMin;
                colorMax = redMax;
            }
            colorSort = true;
        }
    }
    
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
        int currX = chassis.getPose().x;
        int currY = chassis.getPose().y;
        chassis.setPose(currX, currY, 0);

        chassis.moveToPose(currX, currY-6.5, 0, 1000);
    }

    // else if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_LEFT)) {
    //     if (colorSort == false) {
    //         if (redSide) {
    //             colorMin = blueMin;
    //             colorMax = blueMax;
    //         } else if (!redSide) {
    //             colorMin = redMin;
    //             colorMax = redMax;
    //         }
    //     } else {
    //         if (colorMax == redMax && colorMin == redMin) {
    //             colorMin = blueMin;
    //             colorMax = blueMax;
    //         } else if (colorMax == blueMax && colorMin == blueMin) {
    //             colorMin = redMin;
    //             colorMax = redMax;
    //         }
    //     }
    //     colorSort = true;
    // }
}
