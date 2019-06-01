/* **************************************************** */
/*                                                      */
/*                                                      */
/*    env.h                                             */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 12:38:27 by Exyos             */
/*    Updated: 2019/06/01 17:36:14 by Exyos             */
/*                                                      */
/* **************************************************** */

#ifndef ENV_H
#define ENV_H 

#define SHAPE_SIZE 4

#include <stdio.h>
#include <stdlib.h>

/**
 * @enum e_shape
 * @brief enumeration of different type of tetriminos shape 
**/
typedef enum 
{
    L_LEFT_1, 
    L_LEFT_2,
    L_LEFT_3,
    L_LEFT_4,
    L_RIGHT_1, 
    L_RIGHT_2,
    L_RIGHT_3,
    L_RIGHT_4,
    SQUARE, 
    STICK_H,
    STICK_V, 
    BOTTOM_1,
    BOTTOM_2,
    BOTTOM_3,
    BOTTOM_4,
    FOUR_H,
    FOUR_V,
    FOUR_REV_H,
    FOUR_REV_V,
    UNDIFINED
} e_shape;


/**
 * @struct s_shape_grid
 * @brief structure of a shape grid with labels
**/
typedef struct
{
    int* value;
    int label_w_size;
    int label_h_size;
    int* label_width;
    int* label_height;
} s_shape_grid;


/**
 * @struct s_game
 * @brief structure of the game
**/
typedef struct 
{
    int size;
    e_shape* shapes;
} s_game;


/**
 * @struct s_env
 * @brief structure of the environment
**/
typedef struct 
{
    s_game* game;
    int width;
    int height;
    int* env;
} s_env;

/**
 * @brief compute the max width and height
 * @param a game
 * @return void
**/
void compute_size_max(s_env* env);

/**
 * @brief initialize the environment
 * @param a game
 * @return the environment initialized
**/
s_env* initialize_env(s_game* game);

#endif