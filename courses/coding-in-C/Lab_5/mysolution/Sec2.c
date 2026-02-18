#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("At least one argument is expected.\n");
        return 0;
    }

    for(int i = 0; i < argc; i++){
        printf("Argument %d at Adress %p has value '%s' and lenght %ld\n", argc, argv[i], argv[i], strlen(argv[i]));
        printf("Argument %d at Adress %p has value '%s' and lenght %ld\n", argc, *(argv + i), *(argv + i), strlen(argv[i]));
    }
}