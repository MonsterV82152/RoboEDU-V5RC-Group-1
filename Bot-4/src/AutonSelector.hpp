#include "globals.hpp"


#ifndef AUTONSELECTOR_HPP
#define AUTONSELECTOR_HPP

/*
Autonomous Selector - We display an image of the field onto the brain through lines, rectagles
and circles. Then, it will detect touches on the brain and changes the selected autonomous accordingly. 
There is also a driver selector that will change the control scheme.
*/

void DisplayUser() {
    if (user == 0) {
        pros::screen::set_pen(pros::Color::red);
        pros::screen::fill_rect(248,14,357,60);
        pros::screen::erase_rect(258,24,347,50);
        pros::screen::print(TEXT_MEDIUM_CENTER,480-201, 29, "Kiera");
        pros::screen::set_pen(RGB2COLOR(0,0,100));
        pros::screen::fill_rect(357,14,466,60);
        pros::screen::erase_rect(367,24,456,50);
        pros::screen::print(TEXT_MEDIUM_CENTER,480-97, 29, "Nathan");
    } else if (user == 1) {
        pros::screen::set_pen(pros::Color::blue);
        pros::screen::fill_rect(357,14,466,60);
        pros::screen::erase_rect(367,24,456,50);
        pros::screen::print(TEXT_MEDIUM_CENTER,480-97, 29, "Nathan");
        pros::screen::set_pen(RGB2COLOR(100,0,0));
        pros::screen::fill_rect(248,14,357,60);
        pros::screen::erase_rect(258,24,347,50);
        pros::screen::print(TEXT_MEDIUM_CENTER,480-201, 29, "Kiera");
    }
}

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
                SelectedTeam = true;
                SelectedAuton = 1;
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
                DisplayUser();
                touched = 0;
            }
        } else if (status.x < 14+(72*1.5) && status.y > 14+(72*1.5) && status.y < 14+(144*1.5)) {
            if (touched != 1) {
                SelectedTeam = true;
                SelectedAuton = 2;
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
                DisplayUser();
                touched = 1;
            }
        } else if (status.x < 14+(144*1.5) && status.y < 14+(72*1.5) && status.x > 14+(72*1.5)) {
            if (touched != 2) {
                SelectedTeam = false;
                SelectedAuton = 1;
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
                DisplayUser();
                touched = 2;
            }
        } else if (status.x < 14+(144*1.5) && status.x > 14+(72*1.5) && status.y < 14+(144*1.5) && status.y > 14+(72*1.5)) {
            if (touched != 3) {
                SelectedTeam = false;
                SelectedAuton = 2;
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
                DisplayUser();
                touched = 3;
            }
        } else if (status.x > 480-230 && status.x < 480-115 && status.y < 60) {
            if (user == 1) {
                pros::screen::erase_rect(240,0,480,60);
                user = 0;
                DisplayUser();
            }
            
        } else if (status.x > 480-115 && status.y < 60) {
            if (user == 0) {
                pros::screen::erase_rect(240,0,480,60);
                user = 1;
                DisplayUser();
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
            DisplayUser();
            break;

        }
        pros::delay(20);

    }
    AutonSelected = true;

}

#endif