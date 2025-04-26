#include "globals.hpp"


#ifndef AUTONSELECTOR_HPP
#define AUTONSELECTOR_HPP

/*
Autonomous Selector - We display an image of the field onto the brain through lines, rectagles
and circles. Then, it will detect touches on the brain and changes the selected autonomous accordingly. 
There is also a driver selector that will change the control scheme.
*/

void DrawMogo(int x, int y, double size) {
    pros::screen::set_pen(pros::Color::lime_green);
    pros::screen::fill_circle(x,y,10);
    pros::screen::set_pen(pros::Color::black);
    pros::screen::fill_circle(x,y,8);
    pros::screen::set_pen(pros::Color::lime_green);
    pros::screen::fill_circle(x,y,2);
}

void DrawRing(auto colour, int x, int y, double size) {
    pros::screen::set_pen(colour);
    pros::screen::fill_circle(x,y,3.5*size);
    pros::screen::set_pen(pros::Color::black);
    pros::screen::fill_circle(x,y,1.5*size);
}

void DrawField(int x, int y, double size) {
    
    pros::screen::set_pen(pros::Color::gray);
    for (int i = 1; i < 6; i++) {
        pros::screen::draw_line(x+(24*i*size),y,x+(24*i*size),y+(144*size));
    }
    for (int i = 1; i < 6; i++) {
        pros::screen::draw_line(x,y+(24*i*size),x+(144*size),y+(24*i*size));
    }

    pros::screen::set_pen(pros::Color::white);
    pros::screen::draw_rect(x-4,y-4,x+(146*size),y+(146*size));
    pros::screen::draw_rect(x-1,y-1,x+(144*size),y+(144*size));
    
    DrawRing(pros::Color::blue,x+(12*size),y+(72*size),size);
    DrawRing(pros::Color::blue,x+(24*size),y+(120*size),size);
    DrawRing(pros::Color::blue,x+(48*size),y+(24*size),size);
    DrawRing(pros::Color::blue,x+(48*size),y+(120*size),size);
    DrawRing(pros::Color::blue,x+((72-3.5)*size),y+((24-3.5)*size),size);
    DrawRing(pros::Color::blue,x+((72-3.5)*size),y+((24+3.5)*size),size);
    DrawRing(pros::Color::blue,x+((72-3.5)*size),y+((72-3.5)*size),size);
    DrawRing(pros::Color::blue,x+((72-3.5)*size),y+((72+3.5)*size),size);
    DrawRing(pros::Color::blue,x+(120*size),y+(72*size),size);
    DrawRing(pros::Color::blue,x+(3.5*size),y+(3.5*size),size);
    DrawRing(pros::Color::blue,x+(3.5*size),y+((144-3.5)*size),size);
    
    DrawRing(pros::Color::red,x+(24*size), y+(72*size), size);
    DrawRing(pros::Color::red,x+((72+3.5)*size),y+((24-3.5)*size), size);
    DrawRing(pros::Color::red,x+((72+3.5)*size),y+((24+3.5)*size), size);
    DrawRing(pros::Color::red,x+((72+3.5)*size),y+((72-3.5)*size), size);
    DrawRing(pros::Color::red,x+((72+3.5)*size),y+((72+3.5)*size), size);
    DrawRing(pros::Color::red,x+(96*size), y+(24*size), size);
    DrawRing(pros::Color::red,x+(96*size), y+(120*size), size);
    DrawRing(pros::Color::red,x+(120*size), y+(120*size), size);
    DrawRing(pros::Color::red,x+(132*size), y+(72*size), size);
    DrawRing(pros::Color::red,x+((144-3.5)*size),y+(3.5*size),size);
    DrawRing(pros::Color::red,x+((144-3.5)*size),y+((144-3.5)*size),size);

    pros::screen::set_pen(pros::Color::grey);
    pros::screen::fill_circle(x+(72*size),y+(48*size),6);
    pros::screen::fill_circle(x+(48*size),y+(72*size),6);
    pros::screen::fill_circle(x+(72*size),y+(96*size),6);
    pros::screen::fill_circle(x+(96*size),y+(72*size),6);

    pros::screen::set_pen(pros::Color::lime_green);
    pros::screen::draw_line(x+(72*size),y+(48*size),x+(96*size),y+(72*size));
    pros::screen::draw_line(x+(72*size),y+(48*size),x+(48*size),y+(72*size));
    pros::screen::draw_line(x+(72*size),y+(96*size),x+(96*size),y+(72*size));
    pros::screen::draw_line(x+(72*size),y+(96*size),x+(48*size),y+(72*size));

    DrawMogo(x+(48*size),y+(48*size),size);
    DrawMogo(x+(96*size),y+(48*size),size);
    DrawMogo(x+(48*size),y+(96*size),size);
    DrawMogo(x+(96*size),y+(96*size),size);
    DrawMogo(x+(72*size),y+(120*size),size);
}

void AutonomousSelector(void* param) {
    bool usernotselected = true;
    pros::delay(200);
    DrawField(14,14,1.5);
    int touched = 5;
    pros::screen_touch_status_s_t status = pros::screen::touch_status();
    while (true) {
        status = pros::screen::touch_status();
        if (status.x < 14+(72*1.5) && status.y < 14+(72*1.5) && status.x != 0) {
            if (touched != 0) {
                team = true;
                auton = 1;
                pros::screen::erase();
                pros::screen::set_pen(RGB2COLOR(70,0,0));
                pros::screen::fill_rect(14,14,14+(72*1.5),14+(144*1.5));
                pros::screen::set_pen(RGB2COLOR(0,0,70));
                pros::screen::fill_rect(14+(72*1.5),14,14+(144*1.5),14+(144*1.5));
                pros::screen::set_pen(pros::Color::dark_red);
                pros::screen::fill_rect(14,14,14+(72*1.5),14+(72*1.5));
                DrawField(14,14,1.5);

                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 100, "Red Ring Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 150, "NA");
                touched = 0;
            }
        } else if (status.x < 14+(72*1.5) && status.y > 14+(72*1.5) && status.y < 14+(144*1.5)) {
            if (touched != 1) {
                team = true;
                auton = 2;
                pros::screen::erase();
                pros::screen::set_pen(RGB2COLOR(70,0,0));
                pros::screen::fill_rect(14,14,14+(72*1.5),14+(144*1.5));
                pros::screen::set_pen(RGB2COLOR(0,0,70));
                pros::screen::fill_rect(14+(72*1.5),14,14+(144*1.5),14+(144*1.5));
                pros::screen::set_pen(pros::Color::dark_red);
                pros::screen::fill_rect(14,14+(72*1.5),14+(72*1.5),14+(144*1.5));
                DrawField(14,14,1.5);

                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 100, "Red Mogo Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 150, "NA");
                touched = 1;
            }
        } else if (status.x < 14+(144*1.5) && status.y < 14+(72*1.5) && status.x > 14+(72*1.5)) {
            if (touched != 2) {
                team = false;
                auton = 1;
                pros::screen::erase();
                pros::screen::set_pen(RGB2COLOR(70,0,0));
                pros::screen::fill_rect(14,14,14+(72*1.5),14+(144*1.5));
                pros::screen::set_pen(RGB2COLOR(0,0,70));
                pros::screen::fill_rect(14+(72*1.5),14,14+(144*1.5),14+(144*1.5));
                pros::screen::set_pen(pros::Color::dark_blue);
                pros::screen::fill_rect(14+(72*1.5),14,14+(144*1.5),14+(72*1.5));
                DrawField(14,14,1.5);

                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 100, "Blue Ring Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 150, "NA");
                touched = 2;
            }
        } else if (status.x < 14+(144*1.5) && status.x > 14+(72*1.5) && status.y < 14+(144*1.5) && status.y > 14+(72*1.5)) {
            if (touched != 3) {
                team = false;
                auton = 2;
                pros::screen::erase();
                pros::screen::set_pen(RGB2COLOR(70,0,0));
                pros::screen::fill_rect(14,14,14+(72*1.5),14+(144*1.5));
                pros::screen::set_pen(RGB2COLOR(0,0,70));
                pros::screen::fill_rect(14+(72*1.5),14,14+(144*1.5),14+(144*1.5));
                pros::screen::set_pen(pros::Color::dark_blue);
                pros::screen::fill_rect(14+(72*1.5),14+(72*1.5),14+(144*1.5),14+(144*1.5));
                DrawField(14,14,1.5);

                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 100, "Blue Mogo Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+20, 150, "NA");
                touched = 3;
            }
        } else if (status.x > 28+(144*1.5)) {
            pros::screen::erase_rect(29+(144*1.5),0,480,240);
            pros::screen::set_pen(pros::Color::green);
            pros::screen::fill_rect(32+(144*1.5),14,466,226);
            pros::screen::erase_rect(46+(144*1.5),28,452,212);
            
            if (touched == 0) {
                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 100, "Red Ring Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 150, "NA");
            } else if (touched == 1) {
                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 100, "Red Mogo Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 150, "NA");
            } else if (touched == 2) {
                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 100, "Blue Ring Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 150, "NA");
            } else if (touched == 3) {
                pros::screen::set_pen(pros::Color::white);
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 80, "Selected Auton:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 100, "Blue Mogo Rush");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 130, "Points:");
                pros::screen::print(TEXT_MEDIUM_CENTER,28+(144*1.5)+30, 150, "NA");
            }  
            break;

        }
        pros::delay(20);

    }

}
double currentx = 0;
double currenty = 0;

// Draw a button with label
void draw_button(int x, int y, int width, int height, const char* label, pros::Color color) {
    pros::screen::set_pen(pros::Color::black);
    pros::screen::draw_rect(x, y, x + width, y + height);
    pros::screen::set_pen(color);
    pros::screen::print(TEXT_MEDIUM_CENTER,x + 5, y + 15, label);
}

bool button_pressed(int x, int y, int width, int height) {
    pros::screen_touch_status_s_t status = pros::screen::touch_status();
    if (status.x != currentx || status.y != currenty) {
        currentx = status.x;
        currenty = status.y;
        if (status.x >= x && status.x <= x + width && status.y >= y && status.y <= y + height) {
            return true;
        }
    }
    return false;
}

void draw_back_button() {
    draw_button(5, 200, 60, 30, "Back", pros::Color::red);
}

bool back_pressed() {
    return button_pressed(5, 200, 60, 30);
}

// Draw first screen
void draw_main_menu() {
    pros::screen::erase();
    draw_button(20, 40, 80, 40, "Red", pros::Color::red);
    draw_button(120, 40, 80, 40, "Blue", pros::Color::blue);
    draw_button(70, 100, 100, 40, "Skills", pros::Color::green);
}

void draw_skills_menu() {
    pros::screen::erase();
    draw_button(30, 50, 160, 40, "Auton Skills", pros::Color::orange);
    draw_button(30, 110, 160, 40, "Driver Skills", pros::Color::yellow);
    draw_back_button();
}

void draw_auton_menu() {
    pros::screen::erase();
    draw_button(10, 30, 140, 40, "Auton 1", pros::Color::white);
    draw_button(170, 30, 140, 40, "Auton 2", pros::Color::white);
    draw_button(10, 100, 140, 40, "Auton 3", pros::Color::white);
    draw_button(170, 100, 140, 40, "Auton 4", pros::Color::white);
    draw_back_button();
}

// GUI state machine
void gui_task(void *param) {
    enum ScreenState { MAIN_MENU, AUTON_MENU, SKILLS_MENU };
    ScreenState current = MAIN_MENU;

    draw_main_menu();

    while (auton == 0) {
        switch (current) {
            case MAIN_MENU:
                if (button_pressed(20, 40, 80, 40)) {
                    team = true;
                    skills = false;
                    current = AUTON_MENU;
                    draw_auton_menu();
                    pros::delay(300);
                } else if (button_pressed(120, 40, 80, 40)) {
                    team = false;
                    skills = false;
                    current = AUTON_MENU;
                    draw_auton_menu();
                    pros::delay(300);
                } else if (button_pressed(70, 100, 100, 40)) {
                    skills = true;
                    team = true;  // default red for skills
                    current = SKILLS_MENU;
                    draw_skills_menu();
                    pros::delay(300);
                }
                break;

            case SKILLS_MENU:
                if (button_pressed(30, 50, 160, 40)) {
                    auton = 6;  // auton skills
                } else if (button_pressed(30, 110, 160, 40)) {
                    auton = 5;  // driver skills
                } else if (back_pressed()) {
                    current = MAIN_MENU;
                    draw_main_menu();
                    pros::delay(300);
                }
                break;

            case AUTON_MENU:
                if (button_pressed(10, 30, 140, 40)) auton = 1;
                else if (button_pressed(170, 30, 140, 40)) auton = 2;
                else if (button_pressed(10, 100, 140, 40)) auton = 3;
                else if (button_pressed(170, 100, 140, 40)) auton = 4;
                else if (back_pressed()) {
                    current = MAIN_MENU;
                    draw_main_menu();
                    pros::delay(300);
                }
                break;
        }
        pros::delay(50);
    }

    // Final selection screen
    pros::screen::erase();
    if (skills) {
        if (auton == 5)
            pros::screen::print(TEXT_MEDIUM_CENTER, 30, 60, "Driver Skills Selected!");
        else
            pros::screen::print(TEXT_MEDIUM_CENTER, 30, 60, "Auton Skills Selected!");
    } else {
        pros::screen::print(TEXT_MEDIUM_CENTER, 30, 60, "%s Auton %d Selected!", team ? "Red" : "Blue", auton);
    }
}

#endif