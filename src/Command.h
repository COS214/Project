/**
 * @file Command.h
 * @brief Contains the declaration of the Command class.
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "Order.h"

/**
 * @class Command
 * @brief The Command class represents a command for executing an order.
 */
class Command {
	private:
	public:
		Order* order;
		virtual ~Command()=default;
		/**
		 * @brief Execute the command to process the associated order.
		 */
		virtual void execute()=0;
};

#endif
