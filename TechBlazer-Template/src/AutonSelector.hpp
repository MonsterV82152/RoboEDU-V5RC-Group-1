#include "globals.hpp"


#ifndef AUTONSELECTOR_HPP
#define AUTONSELECTOR_HPP

class button {
    public:
    double x;
    double y;
    double x2;
    double y2;
    std::string name;
    button(double x, double y, double x2, double y2, std::string name) : x(x), y(y), x2(x2), y2(y2), name(name) {}
    bool isPressed(pros::screen_touch_status_s_t touch) {
        if (touch.x >= x && touch.x <= x2 && touch.y >= y && touch.y <= y2) {
            return true;
        }
        return false;
    }
};

class AutonSelector {
    public:
    AutonSelector() {

    }

    private:
    void drawButtons(std::vector<button> buttons) {
        for (const auto& b : buttons) {
            pros::screen::draw_rect(b.x, b.y, b.x2, b.y2);
            pros::screen::print(pros::text_format_e_t::E_TEXT_LARGE_CENTER,(b.x2+b.x)/2,(b.y2+b.y)/2, b.name.c_str());
        }
    }
    
    std::string currentPage = "home";
    std::

};

#endif