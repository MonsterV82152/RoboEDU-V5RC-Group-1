#include "feedForward.hpp"

ArmFeedForward::ArmFeedForward(double K_G)
    : K_G(K_G) {}

double ArmFeedForward::update(double thetaDeg) {
    double thetaRad = thetaDeg * (M_PI / 180.0);

    double gravityComp = K_G * cos(thetaRad);

    return gravityComp;
}
