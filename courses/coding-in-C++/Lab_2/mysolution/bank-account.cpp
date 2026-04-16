#include <iostream>
#include <string>

class BankAccount{
    private:
        std::string owner;
        double balance;

    public:
        void setOwner(std::string ownerName){
            owner = ownerName;
        }

        std::string getOwner(){
            return owner;
        }

        double getBalance();

        void getAccountInfo();

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

void BankAccount::getAccountInfo(){
    
}