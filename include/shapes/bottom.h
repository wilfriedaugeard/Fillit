/* **************************************************** */
/*                                                      */
/*                                                      */
/*    bottom.h                                          */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 11:57:39 by Exyos             */
/*    Updated: 2019/06/01 12:30:31 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef BOTTOM_H
#define BOTTOM_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "env.h"

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


#endif