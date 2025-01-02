#include "TBGlobals.hpp"

class TBTrackingWheel {
    private:
    float wheeldiameter;
    float distance;
    pros::Rotation *rotationalSensor;

    public:
    float getDistance();
    float getWheelDiameter();
    float getDifference();
    void calibrate();
    TBTrackingWheel(pros::Rotation *Isensor, float Iwheelradius, float Ioffset);
};