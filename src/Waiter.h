// Invoker
#ifndef WAITER_H
#define WAITER_H

#include "Observer.h"
#include "State.h"
#include "Chefs.h"
#include "Table.h"
#include "Iterator.h"
#include "Bill.h"
#include "Tab.h"

class Waiter : public Observer, public Iterator
{

private:
	string name;
	State *waiterState;
	State *customerState;

	// added for iterator pattern
	std::list<Table *> tables; // reference to tables
	std::list<Table *>::iterator currentTable;
	std::list<Customer *>::iterator currentCustomer;

public:
	Waiter();
	void placeOrder(Chefs *Chefs, Command *order, int cookStrategy);
	void update(string message);

	// added for iterator pattern
	void receiveOrder(Command *order);
	Waiter(std::list<Table *> tables);
	Customer *first();
	Customer *next();
	bool isDone();
	void serveCustomers(Chefs *Chefs, Command *order);

	~Waiter(); // Destructor
};

#endif
