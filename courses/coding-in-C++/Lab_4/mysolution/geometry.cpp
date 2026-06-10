#include <iostream>

class Shape{
    private:

    public:
        virtual double getArea() = 0;
};

class Circle : public Shape{
    private:
        double radius;
        static constexpr double PI = 3.14;

    public:
        Circle() : radius(0.0){}

        Circle(double radius) : radius(radius) {}

        double getArea() override{
            return PI * this->radius * this->radius;
        };
};

class Rectangle : public Shape{
    private:
        double a;
        double b;

    public:
        Rectangle() : a(0.0), b(0.0){}

        Rectangle(double a, double b) : a(a), b(b){}

        double getArea() override{
            return a * b;
        }
};

int main(){
    constexpr int ARR_SIZE = 4;

    Circle circle1(10);
    Circle circle2(20);

    Rectangle rectangle1(5, 5);
    Rectangle rectangle2(10, 10);
    
    Shape* arr[ARR_SIZE] = {&circle1, &circle2, &rectangle1, &rectangle2};

    for(int i = 0; i < 4; i++){
        std::cout << "The Area ist: " << arr[i]->getArea() << std::endl;
    }

    return 0;
}