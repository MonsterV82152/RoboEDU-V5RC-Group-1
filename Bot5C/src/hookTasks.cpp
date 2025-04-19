#ifndef COLOURSORTER_CPP
#define COLOURSORTER_CPP

#include "globals.hpp"
#include "intake.cpp"

class HookTasks {
    private:
        Intake *intake;
        pros::Optical *colourSensor;
        pros::Distance *dist;
        pros::Task task;
        bool shouldSort;
        int delayTime;
        int reverseCountdown;


        static constexpr int BLUE_HUE_MIN = 180;
        static constexpr int BLUE_HUE_MAX = 230;
        static constexpr int RED_HUE_MIN = 350;
        static constexpr int RED_HUE_MAX = 20;

        void multiThread() {
            bool atTop = false;
            bool reject = false;
            bool newRej = true;
            while (true) {
                int hue = colourSensor->get_hue();
                if (shouldSort) {
                    if (dist->get_distance() < 30) {
                        atTop = true;
                    } else {
                        atTop = false;
                    }
                    
                    if (team && BLUE_HUE_MIN < hue && hue < BLUE_HUE_MAX && newRej) {
                        reject = true;
                        newRej = false;
                    }
            
                    if (reject && atTop) {
                        reject = false;
                        // pros::delay(50);
                        intake->setOverwriteSpeed(-550, 200);
                        pros::delay(300);
                        newRej = true;
                    }
            
                    // master.print(1, 0, atTop ? "at top" : "no top");
                    pros::delay(20);
                }
                if (!hookAtFullSpeed && intake->atTargetSpeed()) {
                    hookAtFullSpeed = true;
                }
                if ((intake->getTargetSpeed() > 50 && intake->getSpeed() < 20 && hookAtFullSpeed)) {
                    intake->setOverwriteSpeed(-127, 200);
                }
            
                pros::delay(10); // Add a delay to prevent the loop from running too fast
            }
        }

    public:
        HookTasks(Intake *intake, pros::Optical *colourSensor, pros::Distance *dist, int delay)
            : intake(intake), colourSensor(colourSensor), dist(dist), task([&](){}), shouldSort(false), delayTime(delay), reverseCountdown(300) {}

        void setDelay(int delay) {
            this->delayTime = delay;
        }

        void init() {
            colourSensor->set_led_pwm(100);
            task.create([&](){multiThread();}, 4, 8192, "colour");
            task.suspend();
        }

        void start() {
            task.create([&](){multiThread();}, 4, 8192, "colour");
        }


        void stop() {
            task.suspend();
        }

        void setSorting(bool state) {
            shouldSort = state;
        }



        bool isRunning() {
            return task.get_state() == pros::E_TASK_STATE_RUNNING;
        }
        bool isSorting() {
            return shouldSort;
        }
};

#endif