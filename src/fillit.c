#include "fillit.h"


void create_shape_grid(int* array){
    s_shape_grid* grid = (s_shape_grid*)malloc(sizeof(s_shape_grid));
    grid->value = copy_array(array, SHAPE_SIZE*SHAPE_SIZE);
    create_label(grid);
}

int load_file(char *filename){
    if(!filename) 
        return -1;
    
    FILE* fd;
    long size=0;

    fd=fopen(filename,"r");
    char* line =read_next_line(fd,&size);
    int j = 1;
    int i;
    int t[SHAPE_SIZE*SHAPE_SIZE];
    int pos = 0;

	while(line!=NULL){
        if(j%(SHAPE_SIZE+1) != 0){
            i = 0;
            while(i<SHAPE_SIZE){
                switch(line[i*2]){
                    case '.':
                        t[pos] = 0;
                        break;
                    case '#':
                        t[pos] = 1;
                        break;
                    default:
                        t[pos] = -1;
                        break;
                }
                pos++;
                i++;
		    }
        }
        else{
            display_array(t);
            create_shape_grid(t);
            j = 0;
            pos = 0;
        }
        j++;
		free(line);
		line=read_next_line(fd,&size);
	}
    display_array(t);
    create_shape_grid(t);
    free(line);
    pclose(fd);
    return 0;
}