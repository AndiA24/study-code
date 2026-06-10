#include <iostream>

class Foo{

    private:


    public:
        constexpr static float pi = 3.14;
        int value;

        Foo(int value) : value{value} {}

};


int main(){

    Foo obj1(5);

    std::cout << obj1.value;
    std::cout << obj1.pi;
    
    return 0;
}