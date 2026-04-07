#include <stdio.h>
#include <stdlib.h>

int main(){
    int inp = 0;
    printf("Please enter an Integer(1-100): ");
    scanf("%d", &inp);
    if(inp < 1 || inp > 100){
        printf("\n Error input invalid.\n");
        return -1;
    }
    int *ptr_inp = malloc(sizeof(int));
    *ptr_inp = inp;

    printf("\n");
    printf("%d\n", inp);
    printf("%d\n", *ptr_inp);

    int *ptr_arr = calloc(*ptr_inp, sizeof(int));
    for(int i = 0; i < *ptr_inp; i++){
        *(ptr_arr + i) = (i * i);
    }
    for(int i = 0; i < *ptr_inp; i++){
        printf("%d  ", *(ptr_arr + i));
    }
    printf("\n");

    int *ptr_temp = realloc(ptr_arr, (2 * *ptr_inp) * sizeof(int));
    if(ptr_temp == NULL){
        printf("Error couldn't reallocate memory.\n");
        return -1;
    }
    ptr_arr = ptr_temp;

    for(int i = *ptr_inp; i < 2 * *ptr_inp; i++){
        *(ptr_arr + i) = (i * i);
    }

    for(int i = 0; i < 2 * *ptr_inp; i++){
        printf("%d  ", *(ptr_arr + i));
    }
    printf("\n");

    free(ptr_inp);
    free(ptr_arr);
}