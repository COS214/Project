#include "MeatChef.h"

void MeatChef::prepareOrder(Command* order, Waiter* currWaiter) {
	std::cout << "Meat Chef is preparing & removing from Inventory. " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter);
}

void MeatChef::cook(std::string dish) {
        std::cout << "Meat chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}