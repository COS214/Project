#include "HeadChef.h"

HeadChef::HeadChef(){
    std::cout << "Head Chef has arrived." << std::endl;
}

void HeadChef::cook(std::string dish) {
    std::cout << "Head chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}

void HeadChef::prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) {
    std::cout << "Head Chef is preparing & removing from Inventory. " << std::endl;
    order->execute();
    // After the head chef prepares the order, send it to the waiter
    this->mediator->notify(this, "cook");

    std::cout << "Order prepared by Head Chef. Sending it to the waiter." << std::endl;
    currWaiter->receiveOrder(order);

    
}

