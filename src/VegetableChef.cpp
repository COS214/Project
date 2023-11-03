#include "VegetableChef.h"

void VegetableChef::prepareOrder(Command* order, Waiter* currWaiter) {
	std::cout << "Vegetable Chef is preparing order and removing from Inventory: " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter);
}

void VegetableChef::cook(std::string dish) {
        std::cout << "Sauce chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}