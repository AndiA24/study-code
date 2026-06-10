/**
 * @file ageValidation.cpp
 * @brief Short script to validate the user age
 */

 #include <iostream>
 #include <limits>
 
 namespace validation{
    constexpr int ADULT_AGE_LIMIT = 18;
    constexpr int SENIOR_AGE_LIMIT = 65;
    constexpr int MAX_AGE = 120;

    bool isAdult(int age){
        return age >= ADULT_AGE_LIMIT;
    }

    bool isSenior(int age){
        return age >= SENIOR_AGE_LIMIT;
    }
 }

 int main(){
    int age = 0;

    while(true){
        std::cout << "Please enter your Age: ";
        if(!(std::cin >> age)){
            std::cout << "The Age you entered was invalid. Please try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),  '\n');
        }
        else if(age <= 0 && age <= validation::MAX_AGE){
            std::cout << "Your input age was not valid. Please try again." << std::endl;
        }
        else{
            std::cout << "Your Age is " << age << " years." << std::endl;
            if(validation::isSenior(age)){
                std::cout << "That means youre an senior Citizen." << std::endl;
            }
            if(validation::isAdult(age)){
                std::cout << "That means youre an Adult." << std::endl;
            }
            else{
                std::cout << "That means youre an Minor." << std::endl;
            }
        }
    }

    return 0;
 }