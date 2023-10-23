#include <iostream>
#include "Customer.h"

void StateTest(){
    std::cout << "<=============================== State Unit Testing ===============================>" << std::endl;

    Customer* customer = new Customer();
    for (int i = 0; i < 10; i++) {
        std::string currentTLcolour = customer->getState();
        std::cout << "Customer is currently: " << currentTLcolour << std::endl;
        customer->change();
    }
    delete customer;
}

int main(){

    StateTest();
    return 0;
}