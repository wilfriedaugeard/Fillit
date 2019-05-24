#include "shape.h"


bool is_stick(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    if(nb_label_w < nb_label_h){
        return (grid->label_width[0] == 4 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 1 &&
                grid->label_height[2] == 1 &&
                grid->label_height[3] == 1
        );
    }else{
        return (grid->label_height[0] == 4 &&
                grid->label_width[0] == 1 &&
                grid->label_width[1] == 1 &&
                grid->label_width[2] == 1 &&
                grid->label_width[3] == 1
        );
    }
    return false;
}


e_shape shape_name(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    
    if(nb_label_w == 1 || nb_label_h == 1){
            if(is_stick(grid)) return STICK;
    }
    return UNDIFINED;
}

void display_name(s_game* game){
    int i = 0;
    while(i < game->size){
        printf("%d\n",game->shapes[i]);
        i++;
    }
}
