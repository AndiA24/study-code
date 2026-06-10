#include <iostream>

#define PI 3.14

class Shape{
    private:

    public:
        virtual double getArea() = 0;

        virtual ~Shape(){};
};

class Circle : public Shape{
    private:
        double radius;

    public:
        Circle(double radius) : radius(radius){};
        double getArea() override{
            return (PI * radius * radius);
        }
};

class Rectangle : public Shape{
    private:
        double a;
        double b;

    public:
        Rectangle(double a, double b) : a(a), b(b){};
        double getArea() override{
            return (a * b);
        }

};

int main(){
    Circle *newCircle = new Circle(10);
    std::cout << "The Area is: " << newCircle->getArea() << std::endl;

    Rectangle *newRectangle = new Rectangle(5, 5);
    std::cout << "The Area is: " << newRectangle->getArea() << std::endl;

    Shape *shape[4];
    shape[0]= new Circle(10);
    shape[1] = new Circle(20);
    shape[2] = new Rectangle(10, 10);
    shape[3] = new Rectangle(20, 20);

    for(int i = 0; i < 4; i++){
        std::cout << "The Area of the object in field " << i << " is: " << shape[i]->getArea() << std::endl;
    }


    return -1;
}