#include "MeatChef.h"

void MeatChef::prepareOrder(Command* order) {
	std::cout << "Meat Chef is preparing order and removing from Inventory: " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    Chefs::prepareOrder(order);
}
