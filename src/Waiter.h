#ifndef WAITER_H
#define WAITER_H

#include "Observer.h"
#include "State.h"
#include "Chefs.h"

class Waiter : Observer {

private:
	State* waiterState;
	State* customerState;

public:
	void placeOrder(Chefs Chefs, Command order);

	void update();
};

#endif
