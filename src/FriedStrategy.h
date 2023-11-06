/**
 * @file FriedStrategy.h
 * @brief Contains the declaration of the FriedStrategy class.
 */

#ifndef FRIEDSTRATEGY_H
#define FRIEDSTRATEGY_H

#include "CookStrategy.h"

/**
 * @class FriedStrategy
 * @brief The FriedStrategy class represents a cooking strategy for frying dishes.
 */
class FriedStrategy : public CookStrategy {

public:
	/**
     * @brief Constructor for the FriedStrategy class.
     * @param order The kitchen order associated with this cooking strategy.
     */
	FriedStrategy(KitchenOrder* order);

	/**
     * @brief Cook the dish using the frying method.
     * @param order The kitchen order to be cooked.
     */
	void cookDish(KitchenOrder* order);
};

#endif
