#ifndef KITCHENORDER_H
#define KITCHENORDER_H

#include "Command.h"
#include "Kitchen.h"
#include "Order.h"
#include <iostream>

class KitchenOrder : public Command {

private:
	Kitchen* kitchen;
	
	std::string state = "Uncooked";

public:
	KitchenOrder(Order* order);
	~KitchenOrder();
	void execute() override;
	Order* getOrder() const;
	std::string getState();
	void setState(std::string str);
};

#endif
