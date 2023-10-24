#ifndef KITCHENORDER_H
#define KITCHENORDER_H

#include "Command.h"

class KitchenOrder : Command {

private:
	int Kitchen;
	int Order;

public:
	void execute();
};

#endif
