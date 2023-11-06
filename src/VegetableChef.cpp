/**
 * @file VegetableChef.cpp
 * @brief Contains the declaration of the VegetableChef class functions.
 */

#include "VegetableChef.h"

VegetableChef::VegetableChef()
{
    std::cout << "Vegetable Chef has arrived." << std::endl;
}
/**
 * @brief This method allows the VegetableChef to prepare an order and remove the necessary ingredients from the inventory.
 *
 * @param order Pointer to the Command object representing the customer's order.
 * @param currWaiter Pointer to the Waiter object who is currently serving.
 * @param cookStrategy Integer representing the cooking strategy to be used.
 */
void VegetableChef::prepareOrder(Command *order, Waiter *currWaiter, int cookStrategy)
{
    std::cout << "Vegetable Chef is preparing & removing from Inventory. " << std::endl;

    Dish *dish = order->order->getCustomer()->getDish();
    // cout<<"\n========================\n"<<endl;
    for (string ingredient : dish->getList())
    {
        // Check if the ingredient is vegetable-related
        if (isVegetable(ingredient))
        {
            // Call the removeFromInventory function to decrement the quantity
            // cout<<"Vegetable Chef is removing "<<ingredient<<" from inventory"<<endl;
            Chefs::inventory->removeFromInventory(ingredient, 1);
        }
    }

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter, cookStrategy);
}
/**
 * @brief This method allows the VegetableChef to cook a specific dish.
 *
 * @param dish String representing the name of the dish to be cooked.
 */
void VegetableChef::cook(std::string dish)
{
    std::cout << "Sauce chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}
/**
 * @brief This method checks if a given item is a vegetable.
 *
 * @param item String representing the name of the item to be checked.
 * @return true if the item is a vegetable, false otherwise.
 */
bool VegetableChef::isVegetable(string item)
{
    // Check if the ingredient is vegetable-related
    if (item == "LadyFingers" || item == "Vegetable Broth" || item == "Tomatoes" || item == "Beans" || item == "Spaghetti" || item == "Pancetta" || item == "Pizza Dough" || item == "Lasagna Sheets" || item == "Pasta" || item == "Onions")
    {
        return true;
    }
    return false;
}