#include <string>

class Inspection{
    private:

    public:
        virtual void createReport() = 0;



};

class WeightInspection : public Inspection{
    private:
        std::string name;
        
        

};

class VisualInspection : public Inspection{

};

class TemperatureInspection : public Inspection{

};