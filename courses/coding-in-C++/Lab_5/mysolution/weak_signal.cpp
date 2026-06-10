#include <iostream>

template <typename A, std::size_t N>
A getWeakest(A (&arr)[N]){
    A temp = arr[0];
    for(int i = 0; i < N; i++){
        if(arr[i] < temp){
            temp = arr[i];
        }
    }

    return temp;
}

int main(){
    int arr1[5] = {1,2,3,-2,5};
    double arr2[5] = {1.1,1.2,1.3,1.4,1.5};

    std::cout << "The smallest Member is: " << getWeakest(arr1) << std::endl;
    std::cout << "The smallest Member is: " << getWeakest(arr2) << std::endl;

    return 0;
}