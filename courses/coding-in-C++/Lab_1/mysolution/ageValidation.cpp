#include <iostream>
#include <iomanip>
#include <cstdint>
#include <limits>

namespace validation{
    const std::uint8_t AGE_LIMIT_ADULT = 18;
    const std::uint8_t AGE_LIMIT_SENIOR = 65;
    const uint8_t AGE_LIMIT_VALIDATION = 120;


    bool isAdult(std::uint8_t age){
        return age >= AGE_LIMIT_ADULT;
    }

    bool isSenior(std::uint8_t age){
        return age >= AGE_LIMIT_SENIOR;
    }
}

int main(){
    int age;
    bool invalid_input = false;


    do{
        std::cout << "Please enter youre Age: ";

        if(!(std::cin >> age)){
            std::cout << "Your Input was not valid. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if(age >= validation::AGE_LIMIT_VALIDATION || age < 0){
            std::cout << "Invalid Input. Age must be between 0 and " << static_cast<int>(validation::AGE_LIMIT_VALIDATION) << "." << std::endl;
            invalid_input = true;
        }
        else{
            invalid_input = false;
        }
    } while (invalid_input);
    
    std::cout << "Your age is " << age << " years old." << std::endl;

    std::cout << "That means that you are ";

    if(!validation::isAdult(age)){
        std::cout << "still a kid or teenager." << std::endl;
    }

    if(validation::isSenior(age)){
        std::cout << "a senior citizen" << std::endl;
        return 0;
    }


    if(validation::isAdult(age)){
        std::cout << "an adult." << std::endl;
    }

    return 0;
}