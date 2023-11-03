#include "MeatChef.h"

void MeatChef::prepareOrder(Command* order) {
	std::cout << "Meat Chef is preparing order and removing from Inventory: " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order);
}

void MeatChef::cook(std::string dish) {
        std::cout << "Meat chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}