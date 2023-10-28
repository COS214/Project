#include "VegetableChef.h"

void VegetableChef::prepareOrder(Command* order) {
	std::cout << "Vegetable Chef is preparing order and removing from Inventory: " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    Chefs::prepareOrder(order);
}
