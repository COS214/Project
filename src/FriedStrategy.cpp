/**
 * @file FriedStrategy.cpp
 * @brief Contains the declaration of the FriedStrategy class functions.
 */

#include "FriedStrategy.h"
/**
 * @brief Constructor for the FriedStrategy class that takes an order as a parameter.
 *
 * @param order Pointer to the KitchenOrder object.
 */
FriedStrategy::FriedStrategy(KitchenOrder *order)
{
	order->setState("Cooking");
}
/**
 * @brief This method allows the FriedStrategy to cook a dish.
 *
 * @param order Pointer to the KitchenOrder object representing the dish to be cooked.
 */
void FriedStrategy::cookDish(KitchenOrder *order)
{
	order->setState("Fried");
	std::cout << "Meat is being fried" << std::endl;
}
