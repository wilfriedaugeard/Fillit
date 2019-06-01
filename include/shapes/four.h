/* **************************************************** */
/*                                                      */
/*                                                      */
/*    four.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 11:57:39 by Exyos             */
/*    Updated: 2019/06/01 12:30:31 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef _FOUR_H
#define _FOUR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "env.h"

/**
 * @brief verify if the shape is a FOUR shape
 * @param a grid
 * @return true if it's a FOUR shape else false
**/
bool is_four(s_shape_grid* grid);

/**
 * @brief verify if the shape is a FOUR_H,FOUR_V or FOUR_REV_H,FOUR_REV_V shape
 * @param a grid
 * @return the type of the shape (FOUR_H,FOUR_V,FOUR_REV_H,FOUR_REV_V or UNDIFINED)
**/
e_shape four_or_four_rev(s_shape_grid* grid);

#endif