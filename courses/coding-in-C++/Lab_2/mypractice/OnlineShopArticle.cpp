#include <iostream>
#include <string>

class Article {
    private:
        std::string name;
        double price;
        int stock;
        std::string category;
        int id;
    
    public:

    Article(const std::string& name, double price, int stock, const std::string& category, int id) : 
        name(name), price(price), stock(stock), category(category), id(id){}

    ~Article() = default;

    void setPrice(double price) {
        if(price < 0){
            return;
        }
        else{
            this->price = price;
        }
    }

    void sell(int amount) {
        if(amount <= 0){
            return;
        }
        else{
            this->stock -= amount; 
        }
    }

    void restock(int amount) {
        if(amount <= 0){
            return;
        }
        else{
            this->stock += amount;
        }
    }

    void applyDiscount(double percent) {
        if(percent <= 0 || percent >=100){
            return;
        }
        else{
            price = price - price * percent / 100;
        }
    }

    double getPrice() {
        return price; 
    }

    bool isAvailable() {
        return (stock > 0);
    }

    void printInfo() {
        std::cout << "Article: " << name << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.applyDiscount(150);

    if (a.isAvailable()) std::cout << "Article available" << std::endl;

    a.printInfo();
}