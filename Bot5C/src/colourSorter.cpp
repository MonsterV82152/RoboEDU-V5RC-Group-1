#ifndef COLOURSORTER_CPP
#define COLOURSORTER_CPP

#include "globals.hpp"
#include "intake.cpp"

class ColourSorter {
    private:
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Task *sorterTask;
        bool shouldSort;
        int rings[3] = {0, 0, 0};
        int delayTime;
        int reverseCountdown;


        static constexpr int BLUE_HUE_MIN = 180;
        static constexpr int BLUE_HUE_MAX = 230;
        static constexpr int RED_HUE_MIN = 350;
        static constexpr int RED_HUE_MAX = 20;

        void multiThread(void *param) {
            while (true) {
                int hue = colourSensor->get_hue();
                if (shouldSort) {
                    if (team && hue > BLUE_HUE_MIN && hue < BLUE_HUE_MAX) {
                        pros::delay(delayTime);
                        if ((rings[0]-1) == !team && shouldSort) {intake->waitUntilRotations(0.5); intake->setOverwriteSpeed(-10, reverseCountdown);}
                        master.rumble(".");
                        pros::delay(100);
                    } else if (!team && (hue > RED_HUE_MIN || hue < RED_HUE_MAX)) {
                        pros::delay(delayTime);
                        if ((rings[0]-1) == !team && shouldSort) {intake->waitUntilRotations(0.5); intake->setOverwriteSpeed(-10, reverseCountdown);}
                        master.rumble(".");
                        pros::delay(100);
                    }
                }
                

                pros::delay(10); // Add a delay to prevent the loop from running too fast
            }
        }

    public:
        ColourSorter(Intake *intake, pros::Optical *colourSensor, int delay)
            : intake(intake), colourSensor(colourSensor), sorterTask(nullptr), shouldSort(false), delayTime(delay), reverseCountdown(5) {}

        void setDelay(int delay) {
            this->delayTime = delay;
        }

        void init() {
            colourSensor->set_led_pwm(100);
            sorterTask = new pros::Task([this] { multiThread(nullptr); }, 8, 8192, "colour");
            sorterTask->suspend();
        }

        void start() {
            sorterTask = new pros::Task([this] { multiThread(nullptr); }, 8, 8192, "colour");
        }


        void stop() {
            if (sorterTask != nullptr) {
                sorterTask->suspend();
            }
        }

        void setSorting(bool state) {
            shouldSort = state;
        }



        bool isRunning() {
            return sorterTask->get_state() == pros::E_TASK_STATE_RUNNING;
        }
        bool isSorting() {
            return shouldSort;
        }


        ~ColourSorter() {
            if (sorterTask != nullptr) {
                sorterTask->remove();
                delete sorterTask;
            }
        }
};

#endif