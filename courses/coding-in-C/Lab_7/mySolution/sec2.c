#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    double value;
    struct Node *ptr_next;
} Node;

Node *create_node(double value){
    Node *ptr_temp = malloc(sizeof(Node));
    if(ptr_temp == NULL){
        printf("Error while allocating memory.\n");
        return NULL;
    }
    ptr_temp->value = value;
    ptr_temp->ptr_next = NULL;
    return ptr_temp;
}

int main(){
    srand(time(NULL));
    Node *ptr_head = NULL;
    Node *ptr_current = NULL;

    for(int i = 0; i < 50; i++){
        Node *ptr_new = create_node(rand());

        if(ptr_new == NULL){
            printf("Error\n");
        }
        if(ptr_head == NULL){
            ptr_head = ptr_new;
            ptr_current = ptr_head;
        }
        else{
            ptr_current->ptr_next = ptr_new;
            ptr_current = ptr_current->ptr_next;
        }
    }

    int arr[51] = {0};
    for(int i = 0; i < 50; i++){
        arr[i] = rand();
    }

    for(int i = 0; i < 51; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    for(int i = 50; i > 3; i--){
        arr[i] = arr[i - 1];
    }

    arr[3] = rand();

    for(int i = 0; i < 51; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    ptr_current = ptr_head;
    while(ptr_current){
        printf("%f  ", ptr_current->value);
        ptr_current = ptr_current->ptr_next;
    }
    printf("\n");

    ptr_current = ptr_head;
    for(int i = 1; i < 2; i++){
        ptr_current = ptr_current->ptr_next;
    }
    Node *ptr_new = create_node(rand());
    if(ptr_new == NULL){
        printf("Error\n");
        return -1;
    }
    ptr_new->ptr_next = ptr_current->ptr_next;
    ptr_current->ptr_next = ptr_new;

    ptr_current = ptr_head;
    while(ptr_current){
        printf("%f  ", ptr_current->value);
        ptr_current = ptr_current->ptr_next;
    }

    ptr_current = ptr_head;
    while(ptr_current){
        ptr_head = ptr_current->ptr_next;
        free(ptr_current);
        ptr_current = ptr_head;
    }

}