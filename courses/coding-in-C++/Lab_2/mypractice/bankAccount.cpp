#include <string>
#include <iostream>
#include <iomanip>

class BankAccount{
    private:
        std::string owner;
        double balance;

    public:
        BankAccount() : owner{""}, balance{0}{}
        BankAccount(const std::string& owner, double balance) : 
            owner{owner}, balance{balance}{}
        
        void setOwner(const std::string& owner){
            this->owner = owner;
        }

        std::string getOwner() const{
            return this->owner;
        }

        void deposit(double amount){
            if(amount > 0){
                this->balance += amount;
            }
        }

        void withdraw(double amount){
            if(amount > 0 && amount <= this->balance){
                this->balance -= amount;
            }
        }

        double getBalance();

        void getAccountInfo();

};

double BankAccount::getBalance(){
    return this->balance;
}

void BankAccount::getAccountInfo(){
    std::cout << "Account Info" << std::endl;
    std::cout << std::left << std::setw(10) << "Owner" << ": " << getOwner() << std::endl;
    std::cout << std::left << std::setw(10) << "Balance" << ": " << getBalance() << std::endl;
}

int main(){
    BankAccount acc1;
    BankAccount acc2("Andi", 1000);

    acc1.getAccountInfo();
    acc2.getAccountInfo();

    acc1.setOwner("Max Mustermann");
    acc1.deposit(20000);

    acc1.getAccountInfo();
    acc2.getAccountInfo();

    return 0;
}