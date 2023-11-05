/**
 * @file GrilledStrategy.cpp
 * @brief Contains the declaration of the GrilledStrategy class functions.
 */

#include "GrilledStrategy.h"
/**
 * @brief Constructor for the GrilledStrategy class that takes an order as a parameter.
 *
 * @param order Pointer to the KitchenOrder object.
 */
GrilledStrategy::GrilledStrategy(KitchenOrder *order)
{
	order->setState("Cooking");
}
/**
 * @brief This method allows the GrilledStrategy to cook a dish.
 *
 * @param order Pointer to the KitchenOrder object representing the dish to be cooked.
 */
void GrilledStrategy::cookDish(KitchenOrder *order)
{
	order->setState("Grilled");
	std::cout << "Meat is being grilled" << std::endl;
}
