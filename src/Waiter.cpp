#include "Waiter.h"

void Waiter::placeOrder(Chefs* Chefs, Command* order) {
	std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
    Chefs->prepareOrder(order);
}

void Waiter::update(string message) {
	// name can be the name given to the waiter object observing a specific customer 
	// can be changed to an id instead
	cout << "Customer has changed state: " << message << endl;
}

Waiter::Waiter(std::list<Table*>& tables): tables(tables) {
    currentTable = tables.begin(); //sets to the start of the table
    currentCustomer = (*currentTable)->getCustomers().begin(); //sets to the beginning of the customers
}

Customer* Waiter::first() {
    currentTable = tables.begin(); //set to the first table
    currentCustomer = (*currentTable)->getCustomers().begin(); //first customer at the table
    if (!tables.empty() && !(*currentTable)->getCustomers().empty()) {
        return *currentCustomer; //return the first customer at the table...
    }
    return nullptr; // No customers to serve
}

Customer* Waiter::next() {
    if (!isDone()) {
        ++currentCustomer;
        if (currentCustomer == (*currentTable)->getCustomers().end()) {
            // Move to the next table
            ++currentTable;
            if (!isDone()) {
                currentCustomer = (*currentTable)->getCustomers().begin();
            }
        }
        if (!isDone()) {
            return *currentCustomer;
        }
    }
    return nullptr; // No more customers to serve
}

bool Waiter::isDone(){
    return currentTable == tables.end();
}

void Waiter::serveCustomers(Chefs* Chefs, Command* order) {
    	Customer* currentCustomer = first(); // Get the first customer to serve

        // Get the state of the customer
        if (currentCustomer->getState() == "Order")
        {
            //make a new Command object
            //Command* order = currentCustomer->getOrder();
            placeOrder(Chefs, order); // Forward the order to the kitchen using the placeOrder method.
            std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
        } else if (currentCustomer->getState() == "Pay")
        {
            //create a new bill

            //continue here
            Bill newBill = Bill(generateOrderID(),currentCustomer->getCustomerID,15,);
            
        } else if (currentCustomer->getState() == "Rate")
        {
            std::cout << "Customer: " << currentCustomer->getName() << "has arrived at the restaurant." << std::endl;
        }  else if (currentCustomer->getState() == "Leave")
        {
            std::cout << "Customer: " << currentCustomer->getName() << "is about to leave the restaurant." << std::endl;
        }
        
        currentCustomer = next();
}



