/**
 * @file VegetableChef.h
 * @brief Contains the declaration of the VegetableChef class.
 */

#ifndef VEGETABLECHEF_H
#define VEGETABLECHEF_H

#include "Chefs.h"
#include "Command.h"

/**
 * @class VegetableChef
 * @brief The VegetableChef class represents a chef specialized in vegetable dishes.
 */
class VegetableChef : public Chefs {

public:
	/**
     * @brief Default constructor for the VegetableChef class.
     */
	VegetableChef();

	/**
     * @brief Constructor for the VegetableChef class with a specified mediator.
     * @param mediator A pointer to the Mediator used for communication.
     */
	VegetableChef(Mediator* mediator) : Chefs(mediator) {}

	/**
     * @brief Cook a dish.
     * @param dish A string representing the dish to be cooked.
     */
	void cook(std::string dish);

	/**
     * @brief Prepare an order.
     * @param order A pointer to the Command representing the order.
     * @param currWaiter A pointer to the Waiter who placed the order.
     * @param cookStrategy An integer representing the cooking strategy.
     */
	void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) override;

	/**
     * @brief Destructor for the VegetableChef class.
     */
	virtual ~VegetableChef()=default;

	/**
     * @brief Check if an item is a vegetable.
     * @param item A string representing the item to be checked.
     * @return True if the item is a vegetable, otherwise false.
     */
	bool isVegetable(string item);
};

#endif