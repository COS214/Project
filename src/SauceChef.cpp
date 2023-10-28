#include "SauceChef.h"

void SauceChef::prepareOrder(Command* order) {
	std::cout << "Sauce Chef is preparing order: " << std::endl;
    order->execute();
    Chefs::prepareOrder(order);
}
