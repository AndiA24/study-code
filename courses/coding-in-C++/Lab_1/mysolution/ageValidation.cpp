#include <iostream>
#include <iomanip>
#include <cstdint>

namespace validation{
    const std::uint8_t AGE_LIMIT_ADULT = 18;
    const std::uint8_t AGE_LIMIT_SENIOR = 65;

    bool isAdult(std::uint8_t age){
        return age >= AGE_LIMIT_ADULT;
    }

    bool isSenior(std::uint8_t age){
        return age >= AGE_LIMIT_SENIOR;
    }
}

int main(){
    std::uint8_t AGE_LIMIT_VALIDATION = 120;
    int age;
    bool invalid_input = false;


    do{
        std::cout << "Please enter youre Age: ";

        std::cin >> age;
        if(age >= AGE_LIMIT_VALIDATION || age < 0){
            std::cout << "Invalid Input. Age must be between 0 and 120." << std::endl;
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