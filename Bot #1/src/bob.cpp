#include "main.h"
#include "globals.hpp"
// #include "odometry.hpp"

inline void bobprogram() {
    right_mg.set_zero_position(0);
    left_mg.set_zero_position(0);
    double distance = ((left_mg.get_position()+right_mg.get_position())/2)/360*3/5*3.25*PI;
    left_mg.set_brake_mode(BRAKE);
    right_mg.set_brake_mode(BRAKE);
    left_mg.move_velocity(-600);
    right_mg.move_velocity(-600);
    while (distance > -8.5) {
        distance = ((left_mg.get_position()+right_mg.get_position())/2)/360*3/5*3.25*PI;
        pros::delay(10);
    }
    left_mg.move_velocity(-250);
    while (distance > -22.5) {
        distance = ((left_mg.get_position()+right_mg.get_position())/2)/360*3/5*3.25*PI;
        pros::delay(10);
    }
    left_mg.move_velocity(-600);
    right_mg.move_velocity(-250);
    while (distance > -43.5) {
        distance = ((left_mg.get_position()+right_mg.get_position())/2)/360*3/5*3.25*PI;
        pros::delay(10);
    }
    clawp.set_value(true);
    left_mg.brake();
    right_mg.brake();
    pros::delay(100);
    right_mg.move(127);
    left_mg.move(0);
    pros::delay(200);
    right_mg.move(127);
    left_mg.move(127);
    pros::delay(500);
    left_mg.brake();
    right_mg.brake();

}


