/**
 * @file GrilledStrategy.h
 * @brief Contains the declaration of the GrilledStrategy class.
 */

#ifndef GRILLEDSTRATEGY_H
#define GRILLEDSTRATEGY_H

#include "CookStrategy.h"

/**
 * @class GrilledStrategy
 * @brief The GrilledStrategy class represents a cooking strategy for grilling dishes.
 */
class GrilledStrategy : public CookStrategy {

public:
	/**
     * @brief Constructor for the GrilledStrategy class.
     * @param order The kitchen order associated with this cooking strategy.
     */
	GrilledStrategy(KitchenOrder* order);

	/**
     * @brief Cook the dish using the grilling method.
     * @param order The kitchen order to be cooked.
     */
	void cookDish(KitchenOrder* order);
};

#endif
