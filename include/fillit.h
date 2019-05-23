/* **************************************************** */
/*                                                      */
/*                                                      */
/*    fillit.h                                          */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/15 18:46:44 by Exyos             */
/*    Updated: 2019/05/22 14:09:14 by Exyos             */
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

void display_array(int* t);

/**
 * @brief load and read the tetriminos description file  
 * @param the file name of tetriminos description
 * @return 0 or -1
**/
int load_file(char *filename);

#endif