/**
 * @file SauceChef.h
 * @brief Contains the declaration of the SauceChef class.
 */

#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "Chefs.h"
#include "Command.h"
#include <iostream>

/**
 * @class SauceChef
 * @brief The SauceChef class represents a chef specialized in sauce-based dishes.
 */
class SauceChef : public Chefs {

public:
	/**
     * @brief Default constructor for the SauceChef class.
     */
	SauceChef();

	/**
     * @brief Constructor for the SauceChef class with a specified mediator.
     * @param mediator A pointer to the Mediator used for communication.
     */
  	SauceChef(Mediator* mediator) : Chefs(mediator) {}

	/**
     * @brief Cook a dish.
     * @param dish A string representing the dish to be cooked.
     */
	void cook(std::string dish) override;

	/**
     * @brief Prepare an order.
     * @param order A pointer to the Command representing the order.
     * @param currWaiter A pointer to the Waiter who placed the order.
     * @param cookStrategy An integer representing the cooking strategy.
     */
	void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) override;

	/**
     * @brief Destructor for the SauceChef class.
     */
	virtual ~SauceChef()=default;

	/**
     * @brief Check if an item is a sauce.
     * @param item A string representing the item to be checked.
     * @return True if the item is a sauce, otherwise false.
     */
	bool isSauce(string item);

};

#endif