#include "fillit.h"


int main(int argc, char *argv[]){

    if(argc < 2){
        EXIT_FAILURE;
    }
    load_file(argv[1]);
    
    return EXIT_SUCCESS;
}