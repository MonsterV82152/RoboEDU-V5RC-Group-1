#include "TBTrackingWheel.hpp"

TBTrackingWheel::TBTrackingWheel(pros::Rotation *Isensor, float Iwheeldiameter, float Ioffset) {
    wheeldiameter = Iwheeldiameter;
    rotationalSensor = Isensor;
    distance = 0;
}

float TBTrackingWheel::getDistance() {
    return rotationalSensor->get_angle()/360 * wheeldiameter * PI;
}

float TBTrackingWheel::getDifference() {
    float newDistance = rotationalSensor->get_angle()/360 * wheeldiameter * PI;
    float difference = newDistance-distance;
    distance = newDistance;
    return difference;
}

float TBTrackingWheel::getWheelDiameter() {
    return wheeldiameter;
}

void TBTrackingWheel::calibrate() {
    rotationalSensor->reset();
    rotationalSensor->reset_position();
}