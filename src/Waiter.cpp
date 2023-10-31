#include "Waiter.h"

Waiter::Waiter(){
	
}

void Waiter::placeOrder(Chefs* Chefs, Command* order) {
	std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
    Chefs->prepareOrder(order);
}

void Waiter::update(string message) {
	// name can be the name given to the waiter object observing a specific customer 
	// can be changed to an id insteads
	cout << "Customer has changed state: " << message << endl;
}


