#include "TBGlobals.hpp"

class TBTrackingWheel {
    private:
    float wheeldiameter;
    float distance;
    pros::Rotation *rotationalSensor;

    public:
    float getDistance();
    float getWheelDiameter();
    void calibrate();
    TBTrackingWheel(pros::Rotation *Isensor, float Iwheelradius);
};