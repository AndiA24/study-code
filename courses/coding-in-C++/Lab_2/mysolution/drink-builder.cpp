/**
 * @file drink-builder.cpp
 * @brief Short Script to mix a drink using method caining
 * 
 * This script creates a DrinkBuilder Class Containing a DrinkBuilder 
 * Object to save the info about the drink. 
 * Furthermore the class contains the methods to change the config 
 * of the drinks using method-chaning.
 * 
 */
#include <iostream>
#include <string>

class DrinkBuilder{
private:
    std::string name;
    int sugar;
    int temperature;
    static constexpr int default_temperature = 55;
    bool with_milk;

public:
    DrinkBuilder(){
        temperature = default_temperature;
    }
    
    /**
     * @brief Changes the name of the drink
     * 
     * This Function changes the name of the drink to the param.
     * 
     * @param[in] name  new name for the drink
     * @return Returns reference to current object
     */
    DrinkBuilder& setName(const std::string &name);

    /**
     * @brief Changes the amount of sugar
     * 
     * This fuction changes the amount of sugar in the drink.
     * 
     * @param[in] sugar Amount of sugar in the drink
     * @return Returns reference to current object
     */
    DrinkBuilder& setSugar(int sugar);

    /**
     * @brief Changes the temperature of the drink
     * 
     * This function changes the temerature of the drink to 
     * the given param.
     * 
     * @param[in] temperature   New temperature for the drink
     * @return returns reference to current object
     */
    DrinkBuilder& setTemperature(int temperature);

    /**
     * @brief Sets if the drink contains milk
     * 
     * This function changes wether the drink contains 
     * milk or not.
     * 
     * @param[in] with_milk true for with milk, false for without
     * @return returns reference to current object
     */
    DrinkBuilder& setWithMilk(bool with_milk);

    /**
     * @brief Checks wether the drink-config is valid
     * 
     * This function checks wether the current drink-config 
     * is valid or not.
     * 
     * @return Returns true if valid and false if not
     */
    bool isValid();

    /**
     * @brief Prints the config of the drink
     * 
     * This function prints the config / info about 
     * the drink.
     */
    void print() const;

};

DrinkBuilder& DrinkBuilder::setName(const std::string &name){
    this->name = name;
    return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(int sugar){
    if(sugar < 0){
        sugar = 0;
    }
    this->sugar = sugar;
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature(int temperature){
    if(temperature < 0){
        temperature = 0;
    }
    this->temperature = temperature;
    return *this;
}

DrinkBuilder& DrinkBuilder::setWithMilk(bool with_milk){
    this->with_milk = with_milk;
    return *this;
}

bool DrinkBuilder::isValid(){
    if(name.empty()){
        return false;
    }
    if(sugar < 0){
        return false;
    }
    if(temperature < 0){
        return false;
    }
    return true;
}

void DrinkBuilder::print() const{ 
    std::cout << "Your Drink:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Sugar: " << sugar << "g" << std::endl;
    std::cout << "Temperatur: " << temperature << std::endl;
    std::cout << "With Milk: ";
    if(with_milk){
        std::cout << "yes" << std::endl;
    }
    else{
        std::cout << "no" << std::endl;
    }
}


int main(){
    DrinkBuilder drink;
    drink.setName("Vodka")
         .setSugar(2)
         .setTemperature(5)
         .setWithMilk(false);
    drink.print();
}