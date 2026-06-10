#include <string>
#include <iostream>

class Note{
    private:
        std::string* text;

    public:
        Note(std::string text){
            this->text = new std::string;
            *(this->text) = text;
        }

        ~Note(){
            delete text;
            text = nullptr;
            std::cout << "Memory released." << std::endl;
        }

        void display(){
            std::cout << "The Text of the Note:" << std::endl << *text << std::endl;
        }
        
};

int main(){
    Note first("Das ist ein Test.");
    Note second(first);


    first.display();
    second.display();

    return 0;
}