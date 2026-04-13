#include <iostream>
#include <string>

class textMessage{
    private:
        std::string *content;
    
    public:
        textMessage(std::string input){
            content = new std::string;
            *content = input;
        }

        ~textMessage(){
            delete content;
            content = nullptr;
            std::cout << "Memory released." << std::endl;
        }

        void display();
};

void textMessage::display(){
    std::cout << "Text conent: " << *content << std::endl;
}

int main(){
    textMessage message1("Test Text");
    message1.display();

    return 0;
}