#include <string>
#include <cstdint>
#include "reportUtilitys.hpp"


int main(){
    std::string name;
    std::uint_fast16_t homework;
    std::uint_fast16_t midterm;
    std::uint_fast16_t finalExam;
    double finalGrade;
    std::string letterGrade;

    report::readStudent_Data(name, homework, midterm, finalExam);

    report::calculate_Grade(homework, midterm, finalExam, finalGrade, letterGrade);

    report::print_Report(name, homework, midterm, finalExam, finalGrade, letterGrade);

    return 0;
}