#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clear_buffer(){
    int c;
    while((c = getchar()) != '\n');
}

void check_paliandrome(char input[], char *p_answer){
    int lenght = strlen(input);
    // printf("Lenght: %d", lenght);
    for(int i = 0; i < lenght; i++){
        input[i] = tolower(input[i]);
    }
    for(int i = 0; i < (int)(lenght / 2); i++){
        if(input[i] != input[(lenght - i - 1)]){
            strcpy(p_answer, "Your Input is not a paliandrome");
            return;
        }
    }
    strcpy(p_answer, "Your Input is a paliandrome");
    return;
}

int main(){
    char input[101];
    char answer[35];
    char *p_answer = answer;

    printf("%s", "Enter your String (max. 100 characters): ");
    
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; //remove \n from string
    
    if(strchr == NULL){
        clear_buffer();
    }
    
    printf("Your Input: %s\n", input);

    check_paliandrome(input, p_answer);
    printf("%s\n", answer);

    return 0;
}