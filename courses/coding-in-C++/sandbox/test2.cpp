#include <iostream>

class Base{
    private:
        int num;

    public:
        Base(int num) : num(num){};

        virtual ~Base(){
            std::cout << "Base Object deleted." << std::endl;
        }
};


class Derived : public Base{
    private:
        int num2;

    public:
        Derived(int num, int num2) : Base(num), num2(num2){};

        ~Derived(){
            std::cout << "Derived Object deleted." << std::endl;
        }
};


int main(){
    Base *object = new Derived(1,2);

    delete object;

    return -1;
}