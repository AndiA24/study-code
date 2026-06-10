#include <iostream>


class Shape{
    public:
        Shape() = default;

        ~Shape(){
            std::cout << "Shape destroyed" << std::endl;
        }

        virtual double getArea() const = 0;
};

class Circle : public Shape{
    private:
        double radius;

    public:
        static constexpr double PI = 3.14;

        Circle(){
            radius = 0.0;
        }

        Circle(double radius) : radius{radius}{}

        double getArea() const override;
};

double Circle::getArea() const{
    return PI * this->radius * this->radius;
}

int main(){
    
    Shape* t = new Circle;

    delete t;


    return 0;
}