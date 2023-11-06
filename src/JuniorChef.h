/**
 * @file JuniorChef.h
 * @brief Contains the declaration of the JuniorChef class.
 */

#ifndef JUNIORCHEF_H
#define JUNIORCHEF_H

#include "Chefs.h"
#include "Command.h"

/**
 * @class JuniorChef
 * @brief The JuniorChef class represents a junior chef responsible for preparing dishes.
 */
class JuniorChef : public Chefs {

public:
	/**
     * @brief Default constructor for the JuniorChef class.
     */
	JuniorChef();

	/**
     * @brief Constructor for the JuniorChef class with a mediator.
     * @param mediator A pointer to the Mediator used for communication with other components.
     */
	JuniorChef(Mediator* mediator) : Chefs(mediator) {}

	/**
     * @brief Prepare and cook a dish.
     * @param dish A string representing the dish to be cooked.
     */
	void cook(std::string dish) override;

	/**
     * @brief Prepare an order based on a given command and waiter.
     * @param order A pointer to the Command representing the order to be prepared.
     * @param currWaiter A pointer to the Waiter who submitted the order.
     * @param cookStrategy An integer representing the cook strategy for the dish.
     */
	void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) override;

	/**
     * @brief Destructor for the JuniorChef class.
     */
	virtual ~JuniorChef()=default;

	/**
     * @brief Set the inventory for the junior chef.
     * @param inventory A pointer to the Inventory to be associated with the chef.
     */
	void setInventory(Inventory* inventory);

};

#endif