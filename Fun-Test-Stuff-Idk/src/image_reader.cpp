#include "globals.hpp"
#include "Images/field.cpp"

inline void Draw_Image_from(const char* selection) {
    int counter = 0;
    if (selection == "field") {
        for (int i = 0; i < field_width; i++) {
            for (int j = 0; j < field_height; j++) {
                pros::screen::set_pen(RGB2COLOR(field_image[counter][0],field_image[counter][1],field_image[counter][2]));
                pros::screen::draw_pixel(i, j);
                counter++;
            }
        }
    }
}