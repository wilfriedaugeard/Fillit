/* **************************************************** */
/*                                                      */
/*                                                      */
/*    shap.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/16 17:12:55 by Exyos             */
/*    Updated: 2019/05/26 23:28:21 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef SHAPE_H
#define SHAPE_H 

#define SHAPE_SIZE 4

#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>


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
 * @brief verify if the shape is a STICK_H shape
 * @param a grid
 * @return true if it's a STICK_H shape else false
**/
bool is_stick_h(s_shape_grid* grid);

/**
 * @brief verify if the shape is a STICK_V shape
 * @param a grid
 * @return true if it's a STICK_V shape else false
**/
bool is_stick_v(s_shape_grid* grid);

/**
 * @brief verify if the shape is a SQUARE shape
 * @param a grid
 * @return true if it's a SQUARE shape else false
**/
bool is_square(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_LEFT_1 shape
 * @param a grid
 * @return true if it's a L_LEFT_1 shape else false
**/
bool is_l_left_1(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_LEFT_2 shape
 * @param a grid
 * @return true if it's a L_LEFT_2 shape else false
**/
bool is_l_left_2(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_LEFT_3 shape
 * @param a grid
 * @return true if it's a L_LEFT_3 shape else false
**/
bool is_l_left_3(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_LEFT_4 shape
 * @param a grid
 * @return true if it's a L_LEFT_4 shape else false
**/
bool is_l_left_4(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_RIGHT_1 shape
 * @param a grid
 * @return true if it's a L_RIGHT_1 shape else false
**/
bool is_l_right_1(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_RIGHT_2 shape
 * @param a grid
 * @return true if it's a L_RIGHT_2 shape else false
**/
bool is_l_right_2(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_RIGHT_3 shape
 * @param a grid
 * @return true if it's a L_RIGHT_3 shape else false
**/
bool is_l_right_3(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_RIGHT_4 shape
 * @param a grid
 * @return true if it's a L_RIGHT_4 shape else false
**/
bool is_l_right_4(s_shape_grid* grid);

/**
 * @brief verify if the shape is a BOTTOM_1 shape
 * @param a grid
 * @return true if it's a BOTTOM_1 shape else false
**/
bool is_bottom_1(s_shape_grid* grid);

/**
 * @brief verify if the shape is a BOTTOM_2 shape
 * @param a grid
 * @return true if it's a BOTTOM_2 shape else false
**/
bool is_bottom_2(s_shape_grid* grid);

/**
 * @brief verify if the shape is a BOTTOM_3 shape
 * @param a grid
 * @return true if it's a BOTTOM_3 shape else false
**/
bool is_bottom_3(s_shape_grid* grid);

/**
 * @brief verify if the shape is a BOTTOM_4 shape
 * @param a grid
 * @return true if it's a BOTTOM_4 shape else false
**/
bool is_bottom_4(s_shape_grid* grid);

/**
 * @brief verify if the shape is a FOUR shape
 * @param a grid
 * @return true if it's a FOUR shape else false
**/
bool is_four(s_shape_grid* grid);

/**
 * @brief verify if the shape is a FOUR_h shape
 * @param a grid
 * @return true if it's a FOUR_h shape else false
**/
bool is_four_h(s_shape_grid* grid);

/**
 * @brief verify if the shape is a FOUR_V shape
 * @param a grid
 * @return true if it's a FOUR_V shape else false
**/
bool is_four_v(s_shape_grid* grid);

/**
 * @brief verify if the shape is a FOUR_H,FOUR_V or FOUR_REV_H,FOUR_REV_V shape
 * @param a grid
 * @return the type of the shape (FOUR_H,FOUR_V,FOUR_REV_H,FOUR_REV_V or UNDIFINED)
**/
e_shape four_or_four_rev(s_shape_grid* grid);

/**
 * @brief give the name of the Tetriminos shape given
 * @param a shape_grid
 * @return the name of the shape
**/
e_shape shape_name(s_shape_grid* grid);

/**
 * @brief display the name of the shapes
 * @param the game
 * @return void
 **/
void display_name(s_game* game);


#endif