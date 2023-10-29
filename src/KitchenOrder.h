#ifndef KITCHENORDER_H
#define KITCHENORDER_H

#include "Command.h"
#include "Kitchen.h"
#include "Order.h"

class KitchenOrder : public Command {

private:
	Kitchen* kitchen;
	Order* order;

public:
	KitchenOrder(Order* order);
	~KitchenOrder();
	void execute() override;
	Order* getOrder() const;
};

#endif
