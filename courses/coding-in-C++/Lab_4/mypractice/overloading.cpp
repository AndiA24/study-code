#include <iostream>
#include <cmath>

class Vector2D{
    private:
        double x;
        double y;

    public:
        Vector2D() = default;

        Vector2D(double x, double y) : x(x), y(y){}

        ~Vector2D() = default;

        void setX(double x){
            this->x = x;
        }

        void setY(double y){
            this->y = y;
        }

        double getX() const{
            return this->x;
        }

        double getY() const{
            return this->y;
        }

        void print() const{
            std::cout << "The Vector is:" << std::endl;
            std::cout << "X: " << getX() << std::endl;
            std::cout << "Y: " << getY() << std::endl;
        }

        double getLenght() const{
            return std::sqrt(x * x + y * y);
        }

        double getLenght(int precision) const{
            double lenght = std::sqrt(x * x + y * y);
            double factor = std::pow(10.0, precision);
            return std::round(lenght * factor) / factor;
        }

        void operator+=(const Vector2D& Vec2){
            this->x += Vec2.getX();
            this->y += Vec2.getY();
            return;
        }

        void operator*(int scalar){
            this->x = this->x * scalar;
            this->y = this->y * scalar;
        }

};

Vector2D operator+(const Vector2D& Vec1, const Vector2D& Vec2){
    return Vector2D(Vec1.getX() + Vec2.getX(), Vec1.getY() + Vec2.getY());
}

void operator*(int scalar, Vector2D& Vec){
    Vec.setX(scalar * Vec.getX());
    Vec.setY(scalar * Vec.getY());
    return;
}




int main(){

    Vector2D newVec(3.0, 5.5);

    newVec.print();

    std::cout << newVec.getLenght() << std::endl;

    std::cout << newVec.getLenght(1) << std::endl;

    newVec * 2;

    newVec.print();

    2 * newVec;

    newVec.print();

    
    return 0;
}