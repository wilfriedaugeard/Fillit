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

bool is_l_right(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    if(nb_label_w < nb_label_h){
        return ((grid->label_width[0] == 3 &&
                grid->label_width[1] == 1 &&
                grid->label_height[0] == 2 &&
                grid->label_height[1] == 1 &&
                grid->label_height[2] == 1) ||

                (grid->label_width[0] == 1 &&
                grid->label_width[1] == 3 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 1 &&
                grid->label_height[2] == 2)
        );
    }else{
        return ((grid->label_width[0] == 2 &&
                grid->label_width[1] == 1 &&
                grid->label_width[2] == 1 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 3) ||

                (grid->label_width[0] == 1 &&
                grid->label_width[1] == 1 &&
                grid->label_width[2] == 2 &&
                grid->label_height[0] == 3 &&
                grid->label_height[1] == 1)
        );
    }
    return false;
}

bool is_bottom(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    if(nb_label_w < nb_label_h){
        return ((grid->label_width[0] == 3 &&
                grid->label_width[1] == 1 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 2 &&
                grid->label_height[2] == 1) ||

                (grid->label_width[0] == 1 &&
                grid->label_width[1] == 3 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 2 &&
                grid->label_height[2] == 1)
        );
    }else{
        return ((grid->label_width[0] == 1 &&
                grid->label_width[1] == 2 &&
                grid->label_width[2] == 1 &&
                grid->label_height[0] == 1 &&
                grid->label_height[1] == 3) ||

                (grid->label_width[0] == 1 &&
                grid->label_width[1] == 2 &&
                grid->label_width[2] == 1 &&
                grid->label_height[0] == 3 &&
                grid->label_height[1] == 1)
        );
    }
    return false;
}

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
            if(is_four(grid)) return FOUR;
            return FOUR_REV;
        }else{
            return UNDIFINED;
        }
    }else{
        if(grid->label_width[0] == 1 &&
            grid->label_width[1] == 2 &&
            grid->label_width[2] == 1 &&
            grid->label_height[0] == 2 &&
            grid->label_height[1] == 2){
            if(is_four(grid)) return FOUR;
            return FOUR_REV;
        }else{
            return UNDIFINED;
        }
    }
    return UNDIFINED;
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
                if(is_l_right(grid)) return L_RIGHT;
                if(is_bottom(grid)) return BOTTOM;
                return four_or_four_rev(grid);
            }
    }
    return UNDIFINED;
}

void display_name(s_game* game){
    int i = 0;
    while(i < game->size){
        switch(game->shapes[i]){
            case L_LEFT:
                printf("L_LEFT\n");
                break;
            case L_RIGHT:
                printf("L_RIGHT\n");
                break;
            case SQUARE:
                printf("SQUARE\n");
                break;
            case STICK:
                printf("STICK\n");
                break;
            case BOTTOM:
                printf("BOTTOM\n");
                break;
            case FOUR:
                printf("FOUR\n");
                break;
            case FOUR_REV:
                printf("FOUR_REV\n");
                break;
            default:
                printf("UNDIFINED\n");
        }
        i++;
    }
}
