/* **************************************************** */
/*                                                      */
/*                                                      */
/*    l_right.h                                         */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 11:57:39 by Exyos             */
/*    Updated: 2019/06/01 12:30:31 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef L_RIGHT_H
#define L_RIGHT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "env.h"

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


#endif
