/** 
 * @file online-shop.cpp
 * @brief This file contains the logic to handle online shop articles
 * 
 * This file contains logic to create online-shop articles as objects of the
 * class Article the Article object contains the information about the article
 * (e.g. name, price, category...). 
 * Furthermore the class contains the necessary methods to manage the articles
 * (e.g. sell, restock...).
 */
#include <iostream>
#include <string>
#include <iomanip>

class Article {
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;

public:

    Article(const std::string &name, double price, int stock, const std::string &category, int id);

    /**
     * @brief Function to update the Price of an Article
     * 
     * The input is validatet (higher then 0) and set.
     * 
     * @param[in] new_price     New Price for the article
     * @return Returns true for success and false for fail
     */
    bool setPrice(double new_price);

    /**
     * @brief Function to sell given amount of an Article
     * 
     * This function validates the amount that should be sold (postive & higher
     * then 0) and removes it from stock.
     * 
     * @param[in] sell_amount   Amount of the Article that should be sold
     * @return Returns true for success and false for fail
     */
    bool sell(int sell_amount);

    /**
     * @brief Function to higher the stock of an article
     * 
     * This function validates the input (positive & higher then 0) and
     * adds the given amount to the stock amount
     * 
     * @param[in]   new_amount  Amount of pices to add to stock
     * @return Returns true for success and false for fail
     */
    bool restock(int new_amount);

    /**
     * @brief Function to apply Discount to an article
     * 
     * This function validates the input Discount (must be higher then 0.0
     * and lower then 100.0) and applys it to the artuicle Price
     * 
     * @param[in] apl_percent Discount to apply to price in percents 
     * @return Returns true for success and false for fail
     */
    bool applyDiscount(double apl_percent);

    /**
     * @brief Function to get the price of an article
     * 
     * This function returns the current price of an article.
     * 
     * @return The Price of the article
     */
    double getPrice() const{
        return price;
    }

    /**
     * @brief Function to check if an Article is available
     * 
     * This function checks wether an article is availerble (stock 
     * > 0) or not.
     * 
     * @return Returns true for available and false for not available
     */
    bool isAvailable() const{
        return stock > 0;
    }
    
    /**
     * @brief Function to print the article info to the console
     * 
     * This function prints all article info (name, price, stock...)
     * to the console.
     */
    void printInfo() const;
};

Article::Article(const std::string &name, double price, int stock, const std::string &category, int id) 
    : name{name}, price{price}, stock{stock}, category{category}, id{id}{
}

bool Article::setPrice(double new_price) {
    if(new_price <= 0){
        std::cout << "Failed to change the Price. New Price must be higher than zero." << std::endl;
        return false;
    }
    if(new_price == price){
        std::cout << "Price was not updated, new price equals the current." << std::endl;
        return false;
    }
    price = new_price;
    return true;
}

bool Article::sell(int sell_amount) {
    if(sell_amount <= 0){
        std::cout << "Cannot sell " << sell_amount << " items. The amount must be higher then 0." << std::endl;
        return false;
    }
    if(stock < sell_amount){
        std::cout << "Cannot sell " << sell_amount << " items. Stock is too low." << std::endl;
        return false;
    }
    stock -= sell_amount;
    return true;
}

bool Article::restock(int new_amount) {
    if(new_amount <= 0){
        std::cout << "Failed to restock. Invalid Arguments. Amount must be higher then 0." << std::endl;
        return false;
    }
    this->stock += new_amount;
    return true;
}

bool Article::applyDiscount(double apl_percent) {
    if(apl_percent <= 0 || apl_percent >= 100){
        std::cout << "Failed to apply Discount. Discount must be between 0 and 100 percents." << std::endl;
        return false;
    }
    price = price - price * (apl_percent / 100);
    return true;
}

void Article::printInfo() const{
    std::cout << "Article: " << name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "ID: " << id << std::endl;
}


int main() {
    Article article1("Laptop", 999.99, 10, "Electronics", 101);

    article1.sell(15);
    article1.restock(-5);
    article1.setPrice(-100);
    article1.applyDiscount(150);

    if (article1.isAvailable()) {
        std::cout << "Article available" << std::endl;
    }

    article1.printInfo();
    return 0;
}