#include "shapes/square.h"


bool is_square(s_shape_grid* grid){
    return grid->label_width[0] == 2 &&
            grid->label_width[1] == 2 &&
            grid->label_height[0] == 2 &&
            grid->label_height[1] == 2;
}
