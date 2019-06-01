#include "shapes/l_left.h"

bool is_l_left_1(s_shape_grid* grid){
    return grid->label_width[0] == 1 &&
            grid->label_width[1] == 1 &&
            grid->label_width[2] == 2 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 3;
}

bool is_l_left_2(s_shape_grid* grid){
    return grid->label_width[0] == 2 &&
            grid->label_width[1] == 1 &&
            grid->label_width[2] == 1 &&
            grid->label_height[0] == 3 &&
            grid->label_height[1] == 1;
    
}

bool is_l_left_3(s_shape_grid* grid){
    return grid->label_width[0] == 3 &&
            grid->label_width[1] == 1 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 1 &&
            grid->label_height[2] == 2;
}

bool is_l_left_4(s_shape_grid* grid){
    return grid->label_width[0] == 1 &&
            grid->label_width[1] == 3 &&
            grid->label_height[0] == 2 &&
            grid->label_height[1] == 1 &&
            grid->label_height[2] == 1;
}