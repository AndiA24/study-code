#include "inspection.hpp"
#include "product.hpp"

int main(){

    Product *products[4];
    products[0] = new CombustionEngine(0, "Porsche1", 350, 80, false);
    products[1] = new CombustionEngine(1, "Porsche1", 370, 90, false);
    products[2] = new ElectricEngine(2, "Tesla", 200, 60, 800, true);
    products[3] = new ElectricEngine(3, "Tesla", 200, 60, 800, true);



    return -1;
}