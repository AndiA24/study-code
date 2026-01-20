#include <stdio.h>

int main(void){
    #define fieldsize 8

    char columns[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    printf("Chess-Field: \n");

    for(int j = fieldsize; j > 0; j--){
        for(int i = 0; i < 8; i++){
            printf("%c%i ", columns[i], j);
        }
        printf("\n");
    }
    return 1;
}