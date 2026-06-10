#ifndef REPORT_UTILITYS_HPP
#define REPORT_UTILITYS_HPP
#include <string>

namespace report{
    void readStudent_Data(std::string& name, std::uint_fast16_t& homework, 
        std::uint_fast16_t& midterm, std::uint_fast16_t& finalExam);

    void calculate_Grade(const std::uint_fast16_t& homework, const std::uint_fast16_t& midterm, 
        const std::uint_fast16_t& finalExam, double& finalGrade, std::string& letterGrade);

    void print_Report(const std::string& name, const std::uint_fast16_t& homework, 
        const std::uint_fast16_t& midterm, const std::uint_fast16_t& finalExam, 
        const double& finalGrade, const std::string& letterGrade);
}

#endif