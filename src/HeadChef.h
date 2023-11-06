/**
 * @file HeadChef.h
 * @brief Contains the declaration of the HeadChef class.
 */

#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chefs.h"
#include "Command.h"
#include "Waiter.h"

/**
 * @class HeadChef
 * @brief The HeadChef class represents the main chef responsible for preparing dishes.
 */
class HeadChef : public Chefs {

public:
	/**
     * @brief Default constructor for the HeadChef class.
     */
	HeadChef();

	/**
     * @brief Constructor for the HeadChef class with a mediator.
     * @param mediator The mediator used for communication with other components.
     */
	HeadChef(Mediator* mediator) : Chefs(mediator) {}

	/**
     * @brief Cook a specified dish.
     * @param dish The name of the dish to be cooked.
     */
	void cook(std::string dish);

	/**
     * @brief Prepare an order and send it to the kitchen.
     * @param order The order to be prepared.
     * @param currWaiter The current waiter handling the order.
     * @param cookStrategy The strategy for cooking the order.
     */
	void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy ) override;

	/**
     * @brief Destructor for the HeadChef class.
     */
	virtual ~HeadChef()=default;

};

#endif