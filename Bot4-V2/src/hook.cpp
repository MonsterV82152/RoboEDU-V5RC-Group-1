#include "globals.hpp"

#ifndef HOOK_CPP
#define HOOK_CPP

class Hook {
    private:
        double defaultSpeed = 0;
        double currentSpeed = 0;
        double overwriteSpeed = 0;
        double overwriteCountdown = 0;
        bool isOverwrite = false;
        bool isMoving = false;
    public:
        Hook() {
            pros::Motor hook(PORT_hook);
        }
        void setSpeed(double speed) {
            defaultSpeed = speed;
        }
        void setOverwriteSpeed(double speed, int countdown) {
            overwriteSpeed = speed;
            overwriteCountdown = countdown;
            isOverwrite = true;
        }
        void update() {
            if (isOverwrite) {
                if (overwriteCountdown > 0) {
                    overwriteCountdown = overwriteCountdown - cycleSpeeds;
                    hook.move(overwriteSpeed);
                } else {
                    isOverwrite = false;
                }
            } else {
                hook.move(defaultSpeed);
            }
            currentSpeed = hook.get_actual_velocity();
            if (abs(currentSpeed) > 5) {
                isMoving = true;
            } else {
                isMoving = false;
            }
        }
        bool getIsMoving() {
            return isMoving;
        }
        double getSpeed() {
            return currentSpeed;
        }
        double getOverwriteSpeed() {
            if (isOverwrite) {
                return overwriteSpeed;
            } else {
                return 0;
            }
        }
        double getDefaultSpeed() {
            return defaultSpeed;
        }
        void stop() {
            defaultSpeed = 0;
        }
};


#endif