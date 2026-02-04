#include<stdio.h>

int main(){
    unsigned int arr1[][3] = {{1, 2, 3}, {4, 5, 6}};
    unsigned int arr2[][3] = {{7, 8, 9}, {10, 11, 12}};

    unsigned int rows = sizeof(arr1) / sizeof(arr1[0]);
    unsigned int cols = sizeof(arr1[0]) / sizeof(arr1[0][0]);
    unsigned int arr3[rows][cols];


    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            arr3[i][j] = arr1[i][j];
        }
    }

    // arr2 -> arr1
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            arr1[i][j] = arr2[i][j];
        }
    }

    // arr3 -> arr2
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            arr2[i][j] = arr3[i][j];
        }
    }

    return 0;
}