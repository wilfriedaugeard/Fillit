#include "read.h"

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