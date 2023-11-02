//Invoker
#ifndef WAITER_H
#define WAITER_H

#include "Observer.h"
#include "State.h"
#include "Chefs.h"
#include "Table.h"	
#include "Iterator.h"

class Waiter : public Observer, public Iterator {

private:
	string name;
	State* waiterState;
	State* customerState;

	//added for iterator pattern
	std::list<Table*>& tables; //reference to tables
    std::list<Table*>::iterator currentTable;
    std::list<Customer*>::iterator currentCustomer;
public:
	Waiter();
	void placeOrder(Chefs* Chefs, Command* order);
	void update(string message);

	//added for iterator pattern
	Waiter(std::list<Table*>& tables);
	Customer* first()	;
    Customer* next();
    bool isDone();
	void serveCustomers();
};

#endif
