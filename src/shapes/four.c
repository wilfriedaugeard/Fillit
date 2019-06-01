#include "shapes/four.h"

bool is_four(s_shape_grid* grid){
    int i = 0;
    int j = 0;
    int pos = 0;
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    bool seen = false;
    while(j < SHAPE_SIZE){
        while(i < SHAPE_SIZE){
            if(grid->value[i+j*SHAPE_SIZE] == 1){
                if(seen){
                    if(nb_label_w < nb_label_h)
                        return (pos > i);
                    return (pos == i);
                }
                pos = i;
                seen = true;
                break;
            }
            i++;
        }
        i = 0;
        j++;
    }
    return false;
}

e_shape four_or_four_rev(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    if(nb_label_w < nb_label_h){
        if(grid->label_width[0] == 2 &&
            grid->label_width[1] == 2 &&
            grid->label_height[0] == 1 &&
            grid->label_height[1] == 2 &&
            grid->label_height[2] == 1){
            if(is_four(grid)) return FOUR_H;
            return FOUR_REV_H;
        }else{
            return UNDIFINED;
        }
    }else{
        if(grid->label_width[0] == 1 &&
            grid->label_width[1] == 2 &&
            grid->label_width[2] == 1 &&
            grid->label_height[0] == 2 &&
            grid->label_height[1] == 2){
            if(is_four(grid)) return FOUR_V;
            return FOUR_REV_V;
        }else{
            return UNDIFINED;
        }
    }
    return UNDIFINED;
}