#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>

std::binary_semaphore door(1);

int counter = 0;

std::vector<int> buffer;

void addItem(){
    door.acquire();
    buffer.emplace_back(counter);
    std::cout << "Add Item: " << counter << " to Buffer." << std::endl;
    counter++;
    door.release();
}

void getItem(){
    door.acquire();
    std::cout << "Remove Item: " << buffer.back() << " from Buffer." << std::endl;
    buffer.pop_back();
    door.release();
}

void producer(){
    while(1){
        addItem();
    }
}

void consumer(){
    while(1){
        getItem();
    }
}

int main(){

    std::thread p1{producer};
    std::thread c1{consumer};
    std::thread c2{consumer};

    p1.join();
    c1.join();
    c2.join();


    return 0;
}