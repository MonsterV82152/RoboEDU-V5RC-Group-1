#include "globals.hpp"
#include "hook.cpp"
#include "intake.cpp"

#ifndef COLOURSORTER_CPP
#define COLOURSORTER_CPP

class ColourSorter {
    private:
        Hook *hook;
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Distance *distanceSensor;
        pros::Task *sorterTask;
        int rings[3] = {0, 0, 0};
        int delayTime;
        int reverseCountdown;
        bool noRing;
        bool firstDetection;
        int lastColor;

        static constexpr int BLUE_HUE_MIN = 130;
        static constexpr int BLUE_HUE_MAX = 230;
        static constexpr int RED_HUE_MIN = 310;
        static constexpr int RED_HUE_MAX = 50;
        static constexpr int DISTANCE_THRESHOLD = 50;

        void multiThread(void *param) {
            while (true) {
                int hue = colourSensor->get_hue();
                int color = 0;
                if ((hue > BLUE_HUE_MIN && hue < BLUE_HUE_MAX)) {
                    color = 1; // Blue
                } else if ((hue > RED_HUE_MIN || hue < RED_HUE_MAX)) {
                    color = 2; // Red
                } else {
                    lastColor = 0; // No ring
                }

                if (color != 0 && color != lastColor) {
                    if (intake->getSpeed() <= 0) {
                        clearRing();
                    } else {
                        addRing(color);
                        master.rumble(".");
                    }
                    lastColor = color;
                }

                if (distanceSensor->get() < DISTANCE_THRESHOLD) {
                    if (firstDetection) {
                        pros::delay(delayTime);
                        if ((rings[0]-1) == !team) hook->setOverwriteSpeed(-10, reverseCountdown);
                        removeFirstRing();
                        master.rumble(".");
                        firstDetection = false;
                        pros::delay(100);
                    }
                } else {
                    firstDetection = true;
                }

                pros::delay(20); // Add a delay to prevent the loop from running too fast
            }
        }

    public:
        ColourSorter(Hook *hook, Intake *intake, pros::Optical *colourSensor, pros::Distance *distanceSensor, int delay)
            : hook(hook), intake(intake), colourSensor(colourSensor), distanceSensor(distanceSensor), sorterTask(nullptr), delayTime(delay), noRing(true), firstDetection(true), reverseCountdown(5), lastColor(0) {}

        void setDelay(int delay) {
            this->delayTime = delay;
        }

        void clearRing() {
            if (rings[2] != 0) {
                rings[2] = 0;
            } else if (rings[1] != 0) {
                rings[1] = 0;
            } else {
                rings[0] = 0;
            }
        }

        void addRing(int color) {
            if (rings[0] == 0) {
                rings[0] = color;
            } else if (rings[1] == 0) {
                rings[1] = color;
            } else {
                rings[2] = color;
            }
        }

        void removeFirstRing() {
            rings[0] = rings[1];
            rings[1] = rings[2];
            rings[2] = 0;
        }

        int getRing(int index) {
            return rings[index];
        }

        void init() {
            colourSensor->set_led_pwm(100);
            sorterTask = new pros::Task([this] { multiThread(nullptr); });
            sorterTask->suspend();
        }

        void start() {
            if (sorterTask == nullptr) {
                sorterTask = new pros::Task([this] { multiThread(nullptr); });
            } else {
                sorterTask->resume();
            }
        }


        void stop() {
            if (sorterTask != nullptr) {
                sorterTask->suspend();
            }
        }

        bool isRunning() {
            return sorterTask->get_state() == pros::E_TASK_STATE_RUNNING;
        }

        ~ColourSorter() {
            if (sorterTask != nullptr) {
                sorterTask->remove();
                delete sorterTask;
            }
        }
};

#endif