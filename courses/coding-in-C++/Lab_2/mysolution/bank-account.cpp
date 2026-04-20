#include <iostream>
#include <string>

class BankAccount{
    private:
        std::string owner;
        double balance;

    public:
        double getBalance();

        void getAccountInfo();

        void setOwner(std::string owner){
            this->owner = owner;
        }

        std::string getOwner(){
            return owner;
        }

        void deposit(double depositAmount){
            if(depositAmount <= 0){
                std::cout << "Invalid Value to deposit. Action canceled." << std::endl;
                return;
            }
            balance += depositAmount;
            std::cout << "Deposit sucessful. Your new balance is: " << balance << "€" << std::endl;
            return;
        }

        void withdraw(double withdrawAmount){
            if(withdrawAmount <= 0){
                std::cout << "Invalid Amount to withdraw. Action canceled." << std::endl;
                return;
            }
            balance -= withdrawAmount;
            std::cout << "Withdraw succesfull. Your new balance is: " << balance <<std::endl;
        }
};

double BankAccount::getBalance(){
    return balance;
}

void BankAccount::getAccountInfo(){
    std::cout << "Account Owner is: " << getOwner() << std::endl;
    std::cout << "The current balance is " << getBalance() << std::endl;
}

int main(){

    BankAccount *Acc1 = new BankAccount;

    Acc1->getAccountInfo();

    Acc1->setOwner("Andi");

    Acc1->getAccountInfo();

    Acc1->deposit(200);

    return 0;
}