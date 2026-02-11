#include <stdio.h>

void letter_change(char str[]){
    *(str + 1) = 'c';

}

int main(){
    char content[] = "Curly bird catches the worm";
    char *p_content = &content[0];

    char str2[] = "AAtions speak louder than words";

    printf("%s\n", content);
    printf("%s\n", p_content);
    printf("%p\n", p_content);

    *(p_content) = 'E';
    *(p_content + 1) = 'a';

    printf("%s\n", content);

    printf("\n");
    printf("%s\n", str2);
    letter_change(str2);
    printf("%s\n", str2);


}