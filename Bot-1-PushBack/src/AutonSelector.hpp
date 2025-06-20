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
    bool isPressed() {
        return true;
    }
};

void autonomousSelector(void *param) {
    
    pros::screen::erase();

}


#endif