/**
 * @file Kitchen.h
 * @brief Contains the declaration of the Kitchen class.
 */

#ifndef KITCHEN_H
#define KITCHEN_H

#include "Order.h"

/**
 * @class Kitchen
 * @brief The Kitchen class represents a kitchen where orders are prepared.
 */
class Kitchen {
	public:
		/**
		 * @brief Prepare an order in the kitchen.
		 * @param order A pointer to the Order representing the customer's order to be prepared.
		 */
		void prepare(Order* order);
};

#endif
