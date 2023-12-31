/**
 * @file MeatChef.cpp
 * @brief Contains the declaration of the MeatChef class functions.
 */

#include "MeatChef.h"

MeatChef::MeatChef()
{
    std::cout << "Meat Chef has arrived." << std::endl;
}
/**
 * @brief This method allows the MeatChef to prepare an order and remove the necessary ingredients from the inventory.
 *
 * @param order Pointer to the Command object representing the customer's order.
 * @param currWaiter Pointer to the Waiter object who is currently serving.
 * @param cookStrategy Integer representing the cooking strategy to be used.
 */
void MeatChef::prepareOrder(Command *order, Waiter *currWaiter, int cookStrategy)
{
    std::cout << "Meat Chef is preparing & removing from Inventory. " << std::endl;

    if (cookStrategy == 1)
    {
        std::cout << "\t\t\tSELECTED STRATEGY FOR COOKING MEAT : MEAT CHEF IS GRILLING THE MEAT" << std::endl;
    }

    else
    {
        std::cout << "\t\t\tSELECTED STRATEGY FOR COOKING MEAT : MEAT CHEF IS FRYING THE MEAT " << std::endl;
    }

    Dish *dish = order->order->getCustomer()->getDish();
    for (const std::string &ingredient : dish->getList())
    {
        // Check if the ingredient is vegetable-related
        if (isMeat(ingredient))
        {
            // Call the removeFromInventory function to decrement the quantity
            // cout<<"Meat Chef is removing "<<ingredient<<" from inventory"<<endl;
            Chefs::inventory->removeFromInventory(ingredient, 1);
        }
    }

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter, cookStrategy);
}
/**
 * @brief This method checks if a given item is a meat.
 *
 * @param item String representing the name of the item to be checked.
 * @return true if the item is a meat, false otherwise.
 */
bool MeatChef::isMeat(string item)
{
    // Check if the ingredient is meat-related
    if (item == "Parmesan Cheese" || item == "Mozzarella Cheese" || item == "Mascarpone Cheese" || item == "Chicken" || item == "Beef" || item == "Pork" || item == "Lamb" || item == "Turkey")
    {
        return true;
    }
    return false;
}
/**
 * @brief This method allows the MeatChef to cook a specific dish.
 *
 * @param dish String representing the name of the dish to be cooked.
 */
void MeatChef::cook(std::string dish)
{
    std::cout << "Meat chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}