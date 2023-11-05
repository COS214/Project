/**
 * @file MeatChef.h
 * @brief Contains the declaration of the MeatChef class.
 */

#ifndef MEATCHEF_H
#define MEATCHEF_H

#include "Chefs.h"
#include "Command.h"
#include "CookStrategy.h"

/**
 * @class MeatChef
 * @brief The MeatChef class represents a chef specializing in meat dishes.
 */
class MeatChef : public Chefs {

public:
	/**
     * @brief Default constructor for the MeatChef class.
     */
	MeatChef();

	CookStrategy* cookStrategy;

	/**
     * @brief Constructor for the MeatChef class with a mediator.
     * @param mediator A pointer to the Mediator for communication.
     */
	MeatChef(Mediator* mediator) : Chefs(mediator) {}

	/**
     * @brief Cook a dish.
     * @param dish A string representing the meat dish to be cooked.
     */
	void cook(std::string dish);

	/**
     * @brief Prepare an order for cooking.
     * @param order A pointer to the Command representing the order.
     * @param currWaiter A pointer to the Waiter taking the order.
     * @param cookStrategy An integer specifying the cook strategy for the dish.
     */
	void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) override;

	/**
	 * @brief Default destructor for the MeatChef class.
	 */
	virtual ~MeatChef()=default;

	/**
     * @brief Check if an item is a meat dish.
     * @param item A string representing the item to be checked.
     * @return A boolean indicating whether the item is a meat dish.
     */
	bool isMeat(string item);

};

#endif
