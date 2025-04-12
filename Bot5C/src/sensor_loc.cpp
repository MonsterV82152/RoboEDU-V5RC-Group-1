#include "sensor_loc.hpp"


SensorLocalizer::SensorLocalizer(std::map<pros::Distance*, Vec3> sensors, lemlib::Chassis* ch)
    : sensor_list(sensors), chassis(ch) {}

lemlib::Pose SensorLocalizer::correct_position_with_sensors() {
    std::vector<Vec2> cases;

    double theta_rad = chassis->getPose().theta * M_PI / 180.0;
    double theta = chassis->getPose().theta;
    double x0 = chassis->getPose().x;
    double y0 = chassis->getPose().y;

    for (auto& entry : sensor_list) {
        pros::Distance* sensor = entry.first;
        Vec3 position = entry.second;

        double raw_dist = sensor->get_distance()*0.0393701;
        if (raw_dist > max_valid) continue;

        double offset_x = position.x * cos(theta_rad) - position.y * sin(theta_rad);
        double offset_y = position.x * sin(theta_rad) + position.y * cos(theta_rad);

        double x_value = raw_dist * sin(theta+position.theta) + offset_x;
        double y_value = raw_dist * cos(theta+position.theta) + offset_y;

        cases.push_back({x_value, y_value});
    }

    double actualX = chassis->getPose().x;
    double actualY = chassis->getPose().y;

    for(int i=0; i<cases.size(); i++){
        for(int j=i+1; j<cases.size(); j++){
            if(cases[i].x == cases[j].x && cases[i].y == cases[j].y) continue;
            if (abs(abs(cases[i].x-cases[j].x)-fieldSize) < correction_threshold) {
                if (abs(cases[i].x) < abs(cases[j].x)) {
                    actualX = fieldSize+cases[i].x;
                } else {
                    actualX = fieldSize+cases[j].x;
                }
                if (actualX > fieldSize) {
                    actualX -= fieldSize;
                }
                actualX -= fieldSize/2;
            }
            if (abs(abs(cases[i].y-cases[j].y)-fieldSize) < correction_threshold) {
                if (abs(cases[i].y) < abs(cases[j].y)) {
                    actualX = fieldSize+cases[i].y;
                } else {
                    actualX = fieldSize+cases[j].y;
                }
                if (actualX > fieldSize) {
                    actualX -= fieldSize;
                }
                actualX -= fieldSize/2;
            }

        }
    }






    chassis->setPose(actualX,actualY,theta);
    return lemlib::Pose(actualX, actualY, theta);
    
}