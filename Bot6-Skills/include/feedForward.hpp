#pragma once
#include <cmath>

class ArmFeedForward {
public:
    ArmFeedForward(double K_G);

    // Feedforward with motion profile inputs
    double update(double thetaDeg);

private:
    double K_G; // gravity gain
};
