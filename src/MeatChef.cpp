#include "MeatChef.h"

void MeatChef::prepareOrder(Command* order) {
	std::cout << "Meat Chef is preparing order: " << std::endl;
    order->execute();
    Chefs::prepareOrder(order);
}
