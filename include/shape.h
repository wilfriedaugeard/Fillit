/* **************************************************** */
/*                                                      */
/*                                                      */
/*    shap.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/16 17:12:55 by Exyos             */
/*    Updated: 2019/05/25 13:52:47 by Exyos             */
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
    L_LEFT, 
    L_RIGHT, 
    SQUARE, 
    STICK, 
    BOTTOM, 
    FOUR,
    FOUR_REV,
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
 * @brief verify if the shape is a STICK shape
 * @param a grid
 * @return true if it's a STICK shape else false
**/
bool is_stick(s_shape_grid* grid);

/**
 * @brief verify if the shape is a SQUARE shape
 * @param a grid
 * @return true if it's a SQUARE shape else false
**/
bool is_square(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_LEFT shape
 * @param a grid
 * @return true if it's a L_LEFT shape else false
**/
bool is_l_left(s_shape_grid* grid);

/**
 * @brief verify if the shape is a L_RIGHT shape
 * @param a grid
 * @return true if it's a L_RIGHT shape else false
**/
bool is_l_right(s_shape_grid* grid);

/**
 * @brief verify if the shape is a BOTTOM shape
 * @param a grid
 * @return true if it's a BOTTOM shape else false
**/
bool is_bottom(s_shape_grid* grid);


/**
 * @brief verify if the shape is a FOUR shape
 * @param a grid
 * @return true if it's a FOUR shape else false
**/
bool is_four(s_shape_grid* grid);

/**
 * @brief verify if the shape is a FOUR or FOUR_REV shape
 * @param a grid
 * @return the type of the shape (FOUR,FOUR_REV or UNDIFINED)
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