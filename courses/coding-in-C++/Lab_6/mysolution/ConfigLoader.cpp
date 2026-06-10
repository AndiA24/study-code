#include <iostream>
#include <string>
#include <stdexcept>

class ConfigErr : std::logic_error{
    public:
    ConfigErr(const std::string& msg) : std::logic_error(msg){};
};

class ConfigLoader{
    private:

    public:
        void load(const std::string filename){
            if(filename.empty()){
                throw std::invalid_argument("Empty Filename.");
            }
            if(filename.substr(filename.length() - 4) != ".cfg"){
                throw std::invalid_argument("Wrong Fileformat.");
            }
            if(filename == "missing.cfg"){
                throw std::runtime_error("Configfile not found.");
            }
            if(filename == "invalid.cfg"){
                throw ConfigErr("Config is invalid");
            }
        }
};

int main(){
    ConfigLoader Test;
    try{
        Test.load("file.cfg");
    }
    catch(std::invalid_argument& err){
        std::cout << "Catch 1: " << err.what() << std::endl;
    }
    catch(std::runtime_error& err){
        std::cout << "Catch 2: " << err.what() << std::endl;
    }
}