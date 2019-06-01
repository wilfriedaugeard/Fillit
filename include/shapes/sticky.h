/* **************************************************** */
/*                                                      */
/*                                                      */
/*    sticky.h                                           */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/06/01 11:57:39 by Exyos             */
/*    Updated: 2019/06/01 12:30:31 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef STICKY_H
#define STICKY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "env.h"

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

bool stick_h_be_placed(s_env* env, int x, int y);
bool stick_v_be_placed(s_env* env, int x, int y);

void stick_v_placed(s_env* env, int x, int y, int nb);
void stick_h_placed(s_env* env, int x, int y, int nb);
#endif