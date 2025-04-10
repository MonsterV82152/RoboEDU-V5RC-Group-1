#pragma once

#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "lemlib/chassis/chassis.hpp"
#include "pros/distance.hpp"

struct Vec2 {
    double x;
    double y;
};

class SensorLocalizer {
private:
    std::map<std::string, Vec2> sensor_offsets;
    double min_valid = 3.0;
    double max_valid = 144.0;
    double correction_threshold = 8.0;
    lemlib::Chassis* chassis;

    std::map<std::string, double> wall_normals = {
        {"front", 0.0},
        {"back", 180.0},
        {"left", 270.0},
        {"right", 90.0}
    };

public:
    SensorLocalizer(std::map<std::string, Vec2> offsets, lemlib::Chassis* ch);

    void correct_position_with_sensors(
        std::map<std::string, pros::Distance*> dist_sensors,
        double heading_deg
    );
};
