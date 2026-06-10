#include <iostream>

template <typename T, typename P>

class Pair{
    private:
        T one;
        P two;

    public:
        Pair(T one, P two) : one{one}, two{two}{}

        ~Pair() = default;

        T getOne(){
            return one;
        }

        P getTwo(){
            return two;
        }

        void setOne(T one){
            this->one = one;
        }

        void setTwo(P two){
            this->two = two;
        }
};

int main(){
    Pair first(4.8, 90);

    std::cout << "One: " << first.getOne() << std::endl;
    std::cout << "Two: " << first.getTwo() << std::endl;

    return 0;
}