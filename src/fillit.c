#include "fillit.h"



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
    while (j < SHAPE_SIZE){
        i = 0;
        while(i < SHAPE_SIZE){
            printf("%d ",array[i+j*SHAPE_SIZE]);
            i++;
        }
        printf("\n");
        j++;
    } 
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
                        printf(". ");
                        t[pos] = 0;
                        break;
                    case '#':
                        printf("# ");
                        t[pos] = 1;
                        break;
                    default:
                        printf("DEFAULT\n");
                        t[pos] = -1;
                        break;
                }
                pos++;
                i++;
		    }
        }
        else{
            display_array(t);
            j = 0;
            pos = 0;
        }
        j++;
        printf("\n");
		free(line);
		line=read_next_line(fd,&size);
	}
    display_array(t);
    free(line);
    pclose(fd);
    return 0;
}