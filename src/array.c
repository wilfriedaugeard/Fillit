#include "array.h"



void display_array(int* array){
    int i = 0;
    int j = 0;
    printf("ARRAY :\n\n");
    while (j < SHAPE_SIZE){
        i = 0;
        while(i < SHAPE_SIZE){
            printf("%d ",array[i+j*SHAPE_SIZE]);
            i++;
        }
        printf("\n");
        j++;
    } 
    printf("\n");
}

int* copy_array(int* src, int size){
    int i = 0;
    int* t = (int*) malloc(size*sizeof(int));
    while(i < size){
        t[i] = src[i];
        i++;
    }
    return t;
}