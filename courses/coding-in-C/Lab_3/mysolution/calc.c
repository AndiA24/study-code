#include<stdio.h>

int main(){
    char opperator;
    float firstNum;
    float secondNum;
    float result;

    while(1){
        char opperator = 0;
        printf("------------------C-Console Calculator------------------\n");
        printf("Please chose the Opperator you want to use:\nAddition: +\n Subtraction: -\n Multiplication: *\n Division: /\n\n");
        if (scanf("%c", &opperator) == 1){
            if(!(opperator == '+' || opperator == '-' || opperator == '*' || opperator == '/')){
                printf("Ungültige Eingabe: Es sind nur die Opperatoren '+', '-', '*' und '/' erlaubt\n");                
            }
        }
        if (opperator != 0){
            printf("Please enter the first Number: ");
            scanf("%f", &firstNum);
            printf("Please enter the second Number: ");
            if(scanf("%f", &secondNum) == 1){
                if(opperator = '/' && (secondNum == 0)){
                    printf("You cant divide a Number by zero.\n");
                }
                else{
                    if(opperator == '+'){
                        result = firstNum + secondNum;
                    }
                    if(opperator == '-'){
                        result = firstNum - secondNum;
                    }
                    if(opperator == '*'){
                        result = firstNum * secondNum;
                    }
                    if(opperator == '/'){
                        result = firstNum / secondNum;
                    }
                }
                printf("The Result of your Calculation is: %f\n", result);
            }
        }
    }
    return 0;
}
