#include <stdio.h>

int main(){
    char content[] = "Curly bird catches the worm";
    char *pcontent = &content[0];

    printf("%s\n", content);
    printf("%s\n", pcontent);
    printf("%p\n", pcontent);

}