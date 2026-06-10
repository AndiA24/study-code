#include <string>
#include <iostream>

class DrinkBuilder{
    private:
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;

        static constexpr int defaultTemperature = 7;
        static constexpr int maxTemperature = 90;

    public:
        DrinkBuilder() = default;
        ~DrinkBuilder() = default;

        DrinkBuilder& setName(const std::string& name){
            this->name = name;
            return *this;
        }

        DrinkBuilder& setSugar(int sugar){
            this->sugar = sugar;
            return *this;
        }

        DrinkBuilder& setTemperature(int temperature){
            this->temperature = temperature;
            return *this;
        }

        DrinkBuilder& setWithMilk(bool withMilk){
            this->withMilk = withMilk;
            return *this;
        }

        const void print(){
            using namespace std;
            cout << "Your Drink: " << endl << endl;
            cout << "Name: " << this->name << endl;
            cout << "Sugar: " << this->sugar << "g" << endl;
            cout << "Temperature: " << this->temperature << "°C" << endl;
            this->withMilk ? cout << "With Milk" : cout << "Without Milk";
            cout << endl;
        }

        const bool isValid(){
            if(this->sugar < 0){
                return false;
            }
            if(this->temperature < 0 || this->temperature > maxTemperature){
                return false;
            }
            return true;
        }

};

int main(){

    DrinkBuilder newDrink;

    newDrink.setName("Testgetränk")
            .setSugar(10)
            .setTemperature(80)
            .setWithMilk(false);
    
    newDrink.print();

    std::cout << std::boolalpha << "Drink is valid: " << newDrink.isValid() << std::endl;
    

    return 0;
}