#include "fillit.h"

void free_grid(s_shape_grid* grid){
    if(grid->value)
        free(grid->value);
    if(grid->label_width)
        free(grid->label_width);
    if(grid->label_height)
        free(grid->label_height);
    free(grid);
}


void free_game(s_game* game){
    if(!game)
        free(game->shapes);
    free(game);
}


void create_shape_grid(s_game* game, int* array){
    s_shape_grid* grid = (s_shape_grid*)malloc(sizeof(s_shape_grid));
    grid->value = copy_array(array, SHAPE_SIZE*SHAPE_SIZE);
    create_label(grid);
    game->size++;
    if(game->size==1){
        game->shapes = (e_shape*)malloc(sizeof(e_shape));
    }else{
        game->shapes = realloc(game->shapes,game->size*sizeof(e_shape));
        if(!game->shapes) perror("OOKKK\n");
    }
    if(!game->shapes) printf("LEAK\n");
    game->shapes[game->size-1] = shape_name(grid);
    free_grid(grid);
}

s_game* create_game(void){
    s_game* game = (s_game*)malloc(sizeof(s_game));
    game->size = 0;
    return game;
}

int load_file(char *filename, s_game* game){
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
                switch(line[i]){
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
            create_shape_grid(game,t);
            j = 0;
            pos = 0;
        }
        j++;
		free(line);
		line=read_next_line(fd,&size);
	}
    display_array(t);
    create_shape_grid(game,t);
    display_name(game);
    free(line);
    pclose(fd);
    return 0;
}


