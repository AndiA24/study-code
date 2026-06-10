#include <iostream>

template <typename A>
void swapValues(A& first, A& second){
    A temp = first;
    first = second;
    second = temp;
}

int main(){
    int f = 5;
    int s = 10;

    std::cout << "The values are: " << f << " and: " << s << std::endl;

    swapValues(f, s);

    std::cout << "The values are: " << f << " and: " << s << std::endl;

    return 0;
}