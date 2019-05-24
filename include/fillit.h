/* **************************************************** */
/*                                                      */
/*                                                      */
/*    fillit.h                                          */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/15 18:46:44 by Exyos             */
/*    Updated: 2019/05/24 19:10:49 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef FILLIT_H
#define FILLIT_H 

#include "shape.h"
#include "read.h"
#include "array.h"
#include "label.h"



/**
 * @brief create the grid that represent the shape and its labels
 * @param the game and a grid that contains a shape 
 * @return void
**/
void create_shape_grid(s_game* game, int* array);

/**
 * @brief load and read the tetriminos description file  
 * @param the file name of tetriminos description
 * @return 0 or -1
**/
int load_file(char *filename);




#endif