#include <iostream>

template <typename A, std::size_t N>
void printFrame(const A (&arr)[N]){
    std::cout << "[";
    for(int i = 0; i < N - 1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(){
    int arr1[5] = {1,2,3,4,5};
    double arr2[5] = {1.1,1.2,1.3,1.4,1.5};

    printFrame(arr1);

    printFrame(arr2);


    return 0;
}