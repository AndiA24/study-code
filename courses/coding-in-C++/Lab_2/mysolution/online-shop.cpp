#include <iostream>
#include <string>
#include <iomanip>

class Article {
private:
    std::string name;
    double price;
    int stock;
    std::string* category;
    int id;

public:

    Article(std::string name, double price, int stock, std::string itm_category, int itm_id);

    ~Article(){
        delete category;
        category = nullptr;

    }

    void setPrice(double new_price);

    void sell(int sell_amount);

    void restock(int new_amount);

    double applyDiscount(double apl_percent);

    double getPrice();

    bool isAvailable();
    
    void printInfo();
};

Article::Article(std::string name, double price, int stock, std::string itm_category, int itm_id) {
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->id = itm_id;
        this->category = new std::string;
        *this->category = itm_category;
}

void Article::setPrice(double new_price) {
    price = new_price;
}

void Article::sell(int sell_amount) {
    if(stock < sell_amount){
        std::cout << "Cannot sell " << sell_amount << " items. Stock is too low.";
        return;
    }
    stock -= sell_amount;
}

void Article::restock(int new_amount) {
    if(new_amount <= 0){
        std::cout << "Failed to restock. Invalid Arguments. Amount must be higher then 0.";
    }
    this->stock += new_amount;
}

double Article::applyDiscount(double apl_percent) {
    price = price - price * (apl_percent / 100);
    return price;
}

double Article::getPrice() {
    return price;
}

bool Article::isAvailable() {
    if (stock > 0)
        return true;
    else
        return false;
}

void Article::printInfo() {
    std::cout << "Article: " << name << std::endl;
    std::cout << "Category: " << *category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "ID: " << id << std::endl;
}


int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5);
    a.setPrice(-100);
    a.applyDiscount(150);

    if (a.isAvailable()) {
        std::cout << "Article available" << std::endl;
    }

    a.printInfo();
    return 0;
}