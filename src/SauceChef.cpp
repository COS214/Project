/**
 * @file SauceChef.cpp
 * @brief Contains the declaration of the SauceChef class functions.
 */

#include "SauceChef.h"

SauceChef::SauceChef()
{
    std::cout << "Sauce Chef has arrived." << std::endl;
}
/**
 * @brief This method allows the SauceChef to prepare an order and remove the necessary ingredients from the inventory.
 *
 * @param order Pointer to the Command object representing the customer's order.
 * @param currWaiter Pointer to the Waiter object who is currently serving.
 * @param cookStrategy Integer representing the cooking strategy to be used.
 */
void SauceChef::prepareOrder(Command *order, Waiter *currWaiter, int cookStrategy)
{
    std::cout << "Sauce Chef is preparing & removing from Inventory. " << std::endl;

    Dish *dish = order->order->getCustomer()->getDish();
    for (const std::string &ingredient : dish->getList())
    {
        // Check if the ingredient is vegetable-related
        if (isSauce(ingredient))
        {
            // Call the removeFromInventory function to decrement the quantity
            // cout<<"Sauce Chef is removing "<<ingredient<<" from inventory"<<endl;
            Chefs::inventory->removeFromInventory(ingredient, 1);
        }
    }

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter, cookStrategy);
}
/**
 * @brief This method checks if a given item is a sauce.
 *
 * @param item String representing the name of the item to be checked.
 * @return true if the item is a sauce, false otherwise.
 */
bool SauceChef::isSauce(string item)
{
    // Check if the ingredient is sauce-related
    if (item == "Tomato Sauce" || item == "Bolognese Sauce " || item == "Black Pepper" || item == "Fresh Basil" || item == "Espresso" || item == "Cocoa Powder")
    {
        return true;
    }
}
/**
 * @brief This method allows the SauceChef to cook a specific dish.
 *
 * @param dish String representing the name of the dish to be cooked.
 *
 */
void SauceChef::cook(std::string dish)
{
    std::cout << "Sauce chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}