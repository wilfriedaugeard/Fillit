#include "shapes/bottom.h"

bool is_bottom_1(s_shape_grid* grid){
    return grid->label_width[0] == 1 &&
            grid->label_width[1] == 2 &&
            grid->label_width[2] == 1 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 3;
}

bool is_bottom_2(s_shape_grid* grid){
    return grid->label_width[0] == 1 &&
            grid->label_width[1] == 2 &&
            grid->label_width[2] == 1 &&
            grid->label_height[0] == 3 &&
            grid->label_height[1] == 1;
}

bool is_bottom_3(s_shape_grid* grid){
    return grid->label_width[0] == 3 &&
            grid->label_width[1] == 1 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 2 &&
            grid->label_height[2] == 1;
}

bool is_bottom_4(s_shape_grid* grid){
    return grid->label_width[0] == 1 &&
            grid->label_width[1] == 3 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 2 &&
            grid->label_height[2] == 1;
}