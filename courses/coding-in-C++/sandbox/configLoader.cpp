#include <iostream>
#include <string>
#include <stdexcept>

class CorruptFile : public std::logic_error{
    public:
        CorruptFile() : std::logic_error("Corrupted Config File."){}
};

class ConfigLoader{
    public:
        static void load(const std::string &filename){
            if(filename == ""){
                throw std::invalid_argument("Input cannot be empty.");
            }
            if(filename.find(".cfg") == filename.length()){
                throw std::invalid_argument("File must be .cfg.");
            }
            if(filename == "missing.cfg"){
                throw std::runtime_error("Failed to open File.");
            }
            if(filename == "invalid.cfg"){
                throw CorruptFile();
            }
        }
};

int main(){
    try{
        ConfigLoader::load("");
    }
        catch(const std::invalid_argument &err){
        std::cout << "Error: " << err.what();
    }
    catch(const std::runtime_error &err){
        std::cout << "Error: " << err.what();
    }
    catch(const CorruptFile &err){
        std::cout << "Error: " << err.what(); 
    }
    catch(const std::exception &err){
        std::cout << "Error: " << err.what();
    }
    catch(...){
        std::terminate();
    }

    try{
        ConfigLoader::load(".cfg");
    }
        catch(const std::invalid_argument &err){
        std::cout << "Error: " << err.what();
    }
    catch(const std::runtime_error &err){
        std::cout << "Error: " << err.what();
    }
    catch(const CorruptFile &err){
        std::cout << "Error: " << err.what(); 
    }
    catch(const std::exception &err){
        std::cout << "Error: " << err.what();
    }
    catch(...){
        std::terminate();
    }

    try{
        ConfigLoader::load("missing.cfg");
    }
        catch(const std::invalid_argument &err){
        std::cout << "Error: " << err.what();
    }
    catch(const std::runtime_error &err){
        std::cout << "Error: " << err.what();
    }
    catch(const CorruptFile &err){
        std::cout << "Error: " << err.what(); 
    }
    catch(const std::exception &err){
        std::cout << "Error: " << err.what();
    }
    catch(...){
        std::terminate();
    }

    try{
        ConfigLoader::load("invalid.cfg");
    }
    catch(const std::invalid_argument &err){
        std::cout << "Error: " << err.what();
    }
    catch(const std::runtime_error &err){
        std::cout << "Error: " << err.what();
    }
    catch(const CorruptFile &err){
        std::cout << "Error: " << err.what(); 
    }
    catch(const std::exception &err){
        std::cout << "Error: " << err.what();
    }
    catch(...){
        std::terminate();
    }

    return 0;
}