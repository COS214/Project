/**
 * @file KitchenOrder.h
 * @brief Contains the declaration of the KitchenOrder class.
 */

#ifndef KITCHENORDER_H
#define KITCHENORDER_H

#include "Command.h"
#include "Kitchen.h"
#include "Order.h"
#include <iostream>

/**
 * @class KitchenOrder
 * @brief The KitchenOrder class represents a command to be executed in the kitchen.
 */
class KitchenOrder : public Command {

private:
	Kitchen* kitchen;
	std::string state = "Uncooked";

public:
	/**
     * @brief Constructor for the KitchenOrder class.
     * @param order A pointer to the Order representing the customer's order.
     */
	KitchenOrder(Order* order);

	/**
     * @brief Destructor for the KitchenOrder class.
     */
	~KitchenOrder();

	/**
     * @brief Execute the kitchen order.
     */
	void execute() override;

	/**
     * @brief Get the associated order.
     * @return A pointer to the Order representing the customer's order.
     */
	Order* getOrder() const;

	/**
     * @brief Get the current state of the kitchen order.
     * @return A string representing the current state of the kitchen order.
     */
	std::string getState();

	/**
     * @brief Set the state of the kitchen order.
     * @param str A string representing the new state of the kitchen order.
     */
	void setState(std::string str);
};

#endif