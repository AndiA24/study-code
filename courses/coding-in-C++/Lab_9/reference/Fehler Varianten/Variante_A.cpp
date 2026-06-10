#include <iostream>

template <typename T, std::size_t n>
void printArray(T (&arr)[n]) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[4] = {5, 2, 8, 1};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        printArray(arr);
    }

    return 0;
}