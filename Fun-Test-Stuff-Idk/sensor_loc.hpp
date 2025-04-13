#ifndef SENSOR_LOC_HPP
#define SENSOR_LOC_HPP

#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "pros/distance.hpp"

struct Vec3
{
    double x;
    double y;
    double theta;
};
struct Vec2
{
    double x;
    double y;
};

class SensorLocalizer
{
private:
    std::map<pros::Distance *, Vec3> sensor_list;
    double min_valid = 3.0;
    double max_valid = 144.0;
    double correction_threshold = 8.0;
    double fieldSize = 141;
    lemlib::Chassis *chassis;

public:
    SensorLocalizer(std::map<pros::Distance *, Vec3> sensors, lemlib::Chassis *ch);

    lemlib::Pose correct_position_with_sensors();
};

#endif