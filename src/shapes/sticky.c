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

bool stick_h_be_placed(s_env* env, int x, int y){
    if(env->env_grid[x][y] != 0) return false;
    if(x+1 >= env->width || env->env_grid[x+1][y] != 0) return false; 
    if(x+2 >= env->width || env->env_grid[x+2][y] != 0) return false; 
    if(x+3 >= env->width || env->env_grid[x+3][y] != 0) return false; 
    return true;
}

bool stick_v_be_placed(s_env* env, int x, int y){
    if(env->env_grid[x][y] != 0) return false;
    if(y+1 >= env->width || env->env_grid[x][y+1] != 0) return false; 
    if(y+2 >= env->width || env->env_grid[x][y+2] != 0) return false; 
    if(y+3 >= env->width || env->env_grid[x][y+3] != 0) return false; 
    return true;
}

void stick_v_placed(s_env* env, int x, int y, int nb){
    env->env_grid[x][y] = nb;
    env->env_grid[x][y+1] = nb; 
    env->env_grid[x][y+2] = nb; 
    env->env_grid[x][y+3] = nb; 
}

void stick_h_placed(s_env* env, int x, int y, int nb){
    env->env_grid[x][y] = nb;
    env->env_grid[x+1][y] = nb; 
    env->env_grid[x+2][y] = nb; 
    env->env_grid[x+3][y] = nb; 
}