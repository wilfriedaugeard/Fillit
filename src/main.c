#include "fillit.h"


int main(int argc, char *argv[]){

    if(argc < 2){
        EXIT_FAILURE;
    }
    s_game* game = create_game();
    load_file(argv[1],game);
    initialize_env(game);
    free(game);
    return EXIT_SUCCESS;
}