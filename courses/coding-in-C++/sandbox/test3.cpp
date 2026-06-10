#include <iostream>
#include <cmath>

class Calc{
    private:
        static constexpr float pi = 3.14;
        float radius;

    public:
        Calc(float radius) : radius(radius){}

        float getArea(){
            return (this->radius * this->radius * pi);
        }



};

int main(){
    Calc shape1(50);

    std::cout << shape1.getArea();

    return 0;
}