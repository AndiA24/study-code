#include <string>

class Product{
    private:
        int id;
        std::string name;

    public:
        Product(int id, const std::string &name) : id(id), name(name){};
        virtual ~Product(){};

};

class CombustionEngine : public Product{
    private:
        double weight;
        double temperature;
        bool visualDamage;

    public:
        CombustionEngine(int id, const std::string &name, double weight, 
                    double temperature, bool visualDamage) 
                    : Product(id, name), weight(weight), 
                    temperature(temperature), visualDamage(visualDamage){};

};

class ElectricEngine : public Product{
    private:
        double weight;
        double temperature;
        double voltage;
        bool visualDamage;

    public:
        ElectricEngine(int id, const std::string &name, double weight, 
                    double temperature, double voltage, bool visualDamage) 
                    : Product(id, name), weight(weight), 
                    temperature(temperature), voltage(voltage), 
                    visualDamage(visualDamage){};
};