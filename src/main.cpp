#include <iostream>
#include "Context.h"

void StateTest(){
    std::cout << "<=============================== State Unit Testing ===============================>" << std::endl;

    Context* context = new Context();
    for (int i = 0; i < 10; i++) {
        std::string currentTLcolour = context->getColor();
        std::cout << "Traffic light is currently: " << currentTLcolour << std::endl;
        context->change();
    }
    delete context;
}

int main(){

    StateTest();
    return 0;
}