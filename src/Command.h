#ifndef COMMAND_H
#define COMMAND_H

#include "Order.h"

class Command {
	private:
	public:
		Order* order;
		virtual void execute()=0;
};

#endif
