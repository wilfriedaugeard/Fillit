/* **************************************************** */
/*                                                      */
/*                                                      */
/*    square.h                                          */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 11:57:39 by Exyos             */
/*    Updated: 2019/06/01 12:30:31 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef SQUARE_H
#define SQUARE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "env.h"

/**
 * @brief verify if the shape is a SQUARE shape
 * @param a grid
 * @return true if it's a SQUARE shape else false
**/
bool is_square(s_shape_grid* grid);

#endif