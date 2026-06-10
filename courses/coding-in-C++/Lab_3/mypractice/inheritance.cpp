#include <string>
#include <iostream>

class User{
    protected:
        std::string name;
        int id;

    public:
        User(const std::string& name, int id) : name(name), id(id){}
    
        void printInfo(){
            std::cout << "User Info:" << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "ID: " << id << std::endl << std::endl;
        }
};

class Student : public User{
    private:
        int year;

    public:
        Student(const std::string& name, int id, int year) : User(name, id), year(year) {}
};

class Teacher : public User{
    private:
        std::string subject;

    public:
        Teacher(const std::string& name, int id, const std::string& subject) : User(name, id), subject(subject){}
};

int main(){

    User neuer("Andi", 1);

    Teacher neuerTeacher("Andi", 2, "IT");

    Student neuerStudent("Andi", 3, 13);

    neuer.printInfo();
    neuerStudent.printInfo();
    neuerTeacher.printInfo();

    return 0;
}