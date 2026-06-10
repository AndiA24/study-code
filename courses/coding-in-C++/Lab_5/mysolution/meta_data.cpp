#include <iostream>
#include <string>

template <typename A>
class Pair{
    private:
        std::string label;
        A value;

    public:
        Pair(){}

        Pair(std::string label, A value) : label(label), value(value){}

        std::string getLabel() const{
            return this->label;
        }

        A getValue() const{
            return this->value;
        }
};

template <typename A, typename B>
void printPair(const Pair<A>& p1, const Pair<B>& p2){
    std::cout << p1.getLabel() << ": " << p1.getValue() << 
    " | " << p2.getLabel() << ": " << p2.getValue() << std::endl;
}

int main(){
    Pair<int> pair1("Channel", 3);
    Pair<double> pair2("Alt", 403.67);

    printPair(pair1, pair2);

    return 0;
}