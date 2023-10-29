#include "SauceChef.h"

void SauceChef::prepareOrder(Command* order) {
	std::cout << "Sauce Chef is preparing order and removing from Inventory: " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    Chefs::prepareOrder(order);
}

void SauceChef::cook(std::string dish){
        std::cout << "Sauce chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}
