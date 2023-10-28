#include "SauceChef.h"

void SauceChef::prepareOrder(Command* order) {
	std::cout << "Sauce Chef is preparing order and removing from Inventory: " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    Chefs::prepareOrder(order);
}
