#include "HeadChef.h"

void HeadChef::prepareOrder(Command* order) {
	std::cout << "Head Chef is preparing order and removing from Inventory: " << std::endl;
    order->execute();
    // After the head chef prepares the order, send it to the waiter
    std::cout << "Order prepared by Head Chef. Sending it to the waiter." << std::endl;
}
