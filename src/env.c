#include "env.h"


void compute_size_max(s_env* env){
    int x = 0;
    int y = 0;
    int i = 0;
    while(i < env->game->size){
        switch(env->game->shapes[i]){
            case L_LEFT_1:
                x += 2;
                y += 3;
                break;
            case L_LEFT_2:
                x += 2;
                y += 3;
                break;
            case L_LEFT_3:
                x += 3;
                y += 2;
                break;
            case L_LEFT_4:
                x += 3;
                y += 2;
                break;
            case L_RIGHT_1:
                x += 2;
                y += 3;
                break;
            case L_RIGHT_2:
                x += 2;
                y += 3;
                break;
            case L_RIGHT_3:
                x += 3;
                y += 2;
                break;
            case L_RIGHT_4:
                x += 3;
                y += 2;
                break;
            case SQUARE:
                x += 2;
                y += 2;
                break;
            case STICK_H:
                x += 4;
                y ++;
                break;
            case STICK_V:
                x ++;
                y += 4;
                break;
            case BOTTOM_1:
                x += 2;
                y += 3;
                break;
            case BOTTOM_2:
                x += 2;
                y += 3;
                break;
            case BOTTOM_3:
                x += 3;
                y += 2;
                break;
            case BOTTOM_4:
                x += 3;
                y += 2;
                break;
            case FOUR_H:
                x += 3;
                y += 2;
                break;
            case FOUR_V:
                x += 2;
                y += 3;
                break;
            case FOUR_REV_H:
                x += 3;
                y += 2;
                break;
            case FOUR_REV_V:
                x += 2;
                y += 3;
                break;
            default:
                break;
        }
    i++;
    }
    env->width = x;
    env->height = y;
}

void display_env_grid(s_env* env){
    if(!env){
        printf("Empty environment\n");
        return;
    }
    int i = 0;
    int j = 0;
    while(j < env->height){
        while(i < env->width){
            if(env->env_grid[i][j] == 0)
                printf(".");
            else{
                printf("%c",64+env->env_grid[i][j]);
            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

s_env* initialize_env(s_game* game){
    int i = 0;
    int j = 0;
    s_env* env = (s_env*)malloc(sizeof(s_env));
    env->game = game;
    compute_size_max(env);
    env->env_grid = (int**)malloc(env->width*sizeof(int*));
    while(i < env->width){
        env->env_grid[i] = (int*)malloc(env->height*sizeof(int));
        while(j < env->height){
            env->env_grid[i][j] = 0;
            j++;
        }
        i++;
        j = 0;
    }
    return env;
} 