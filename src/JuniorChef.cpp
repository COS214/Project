#include "JuniorChef.h"

void JuniorChef::prepareOrder(Command* order) {
	std::cout << "Junior Chef is preparing order: "<< std::endl;
    order->execute();
    Chefs::prepareOrder(order);
}
