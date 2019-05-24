/* **************************************************** */
/*                                                      */
/*                                                      */
/*    read.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/14 16:56:57 by Exyos             */
/*    Updated: 2019/05/24 16:56:57 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef READ_H
#define READ_H 
#define MAXLINELEN 4096

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>


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

#endif