/* **************************************************** */
/*                                                      */
/*                                                      */
/*    shap.h                                            */
/*                                                      */
/*    By: Exyos <augeardw@gmail.com>                    */
/*                                                      */
/*    Created: 2019/05/16 17:12:55 by Exyos             */
/*    Updated: 2019/05/16 18:10:28 by Exyos             */
/*                                                      */
/* **************************************************** */


#ifndef SHAPE_H
#define SHAPE_H 

#include <stdlib.h>
#include <stdio.h>

typedef struct s_shape t_shape;
typedef enum {
    L_LEFT, L_RIGHT, SQUARE, STICK, BOTTOM, FOUR
} e_shape;

typedef struct s_shape
{
    e_shape name;
} t_shape;

#endif