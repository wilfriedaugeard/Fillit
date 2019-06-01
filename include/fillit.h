/* **************************************************** */
/*                                                      */
/*                                                      */
/*    fillit.h                                          */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/15 18:46:44 by Exyos             */
/*    Updated: 2019/05/27 00:48:33 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef FILLIT_H
#define FILLIT_H 

#include "shape.h"
#include "read.h"
#include "array.h"
#include "label.h"
#include "env.h"



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
int load_file(char *filename,s_game* game);

/**
 * @brief create a game structure  
 * @param void
 * @return the game created
**/
s_game* create_game(void);

/**
 * @brief free memory of a grid  
 * @param a grid
 * @return void
**/
void free_grid(s_shape_grid* grid);

/**
 * @brief free memory of a game  
 * @param a game
 * @return void
**/
void free_game(s_game* game);

#endif