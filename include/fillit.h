/* **************************************************** */
/*                                                      */
/*                                                      */
/*    fillit.h                                          */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/15 18:46:44 by Exyos             */
/*    Updated: 2019/05/24 14:45:56 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef FILLIT_H
#define FILLIT_H 
#define MAXLINELEN 4096

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include "shape.h"


/**
 * @brief read the next line of a file  
 * @param the file to read and a pointer where we'll given the size of the line readed
 * @return the line readed
**/
char* read_next_line(FILE* p_f, long* p_size);


/**
 * @brief divide the occurrences in an array
 * @param the file to split and size of this line
 * @return the array created
**/
long* convert_line(char* line, long* p_size);


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
 * @brief count how many times there is a shape in the grid (width and height)
 * @param a grid that contains a shape 
 * @return void
**/
void create_label(s_shape_grid* grid);

/**
 * @brief create the grid that represent the shape and its labels
 * @param a grid that contains a shape 
 * @return void
**/
void create_shape_grid(int* array);

/**
 * @brief load and read the tetriminos description file  
 * @param the file name of tetriminos description
 * @return 0 or -1
**/
int load_file(char *filename);

#endif