#include <stdio.h>

int main(){
    int myNumbers[] = {10,20,30,40,50};
    int *pNum1 = myNumbers[1];
    int *pNum2 = pNum1 + 3;
    int diff = pNum2 - pNum1;

    printf("Adresse von Element 1: %p\n", pNum1);
    printf("Adresse von Element 2: %p\n", pNum2);
    printf("Adressdifferenz zwischen 2. und 4. Element: %d", diff);
    return 0;
}