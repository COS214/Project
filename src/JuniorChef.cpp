/**
 * @file JuniorChef.cpp
 * @brief Contains the declaration of the JuniorChef class functions.
 */

#include "JuniorChef.h"

JuniorChef::JuniorChef()
{
    std::cout << "Junior Chef has arrived." << std::endl;
}
/**
 * @brief This method allows the JuniorChef to prepare an order.
 *
 * @param order Pointer to the Command object representing the customer's order.
 * @param currWaiter Pointer to the Waiter object who is currently serving.
 * @param cookStrategy Integer representing the cooking strategy to be used.
 */
void JuniorChef::prepareOrder(Command *order, Waiter *currWaiter, int cookStrategy)
{
    std::cout << "Junior Chef is preparing & removing from Inventory.------------------- \033[0m " << std::endl;

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter, cookStrategy);
}
/**
 * @brief This method sets the inventory for the JuniorChef.
 *
 * @param inventory Pointer to the Inventory object to be set.
 */
void JuniorChef::setInventory(Inventory *inventory)
{
    Chefs::inventory = inventory;
}
/**
 * @brief This method allows the JuniorChef to cook a specific dish.
 *
 * @param dish String representing the name of the dish to be cooked.
 */
void JuniorChef::cook(std::string dish)
{
    std::cout << "Junior chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}