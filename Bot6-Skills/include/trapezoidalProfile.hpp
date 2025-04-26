#pragma once

class TrapezoidalProfile {
public:
    TrapezoidalProfile(double maxVel, double maxAccel, double maxDecel);

    void generate(double startPos, double goalPos);

    // Call this each cycle with deltaTime (in seconds)
    void update(double dt);

    double getPosition() const;
    double getVelocity() const;
    double getAcceleration() const;
    bool isFinished() const;

private:
    double startPos, goalPos;
    double maxVel, maxAccel, maxDecel;

    double t1, t2, t3; // durations of accel, cruise, decel
    double totalTime;

    double currentTime;

    double position, velocity, acceleration;
};
