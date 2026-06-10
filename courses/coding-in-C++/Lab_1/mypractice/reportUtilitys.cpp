#include "reportUtilitys.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

namespace report{
    constexpr int MAX_SCORE = 100;

    void readStudent_Data(std::string& name, std::uint_fast16_t& homework, 
        std::uint_fast16_t& midterm, std::uint_fast16_t& finalExam){
            bool validInput = 0;
            std::uint_fast16_t input;

            while(!validInput){
                std::cout << "Please enter the Students Name: ";
                if(!getline(std::cin, name)){
                    std::cout << "Your Input was invalid. Please try again." << std::endl;
                }
                else{
                    validInput = true;
                }
            }

            validInput = false;
            while(!validInput){
                std::cout << "Please enter the Homework Grad: ";
                if(!(std::cin >> input)){
                    std::cout << "Your Input was invalid, please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else if(!(input >= 0 && input <= MAX_SCORE)){
                    std::cout << "The Score is not valid. Please try again." << std::endl;
                }
                else{
                    homework = input;
                    validInput = true;
                }            
            }

            validInput = false;
            while(!validInput){
                std::cout << "Please enter the Midterm Grad: ";
                if(!(std::cin >> input)){
                    std::cout << "Your Input was invalid, please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else if(!(input >= 0 && input <= MAX_SCORE)){
                    std::cout << "The Score is not valid. Please try again." << std::endl;
                }
                else{
                    midterm = input;
                    validInput = true;
                }            
            }

            validInput = false;
            while(!validInput){
                std::cout << "Please enter the Final Exam Grad: ";
                if(!(std::cin >> input)){
                    std::cout << "Your Input was invalid, please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else if(!(input >= 0 && input <= MAX_SCORE)){
                    std::cout << "The Score is not valid. Please try again." << std::endl;
                }
                else{
                    finalExam = input;
                    validInput = true;
                }            
            }
    }

    void calculate_Grade(const std::uint_fast16_t& homework, const std::uint_fast16_t& midterm, 
        const std::uint_fast16_t& finalExam, double& finalGrade, std::string& letterGrade){
            constexpr std::uint_fast16_t HOMEWORK_PERCENT = 40;
            constexpr std::uint_fast16_t MIDTERM_PERCENT = 25;
            constexpr std::uint_fast16_t FINAL_PERCENT = 35;

            finalGrade = (HOMEWORK_PERCENT * homework + 
                MIDTERM_PERCENT * midterm + FINAL_PERCENT * finalExam) / 100.0;

            if(finalGrade >= 90){
                letterGrade = "A";
            }
            else if(finalGrade >= 80){
                letterGrade = "B";
            }
            else if(finalGrade >= 70){
                letterGrade = "C";
            }
            else if(finalGrade >= 60){
                letterGrade = "D";
            }
            else if(finalGrade >= 50){
                letterGrade = "E";
            }
            else{
                letterGrade = "F";
            }
    }

    void print_Report(const std::string& name, const std::uint_fast16_t& homework, 
        const std::uint_fast16_t& midterm, const std::uint_fast16_t& finalExam, 
        const double& finalGrade, const std::string& letterGrade){
            std::string studentStatus;
            if(letterGrade == "A" || letterGrade == "B" || letterGrade == "C"){
                studentStatus = "PASS";
            }
            if(letterGrade == "D" || letterGrade == "E"){
                studentStatus = "CONDITIONAL PASS";
            }
            if(letterGrade == "F"){
                studentStatus = "FAIL";
            }

            // print
            std::cout << "-------------------------------------" << std::endl;
            std::cout << "Name: " << name << std::endl << std::endl;
            std::cout << "Scores" << std::endl;
            std::cout << "-------------------------------------" << std::endl;
            std::cout << std::left << std::setw(16) << "Homework " << ": " << std::setprecision(4)<< homework << std::endl;
            std::cout << std::left << std::setw(16) << "Midterm " << ": " << std::setprecision(4) << midterm << std::endl;
            std::cout << std::left << std::setw(16) << "Final Exam " << ": " << std::setprecision(4) << finalExam << std::endl << std::endl;
            std::cout << std::left << std::setw(16) << "Final Grade " << ": " << std::setprecision(4) << finalGrade << std::endl;
            std::cout << std::left << std::setw(16) << "Letter Grade " << ": " << letterGrade << std::endl;
            std::cout << std::left << std::setw(16) << "Status " << ": " << studentStatus << std::endl;
            std::cout << "-------------------------------------" << std::endl;

    }
}

