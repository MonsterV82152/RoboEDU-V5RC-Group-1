#include "TBGlobals.hpp"

class TBTrackingWheel {
    private:
    float wheelradius;
    PROS::Rotation *sensor;

    public:
    float getDistance();
    float getWheelRadius();
    TBTrackingWheel();
}