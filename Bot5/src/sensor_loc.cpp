#include "sensor_loc.hpp"

SensorLocalizer::SensorLocalizer(std::map<std::string, Vec2> offsets, lemlib::Chassis* ch)
    : sensor_offsets(offsets), chassis(ch) {}

void SensorLocalizer::correct_position_with_sensors(
    std::map<std::string, pros::Distance*> dist_sensors,
    double heading_deg
) {
    std::vector<Vec2> corrected_positions;
    std::vector<double> weights;

    double theta_rad = heading_deg * M_PI / 180.0;
    double x0 = chassis->getPose().x;
    double y0 = chassis->getPose().y;

    for (auto& entry : dist_sensors) {
        const std::string& dir = entry.first;
        pros::Distance* sensor = entry.second;

        double raw_dist = sensor->get();
        if (raw_dist < min_valid || raw_dist > max_valid) continue;

        double wall_heading = wall_normals[dir];
        double phi_deg = fmod(wall_heading - heading_deg + 360.0, 360.0);
        if (phi_deg > 180) phi_deg -= 360;
        double phi_rad = phi_deg * M_PI / 180.0;

        if (std::abs(phi_deg) > 45.0) continue;

        double corrected_dist = raw_dist * cos(phi_rad);

        Vec2 offset = sensor_offsets[dir];
        double offset_x = offset.x * cos(theta_rad) - offset.y * sin(theta_rad);
        double offset_y = offset.x * sin(theta_rad) + offset.y * cos(theta_rad);
        double sensor_x = x0 + offset_x;
        double sensor_y = y0 + offset_y;

        Vec2 predicted;

        if (dir == "front") {
            predicted.y = 72.0 - corrected_dist;
            predicted.x = sensor_x;
        } else if (dir == "back") {
            predicted.y = -72.0 + corrected_dist;
            predicted.x = sensor_x;
        } else if (dir == "left") {
            predicted.x = -72.0 + corrected_dist;
            predicted.y = sensor_y;
        } else if (dir == "right") {
            predicted.x = 72.0 - corrected_dist;
            predicted.y = sensor_y;
        }

        if (std::abs(predicted.x - x0) > correction_threshold ||
            std::abs(predicted.y - y0) > correction_threshold) {
            continue;
        }

        double confidence = cos(phi_rad);
        corrected_positions.push_back(predicted);
        weights.push_back(confidence);
    }

    if (!corrected_positions.empty()) {
        double sum_x = 0, sum_y = 0, total_weight = 0;
        for (size_t i = 0; i < corrected_positions.size(); i++) {
            sum_x += corrected_positions[i].x * weights[i];
            sum_y += corrected_positions[i].y * weights[i];
            total_weight += weights[i];
        }

        double avg_x = sum_x / total_weight;
        double avg_y = sum_y / total_weight;

        chassis->setPose({avg_x, avg_y, chassis->getPose().theta});
    }
}