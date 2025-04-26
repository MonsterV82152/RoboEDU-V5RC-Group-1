#include "trapezoidalProfile.hpp"
#include <cmath>
#include <algorithm>

TrapezoidalProfile::TrapezoidalProfile(double maxVel, double maxAccel, double maxDecel)
    : maxVel(maxVel), maxAccel(maxAccel), maxDecel(maxDecel), currentTime(0),
      position(0), velocity(0), acceleration(0) {}

void TrapezoidalProfile::generate(double startPos, double goalPos) {
    this->startPos = startPos;
    this->goalPos = goalPos;
    currentTime = 0;

    double dist = goalPos - startPos;
    double accelTime = maxVel / maxAccel;
    double decelTime = maxVel / maxDecel;
    double accelDist = 0.5 * maxAccel * accelTime * accelTime;
    double decelDist = 0.5 * maxDecel * decelTime * decelTime;

    if (accelDist+decelDist > std::abs(dist)) {
        accelTime = std::sqrt(std::abs(dist) / maxAccel);
        decelTime = std::sqrt(std::abs(dist) / maxDecel);
        t1 = accelTime;
        t2 = 0;
        t3 = decelTime;
    } else {
        double cruiseDist = std::abs(dist) - accelDist+decelDist;
        double cruiseTime = cruiseDist / maxVel;
        t1 = accelTime;
        t2 = cruiseTime;
        t3 = decelTime;
    }

    totalTime = t1 + t2 + t3;
}

void TrapezoidalProfile::update(double dt) {
    currentTime += dt;
    double t = currentTime;
    double dir = (goalPos > startPos) ? 1.0 : -1.0;

    if (t < t1) {
        acceleration = dir * maxAccel;
        velocity = acceleration * t;
        position = startPos + 0.5 * acceleration * t * t;
    } else 
    if (t < t1 + t2) {
        acceleration = 0;
        velocity = dir * maxVel;
        position = startPos + dir * (0.5 * maxAccel * t1 * t1 + maxVel * (t - t1));
    } else if (t < totalTime) {
        double td = t - t1 - t2;
        acceleration = -dir * maxDecel;
        velocity = dir * maxVel - maxDecel * td;
        position = goalPos - 0.5 * dir * maxDecel * (totalTime - t) * (totalTime - t);
    } else {
        acceleration = 0;
        velocity = 0;
        position = goalPos;
    }
}

double TrapezoidalProfile::getPosition() const { return position; }
double TrapezoidalProfile::getVelocity() const { return velocity; }
double TrapezoidalProfile::getAcceleration() const { return acceleration; }
bool TrapezoidalProfile::isFinished() const { return currentTime >= totalTime; }