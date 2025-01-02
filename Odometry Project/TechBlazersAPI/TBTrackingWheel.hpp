#include "TBGlobals.hpp"

class TBTrackingWheel {
    private:
    float wheelradius;
    pros::Rotation *sensor;

    public:
    float getDistance();
    float getWheelRadius();
    TBTrackingWheel();
}