#include "JuniorChef.h"

void JuniorChef::prepareOrder(Command* order) {
	std::cout << "Junior Chef is preparing order and removing from Inventory: "<< std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    Chefs::prepareOrder(order);
}

void JuniorChef::cook(std::string dish) {
        std::cout << "Junior chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}