#include "shapes/sticky.h"

bool is_stick_h(s_shape_grid* grid){
    return (grid->label_width[0] == 4 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 1 &&
            grid->label_height[2] == 1 &&
            grid->label_height[3] == 1
    );
}

bool is_stick_v(s_shape_grid* grid){
    return (grid->label_height[0] == 4 &&
            grid->label_width[0] == 1 &&
            grid->label_width[1] == 1 &&
            grid->label_width[2] == 1 &&
            grid->label_width[3] == 1
    );
}