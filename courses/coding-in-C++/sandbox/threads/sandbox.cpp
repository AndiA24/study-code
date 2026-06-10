#include <iostream>
#include <thread>
#include <semaphore>

constexpr int ITTERATIONS = 1000000;

int counter = 0;

std::binary_semaphore door(1);


void count(int itt){
    for(int i = 0; i < itt; i++){
        door.acquire();
        counter ++;
        door.release();
    }
}

int main(){


    std::thread t1{count, ITTERATIONS};
    std::thread t2{count, ITTERATIONS};
    std::thread t3{count, 500000};

    t1.join();
    t2.join();
    t3.join();

    std::cout << counter << std::endl;

    return 0;
}