#include <iostream>

template <typename T, typename T2>
class Pair{
    private:
        T t;
        T2 t2;

    public:
        Pair(T t, T2 t2): t(t), t2(t2){}

        void setT(T t){
            this->t = t;
        }

        void setT2(T2 t2){
            this->t2 = t2;
        }

        T getT(){
            return t;
        }

        T2 getT2(){
            return t2;
        }

};

int main(){

    Pair first = Pair(4, 5.5);

    std::cout << "First Value: " << first.getT() << std::endl;
    std::cout << "Second Value " << first.getT2() << std::endl;


    return 0;
}