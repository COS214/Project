#include "JuniorChef.h"

void JuniorChef::prepareOrder(Command* order, Waiter* currWaiter) {
	std::cout << "Junior Chef is preparing & removing from Inventory. "<< std::endl;

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter);
}

void JuniorChef::setInventory(Inventory* inventory)
{
    Chefs::inventory = inventory;
}

void JuniorChef::cook(std::string dish) {
        std::cout << "Junior chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}