/* **************************************************** */
/*                                                      */
/*                                                      */
/*    array.h                                           */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/24 17:01:26 by Exyos             */
/*    Updated: 2019/05/24 17:01:26 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef ARRAY_H
#define ARRAY_H 

#include <stdlib.h>
#include <stdio.h>

#include "shape.h"

/**
 *  tempory function
**/
void display_array(int* t);


/**
 * @brief make a copy of an array of integer
 * @param the array to copy and it size
 * @return the copied array
**/
int* copy_array(int* src, int size);

#endif