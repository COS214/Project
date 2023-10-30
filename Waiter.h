//Invoker
#ifndef WAITER_H
#define WAITER_H

#include "Observer.h"
#include "State.h"
#include "Chefs.h"

class Waiter : public Observer {

private:
	string name;
	State* waiterState;
	State* customerState;

public:
	Waiter();
	void placeOrder(Chefs* Chefs, Command* order);
	void update(string message);
};

#endif
