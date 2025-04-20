#include "globals.hpp"
#include "intake.cpp"

#ifndef COLOURSORTER_CPP
#define COLOURSORTER_CPP

class HookTasks {
    private:
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Distance *distanceSensor;
        pros::Task sorterTask;
        bool shouldSort;
        bool shouldUnjam;
        int rings[3] = {0, 0, 0};
        int delayTime;
        int reverseCountdown;


        static constexpr int BLUE_HUE_MIN = 180;
        static constexpr int BLUE_HUE_MAX = 230;
        static constexpr int RED_HUE_MIN = 350;
        static constexpr int RED_HUE_MAX = 20;

        void multiThread() {
            while (true) {
                int hue = colourSensor->get_hue();
                if (shouldSort) {
                    if (team && hue > BLUE_HUE_MIN && hue < BLUE_HUE_MAX) {
                        int timeout = 100;
                        while (intake->getTargetSpeed() >= 0 && timeout > 0) {
                            timeout--;
                            if (distanceSensor->get_distance() < 20) {
                                master.rumble(".");
                                // pros::delay(delayTime);
                                intake->setOverwriteSpeed(-570, reverseCountdown);
                                pros::delay(100);
                                break;
                            }
                            pros::delay(10); // Add a delay to prevent the loop from running too fast
                        }
                        
                    } else if (!team && (hue > RED_HUE_MIN || hue < RED_HUE_MAX)) {
                        int timeout = 100;
                        while (intake->getTargetSpeed() >= 0 && timeout > 0) {
                            timeout--;
                            if (distanceSensor->get_distance() < 20) {
                                master.rumble(".");
                                // pros::delay(delayTime);
                                intake->setOverwriteSpeed(-570, reverseCountdown);
                                pros::delay(100);
                                break;
                            }
                            pros::delay(10); // Add a delay to prevent the loop from running too fast
                        }
                    }
                }
                if (!hookAtFullSpeed && intake->atTargetSpeed()) {
                    hookAtFullSpeed = true;
                }
                if ((intake->getTargetSpeed() > 50 && intake->getSpeed() < 10 && hookAtFullSpeed && shouldUnjam)) {
                    intake->setOverwriteSpeed(-590, 200);
                }
            
                pros::delay(10); // Add a delay to prevent the loop from running too fast
            }
        }

    public:
        HookTasks(Intake *intake, pros::Optical *colourSensor, pros::Distance *distanceSensor, int delay)
            : intake(intake), colourSensor(colourSensor), distanceSensor(distanceSensor), sorterTask([&](){}), shouldSort(false), shouldUnjam(true), delayTime(delay), reverseCountdown(100) {}

        void setDelay(int delay) {
            this->delayTime = delay;
        }

        void init() {
            colourSensor->set_led_pwm(100);
            sorterTask = pros::Task([&] { multiThread();}, 5, 8192, "colour");
        }

        void setSorting(bool state) {
            shouldSort = state;
        }

        void setUnjam(bool state) {
            shouldUnjam = state;
        }



        bool isRunning() {
            return sorterTask.get_state() == pros::E_TASK_STATE_RUNNING;
        }
        bool isSorting() {
            return shouldSort;
        }
};

#endif