#include "Waiter.h"

void Waiter::placeOrder(Chefs* Chefs, Command* order) {
	std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
    Chefs->prepareOrder(order);
}

void Waiter::update() {
	// TODO - implement Waiter::update
	throw "Not yet implemented";
}
