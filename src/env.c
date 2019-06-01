#include "env.h"


int width_size(s_game* game){
    int x = 0;
    int i = 0;
    while(i < game->size){
        switch(game->shapes[i]){
            case L_LEFT_1:
                x += 2;
                break;
            case L_LEFT_2:
                x += 2;
                break;
            case L_LEFT_3:
                x += 3;
                break;
            case L_LEFT_4:
                x += 3;
                break;
            case L_RIGHT_1:
                x += 2;
                break;
            case L_RIGHT_2:
                x += 2;
                break;
            case L_RIGHT_3:
                x += 3;
                break;
            case L_RIGHT_4:
                x += 3;
                break;
            case SQUARE:
                x += 2;
                break;
            case STICK_H:
                x += 4;
                break;
            case STICK_V:
                x ++;
                break;
            case BOTTOM_1:
                x += 2;
                break;
            case BOTTOM_2:
                x += 2;
                break;
            case BOTTOM_3:
                x += 3;
                break;
            case BOTTOM_4:
                x += 3;
                break;
            case FOUR_H:
                x += 3;
                break;
            case FOUR_V:
                x += 2;
                break;
            case FOUR_REV_H:
                x += 3;
                break;
            case FOUR_REV_V:
                x += 2;
                break;
            default:
                break;
        }
    i++;
    }
    return x;
}


s_env* initialize_env(s_game* game){
    s_env* env = (s_env*)malloc(sizeof(s_env));
    int x = 0;
    int y = 0;
    int i = 0;

    x = width_size(game);
    printf("size: %d\n",x);
    y++;
    i++;
    return env;
} 