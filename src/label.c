#include "label.h"


void create_label_width(s_shape_grid* grid){
    grid->label_w_size = SHAPE_SIZE;
    grid->label_width = (int*) malloc(grid->label_w_size*sizeof(int));
    int i = 0;
    int j = 0;
    int cpt = 0;
    while(j < SHAPE_SIZE){
        while(i < SHAPE_SIZE){
            if(grid->value[i+j*SHAPE_SIZE] == 1){
                cpt++;
            }
            i++;
        }
        grid->label_width[j] = cpt;
        cpt = 0;
        i = 0;
        j++;
    }
}

void create_label_height(s_shape_grid* grid){
    grid->label_h_size = SHAPE_SIZE;
    grid->label_height = (int*) malloc(grid->label_h_size*sizeof(int));
    int i = 0;
    int j = 0;
    int cpt = 0;
    while(i < SHAPE_SIZE){
        while(j < SHAPE_SIZE){
            if(grid->value[i+j*SHAPE_SIZE] == 1){
                cpt++;
            }
            j++;
        }
        grid->label_height[i] = cpt;
        cpt = 0;
        j = 0;
        i++;
    }
}

int nb_label(int* label_array){
    int i = 0;
    int cpt = 0;
    bool label = false;

     while(i < SHAPE_SIZE){
        if( label_array[i] != 0){
            label = true;
            cpt++;
        }
        else{
            if(label) break;
            label = false;
        }
        i++;
    }
    return cpt;
}

int* reduice_label(int* label_array,int* label_size){
    int i = 0;
    int pos = 0;
    *label_size = nb_label(label_array);
    bool label = false;
    int* tmp = (int*)malloc(*label_size*sizeof(int));

     while(i < SHAPE_SIZE){
        if(label_array[i] != 0){
            label = true;
            tmp[pos] = label_array[i];
            pos++;
        }
        else{
            if(label) break;
            label = false;
        }
        i++;
    }
    free(label_array);
    return tmp;
}

void scan_label(s_shape_grid* grid){
    int* array_w = reduice_label(grid->label_width, &grid->label_w_size);
    int* array_h = reduice_label(grid->label_height, &grid->label_h_size);
    grid->label_width = array_w;
    grid->label_height = array_h;
}

void create_label(s_shape_grid* grid){
    create_label_width(grid);
    create_label_height(grid);
    scan_label(grid);
    int i = 0;

    printf("LABEL X: ");
    while (i < grid->label_w_size){
        printf("%d ",grid->label_width[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf("LABEL Y: ");
    while (i < grid->label_h_size){
        printf("%d ",grid->label_height[i]);
        i++;
    }
    printf("\n\n");

} 