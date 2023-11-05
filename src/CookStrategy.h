/**
 * @file CookStrategy.h
 * @brief Contains the declaration of the CookStrategy class.
 */

#ifndef COOKSTRATEGY_H
#define COOKSTRATEGY_H

#include "KitchenOrder.h"

/**
 * @class CookStrategy
 * @brief The CookStrategy class represents a strategy for cooking a dish.
 */
class CookStrategy {

public:
	/**
	 * @brief Cook a dish based on the strategy.
	 * @param order The kitchen order to cook.
	 */
	virtual void cookDish(KitchenOrder* order) = 0;
};

#endif
