/* **************************************************** */
/*                                                      */
/*                                                      */
/*    label.h                                           */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/24 17:08:03 by Exyos             */
/*    Updated: 2019/05/24 17:08:03 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef LABEL_H
#define LABEL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "shape.h"

/**
 * @brief count on the width how many times there is a shape in the grid
 * @param a grid that contains a shape 
 * @return void
**/
void create_label_width(s_shape_grid* grid);


/**
 * @brief count on the height how many times there is a shape in the grid
 * @param a grid that contains a shape 
 * @return void
**/
void create_label_height(s_shape_grid* grid);


/**
 * @brief compute the size of an array
 * @param an array 
 * @return the size of the array
**/
int nb_label(int* label_array);


/**
 * @brief reduice the label array (remove 0)
 * @param a label array and it size
 * @return the reduiced array
**/
int* reduice_label(int* label_array,int* label_size);


/**
 * @brief update the label arrays (without 0) 
 * @param a grid that contains a shape 
 * @return void
**/
void scan_label(s_shape_grid* grid);


/**
 * @brief count how many times there is a shape in the grid (width and height)
 * @param a grid that contains a shape 
 * @return void
**/
void create_label(s_shape_grid* grid);

#endif 