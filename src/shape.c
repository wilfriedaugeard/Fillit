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


bool is_square(s_shape_grid* grid){
    return grid->label_width[0] == 2 &&
            grid->label_width[1] == 2 &&
            grid->label_height[0] == 2 &&
            grid->label_height[1] == 2;
}

bool is_l_left(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    if(nb_label_w < nb_label_h){
        return ((grid->label_width[0] == 3 &&
                grid->label_width[1] == 1 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 1 &&
                grid->label_height[2] == 2) ||

                (grid->label_width[0] == 1 &&
                grid->label_width[1] == 3 &&
                grid->label_height[0] == 2 &&
                grid->label_height[1] == 1 &&
                grid->label_height[2] == 1)
        );
    }else{
        return ((grid->label_width[0] == 1 &&
                grid->label_width[1] == 1 &&
                grid->label_width[2] == 2 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 3) ||

                (grid->label_width[0] == 2 &&
                grid->label_width[1] == 1 &&
                grid->label_width[2] == 1 &&
                grid->label_height[0] == 3 &&
                grid->label_height[1] == 1)
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
    if(nb_label_w == 2 || nb_label_h == 2){
            if(nb_label_h == nb_label_w){
                if(is_square(grid)) return SQUARE;
            }
            if(nb_label_w == 3 || nb_label_h == 3){
                if(is_l_left(grid)) return L_LEFT;
            }
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
