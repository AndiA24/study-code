#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int field[10] = {0};
    int temp_field[sizeof(field)/sizeof(field[0])] = {0};
    unsigned short int steps;
    field[2] = 1;
    field[4] = 1;
    field[6] = 1;
    int *ptr_field = field;
    int *ptr_temp_field = temp_field;
    srand(time(NULL));

    steps = 10;

    for(int j = 0; j < (sizeof(field)/sizeof(field[0])); j++){
        printf("%d ", field[j]);
    }
    printf("\n");

    for(int i = 0; i < steps; i++){

        for(int j = 0; j < (sizeof(field)/sizeof(field[0])); j++){ // Clear temp_field[]
            *(ptr_temp_field + j) = 0;
        }

        for(int j = 0; j < (sizeof(field)/sizeof(field[0])); j++){
            int rn;
            char dir;
            char new_index;

            if(*(ptr_field + j) == 1){
                rn =  rand() % 2;
                if(rn == 0){
                    dir = -1;
                }
                else{
                    dir = 1;
                }

                new_index = j + dir;

                switch(new_index){ // Verlassen des Feldes verhindern
                    case -1:
                        new_index = 0;
                        break;

                    case (sizeof(field)/sizeof(field[0])):
                        new_index = (sizeof(field)/sizeof(field[0]) - 1);
                        break;
                }

                *(ptr_temp_field + new_index) = 1;
            }
        }

        for(int j = 0; j < (sizeof(field)/sizeof(field[0])); j++){ // Übertrage temp_field in field
            *(ptr_field + j) = *(ptr_temp_field + j); 
        }

        for(int j = 0; j < (sizeof(field)/sizeof(field[0])); j++){
            printf("%d ", field[j]);
        }
        printf("\n");
    }


}