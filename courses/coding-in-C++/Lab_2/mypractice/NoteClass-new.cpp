#include <string>
#include <iostream>

class Note{
    private:
        std::string* text;

    public:
        Note(const std::string &input){
            this->text = new std::string;
            *text = input;
        }
        Note(const Note& org){
            this->text = new std::string;
            *text = *org.text;
        }

        ~Note(){
            delete text;
        }

        void display(){
            std::cout << *text << std::endl; 
        }
};

int main(){
    Note one("Test1");
    Note two(one);

    one.display();
    two.display();

    return 0;
}