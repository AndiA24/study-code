#include <iostream>
#include <string>
#include <limits>

void readStudentData(std::string &name, int &homework, 
                        int &midterm, int &finalExam){
    
    bool validInput = false;
    do{
        std::cout << "Please enter youre Name: ";
        
        if(!getline(std::cin, name)){
            std::cout << "Invalid Input, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
            validInput = true;
        }
    }while(!validInput); 

    int grade[3];
    for(int i = 0; i < 3; i++){
        validInput = false;
        do{
            std::cout << "Please enter your ";
            if(i == 0){
                std::cout << "homework grade: ";
            }
            if(i == 1){
                std::cout << "midterm grade: ";
            }
            if(i == 2){
                std::cout << "final grade: ";
            }
            if(!std::cin >> grade[i]){
                std::cout << "Invalid Input. Please try again." << std::endl;
            }
            else{
                if()
                validInput = true;
            }
        } while(!validInput);
    }

    homework = grade[0];
    midterm = grade[1];
    finalExam = grade[2];

}