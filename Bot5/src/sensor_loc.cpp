#ifndef SENSORLOC_CPP
#define SENSORLOC_CPP
#include "pros/distance.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include <math.h>

struct dist_sensor {
    pros::Distance *sensor;
    lemlib::Pose offset;
};

void correct_position(dist_sensor sensor, lemlib::Chassis *chassis, bool x, double correct_rate = 5, bool forced = false) {
    double wall_dist = 70.5;
    lemlib::Pose currentPos = chassis->getPose(true);
    double distanceValue = sensor.sensor->get_distance();
    /*double offset_x = offset.x * cos(theta_rad) - offset.y * sin(theta_rad);
        double offset_y = offset.x * sin(theta_rad) + offset.y * cos(theta_rad);*/
    double offset_y = sensor.offset.x * sin(currentPos.theta) + sensor.offset.y * cos(currentPos.theta);
    double offset_x = sensor.offset.x * cos(currentPos.theta) - sensor.offset.y * sin(currentPos.theta);
    double x_value = distanceValue * sin(currentPos.theta) + offset_x;
    double y_value = distanceValue * cos(currentPos.theta) + offset_y;
    if (x) {
        x_value = wall_dist*x_value/abs(x_value) - x_value;
        if (abs(x_value-currentPos.x) < correct_rate || forced) {
            chassis->setPose(x_value, currentPos.y, currentPos.theta, true);
        }
    } else {
        y_value = wall_dist*y_value/abs(y_value) - y_value;
        if (abs(y_value-currentPos.y) < correct_rate || forced) {
            chassis->setPose(currentPos.x, y_value, currentPos.theta, true);
        }
    }



}

#endif
