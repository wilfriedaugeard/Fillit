/* **************************************************** */
/*                                                      */
/*                                                      */
/*    env.h                                             */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 12:38:27 by Exyos             */
/*    Updated: 2019/06/01 12:38:27 by Exyos             */
/*                                                      */
/* **************************************************** */

#ifndef ENV_H
#define ENV_H 

#define SHAPE_SIZE 4

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



#endif