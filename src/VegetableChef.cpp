#include "VegetableChef.h"

void VegetableChef::prepareOrder(Command* order) {
	std::cout << "Vegetable Chef is preparing order: " << std::endl;
    order->execute();
    Chefs::prepareOrder(order);
}
