/* **************************************************** */
/*                                                      */
/*                                                      */
/*    shap.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/16 17:12:55 by Exyos             */
/*    Updated: 2019/05/24 16:14:56 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef SHAPE_H
#define SHAPE_H 

#define SHAPE_SIZE 4

#include <stdlib.h>
#include <stdio.h>


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
    FOUR
} e_shape;



/**
 * @struct s_shape
 * @brief structure of a shape
**/
typedef struct 
{
    e_shape name;
} s_shape;


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

#endif