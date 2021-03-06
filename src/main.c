#include "fillit.h"
#include "solver.h"

int main(int argc, char *argv[]){

    if(argc < 2){
        EXIT_FAILURE;
    }
    s_game* game = create_game();
    if(load_file(argv[1],game) == -1){
        printf("error\n");
        return EXIT_SUCCESS;
    }
    s_env* env = initialize_env(game);
    stick_v_placed(env, 0, 0, 1);
    stick_h_placed(env, 1, 0, 2);
    printf("\n======================\n\n");
    display_env_grid(env);
    free(game);
    return EXIT_SUCCESS;
}