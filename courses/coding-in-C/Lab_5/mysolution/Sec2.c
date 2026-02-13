#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    for(int i = 0; i < argc; i++){
        printf("Argument %d at Adress %p has value '%s' and lenght %ld\n", argc, argv[i], argv[i], strlen(argv[i]));
    }
}