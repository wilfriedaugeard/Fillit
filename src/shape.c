#include "shape.h"



e_shape shape_name(s_shape_grid* grid){
    int nb_label_w = grid->label_w_size;
    int nb_label_h = grid->label_h_size;
    
    if(nb_label_w == 1 || nb_label_h == 1){
        if(nb_label_w < nb_label_h){
            if(is_stick_h(grid)) return STICK_H;
        }
        if(is_stick_v(grid)) return STICK_V;
    }
    if(nb_label_w == 2 || nb_label_h == 2){
            if(nb_label_h == nb_label_w){
                if(is_square(grid)) return SQUARE;
            }
            if(nb_label_w == 3 || nb_label_h == 3){
                if(nb_label_w < nb_label_h){
                    if(is_l_left_3(grid)) return L_LEFT_3;
                    if(is_l_left_4(grid)) return L_LEFT_4;
                    if(is_l_right_3(grid)) return L_RIGHT_3;
                    if(is_l_right_4(grid)) return L_RIGHT_4;
                    if(is_bottom_3(grid)) return BOTTOM_3;
                    if(is_bottom_4(grid)) return BOTTOM_4;
                }else{
                    if(is_l_left_1(grid)) return L_LEFT_1;
                    if(is_l_left_2(grid)) return L_LEFT_2;
                    if(is_l_right_1(grid)) return L_RIGHT_1;
                    if(is_l_right_2(grid)) return L_RIGHT_2;
                    if(is_bottom_1(grid)) return BOTTOM_1;
                    if(is_bottom_2(grid)) return BOTTOM_2;
                }
                return four_or_four_rev(grid);
            }
    }
    return UNDEFINED;
}

void display_name(s_game* game){
    int i = 0;
    while(i < game->size){
        switch(game->shapes[i]){
            case L_LEFT_1:
                printf("L_LEFT_1\n");
                break;
            case L_LEFT_2:
                printf("L_LEFT_2\n");
                break;
            case L_LEFT_3:
                printf("L_LEFT_3\n");
                break;
            case L_LEFT_4:
                printf("L_LEFT_4\n");
                break;
            case L_RIGHT_1:
                printf("L_RIGHT_1\n");
                break;
            case L_RIGHT_2:
                printf("L_RIGHT_2\n");
                break;
            case L_RIGHT_3:
                printf("L_RIGHT_3\n");
                break;
            case L_RIGHT_4:
                printf("L_RIGHT_4\n");
                break;
            case SQUARE:
                printf("SQUARE\n");
                break;
            case STICK_H:
                printf("STICK_H\n");
                break;
            case STICK_V:
                printf("STICK_V\n");
                break;
            case BOTTOM_1:
                printf("BOTTOM_1\n");
                break;
            case BOTTOM_2:
                printf("BOTTOM_2\n");
                break;
            case BOTTOM_3:
                printf("BOTTOM_3\n");
                break;
            case BOTTOM_4:
                printf("BOTTOM_4\n");
                break;
            case FOUR_H:
                printf("FOUR_H\n");
                break;
            case FOUR_V:
                printf("FOUR_V\n");
                break;
            case FOUR_REV_H:
                printf("FOUR_REV_H\n");
                break;
            case FOUR_REV_V:
                printf("FOUR_REV_V\n");
                break;
            default:
                printf("UNDEFINED\n");
        }
        i++;
    }
}
