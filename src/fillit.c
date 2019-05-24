#include "fillit.h"
#include "shape.h"



char* read_next_line(FILE* p_f, long* p_size){
    char* s = malloc(MAXLINELEN*sizeof(char));
    if(!s){
        fprintf(stderr,"Not enaugh memory");
        exit(EXIT_FAILURE);
    }
    long old_pos = ftell(p_f);
    long len = 0;
    if(fgets(s,MAXLINELEN,p_f) != NULL){
        len = ftell(p_f)-old_pos;
        if(s[len-1] == '\n'){
            s[len-1]='\0';
            len--;
        }
        else{
            if(!feof(p_f)){
                fprintf(stderr,"Line too long...");
                exit(EXIT_FAILURE);
            }
        }
        (*p_size) = len;
        return s;
    }
    free(s);
    return NULL;
}

long* convert_line(char* line, long* p_size){
    long* arr = malloc((*p_size)*sizeof(long));
    if(!arr){
        fprintf(stderr,"Not enaugh memory");
        exit(EXIT_FAILURE);
    }
    long arr_s = 0;
    char* token = strtok(line," ");
    while(token != NULL){
        char* endval = token;
        long val = strtol(token, &endval, 10);
        if((*endval)=='\0'){
            arr[arr_s]=val;
            arr_s++;
        }else{
            free(arr);
            return NULL;
        }
        token = strtok(NULL," ");
    }
    (*p_size)=arr_s;
    return arr;
}

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
    return tmp;
}

void scan_label(s_shape_grid* grid){
    int* array_w = reduice_label(grid->label_width, &grid->label_w_size);
    int* array_h = reduice_label(grid->label_height, &grid->label_h_size);
    free(grid->label_width);
    free(grid->label_height);
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