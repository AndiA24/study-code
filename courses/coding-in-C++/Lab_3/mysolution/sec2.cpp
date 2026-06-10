#include <iostream>
#include <string>

class User{
    protected:
        std::string name;
        int id;

    public:
        User(std::string &name, int id) : name(name), id(id){};

        void print_info() const{
            std::cout << "Name: " << name << std::endl;
            std::cout << "ID: " << id << std::endl;
        }
};

class Student : public User{
    protected:
        int year;

    public:
        Student(std::string name, int id, int year) : User(name, id), year(year){};

        void print_year() const{
            std::cout << "Year: " << year << std::endl;
        }

        void print_role() const{
            std::cout << "Role: Student" << std::endl;
        }
};

class Instructor : public User{
    protected:
        std::string subject;

    public:
        Instructor(std::string subject) : User(name, id){};

        void print_subject(){
            std::cout << "Subject: " << subject << std::endl;
        }
};