/**
 * @file KitchenOrder.cpp
 * @brief Contains the declaration of the KitchenOrder class.
 */

#include "KitchenOrder.h"
/**
 * @brief Constructor for the KitchenOrder class that takes an order as a parameter.
 *
 * @param order Pointer to the Order object.
 */
KitchenOrder::KitchenOrder(Order *order)
{
	this->order = order;
}
/**
 * @brief Destructor for the KitchenOrder class. Deletes the order and kitchen.
 */
KitchenOrder::~KitchenOrder()
{
	this->order = NULL;
	this->kitchen = NULL;
	delete this->order;
	delete this->kitchen;
}
void KitchenOrder::execute()
{
	this->kitchen->prepare(this->order);
}
/**
 * @brief This method returns the order of the KitchenOrder object.
 *
 * @return Pointer to the Order object of the KitchenOrder.
 */
Order *KitchenOrder::getOrder() const
{
	return this->order;
}
/**
 * @brief This method sets the state of the KitchenOrder object.
 *
 * @param str String representing the state to be set.
 */
void KitchenOrder::setState(std::string str)
{
	this->state = str;
}
/**
 * @brief This method returns the state of the KitchenOrder object.
 *
 * @return String representing the state of the KitchenOrder object.
 */
std::string KitchenOrder::getState()
{
	return this->state;
}