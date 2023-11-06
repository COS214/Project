/**
 * @file BasicDish.h
 * @brief Contains the declaration of the BasicDish class.
 */

#ifndef BASICDISH_H
#define BASICDISH_H

#include <iostream>
#include "Dish.h"


/**
 * @class BasicDish
 * @brief The BasicDish class represents a basic dish in a restaurant's menu.
 */
class BasicDish : public Dish {
	public:
		/**
    	 * @brief Constructs a BasicDish instance.
    	 */
        BasicDish();

		/**
		 * @brief Calculates the total cost of the dish.
		 * @return The total cost of the dish.
		*/
		double totalCost();
     
};

#endif
