#include "TBGlobals.hpp"
#include <vector>

class TBToggle {
    private:
    static std::vector<TBToggle*> toggleList;
    int cpin = 0;
    int bpin = 0;
    bool state = false;
    public:
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    
    static void toggle(int cpin,int bpin) {
        for (TBToggle *toggle : toggleList) {
            if (toggle->cpin == cpin && toggle->bpin == bpin) {
                toggle->toggle();
                return;
            }
        }
    }
    TBToggle(int cpin,int bpin) {
        this->cpin = cpin;
        this->bpin = bpin;
        toggleList.push_back(this);
    }
    void toggle() {
        if (state) {
            stop();
        } else {
            start();
        }
        state = !state;
    }
    bool getState() {
        return state;
    }
    static void startAll(Controller ctrl[]) {
        while(true) {

            for(Controller c : ctrl) {
                auto btns = c.getButtons();
                for(auto btn : btns) {
                    if (btn.isPressed()) {
                        TBToggle::toggle(2,btn.getPin());
                    }
                }
            }
            auto btns = ctrl->getButtons();
            for(auto btn : btns) {
                if (btn->isPressed()) {
                    TBToggle::toggle(btn->getPin());
                }
            }
        }
    }
};

class ColorSensorToggle : public TBToggle {
    private:
    pros::ADIAnalogIn *sensor;
    public:
    ColorSensorToggle(int pin, pros::ADIAnalogIn *sensor) : TBToggle(pin) {
        this->sensor = sensor;
    }
    void init() {
        sensor->calibrate();
    }
    void start() {
        sensor->set_led(1);
    }
    void stop() {
        sensor->set_led(0);
    }
};

class MotorToggle : public TBToggle {
    private:
    pros::Motor *motor;
    public:
    MotorToggle(int pin, pros::Motor *motor) : TBToggle(pin) {
        this->motor = motor;
    }
    void init() {
        motor->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
    void start() {
        motor->move_velocity(200);
    }
    void stop() {
        motor->move_velocity(0);
    }
};

void main() {
    MotorToggle *m = new MotorToggle(1, new pros::Motor(1));
    ColorSensorToggle *c = new ColorSensorToggle(2, new pros::ADIAnalogIn(2));
    TBToggle::sartAll(controller);
}

void main2() {
    Object test(controller);
    test.append(motor, button);

}