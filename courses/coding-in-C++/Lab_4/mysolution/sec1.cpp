/**
 * @file sec1.cpp
 * @brief simple arithmetic operations for 2D Vectors
 */
#include <iostream>
#include <cmath>

class Vector2D{
    private:
        double x;
        double y;
    
    public:
        Vector2D() : x(0.0), y(0.0) {}

        Vector2D(double x, double y) : x(x), y(y){}

        double getX() const{
            return this->x;
        }
        
        double getY() const{
            return this->y;
        }

        Vector2D operator+(const Vector2D &sum1){
            return Vector2D(this->getX() + sum1.x, this->getY() + sum1.y);
        }

        void operator+=(const Vector2D &sum1){
            this->x = (this->getX() + sum1.x);
            this->y = (this->getY() + sum1.y);
        }

        void printVec() const;

        double getLenght() const;

        double getLenght(int precision) const;

        bool operator==(const Vector2D& vec2);

        bool operator!=(const Vector2D& vec2);
};

void Vector2D::printVec() const{
    std::cout << "Vector Coordinates are:" << std::endl;
    std::cout << "x: " << this->getX() << std::endl;
    std::cout << "y: " << this->getY() << std::endl;
}

double Vector2D::getLenght() const{
    double lenght = 0;
    lenght = sqrt(this->getX() * this->getX() + this->getY() * this->getY());
    return lenght;
}

double Vector2D::getLenght(int precision) const{
    if(precision < 0){
        return -1;
    }
    double lenght = 0;
    lenght = sqrt(this->getX() * this->getX() + this->getY() * this->getY());

    double factor = std::pow(10.0, precision);
    return std::round(lenght * factor) / factor;
}

Vector2D operator*(double scalar, const Vector2D& vector){
    return Vector2D(scalar * vector.getX(), scalar * vector.getY());
}

Vector2D operator*(const Vector2D& vector, double scalar){
    return Vector2D(scalar * vector.getX(), scalar * vector.getY());
}

bool Vector2D::operator==(const Vector2D& vec2){
    const double EPSILON = 1e-8;
    return(std::fabs(this->getX() - vec2.getX()) < EPSILON &&
            std::fabs(this->getY() - vec2.getY()) < EPSILON);
}

bool Vector2D::operator!=(const Vector2D& vec2){
    const double EPSILON = 1e-9;
    return(std::fabs(this->getX() - vec2.getY() > EPSILON &&
            std::fabs(this->getY() - vec2.getY() > EPSILON)));
}

int main(){
    Vector2D vec1(2,2);
    Vector2D vec2(1,1);
    vec1.printVec();
    vec2.printVec();

    std::cout << "Lenght of vec1: " << vec1.getLenght() << std::endl;

    Vector2D vec3 = vec1 + vec2;
    vec3.printVec();

    vec2 += vec1;
    vec2.printVec();

    return -1;
}