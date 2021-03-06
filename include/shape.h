/* **************************************************** */
/*                                                      */
/*                                                      */
/*    shap.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/16 17:12:55 by Exyos             */
/*    Updated: 2019/06/01 12:30:31 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef SHAPE_H
#define SHAPE_H 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "shapes/l_left.h"
#include "shapes/l_right.h"
#include "shapes/sticky.h"
#include "shapes/bottom.h"
#include "shapes/square.h"
#include "shapes/four.h"
#include "env.h"


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