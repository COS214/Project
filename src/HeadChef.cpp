/**
 * @file HeadChef.cpp
 * @brief Contains the declaration of the HeadChef class functions.
 */

#include "HeadChef.h"
/**
 * @brief Default constructor for the HeadChef class.
 */
HeadChef::HeadChef()
{
    std::cout << "Head Chef has arrived." << std::endl;
}
/**
 * @brief This method allows the HeadChef to cook a specific dish.
 *
 * @param dish String representing the name of the dish to be cooked.
 */
void HeadChef::cook(std::string dish)
{
    std::cout << "Head chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}
/**
 * @brief This method allows the HeadChef to prepare an order and send it to the waiter.
 *
 * @param order Pointer to the Command object representing the customer's order.
 * @param currWaiter Pointer to the Waiter object who is currently serving.
 * @param cookStrategy Integer representing the cooking strategy to be used.
 */
void HeadChef::prepareOrder(Command *order, Waiter *currWaiter, int cookStrategy)
{
    std::cout << "Head Chef is preparing & removing from Inventory. " << std::endl;
    order->execute();
    // After the head chef prepares the order, send it to the waiter
    this->mediator->notify(this, "cook");

    std::cout << "Order prepared by Head Chef. Sending it to the waiter.\033[0m" << std::endl;
    currWaiter->receiveOrder(order);
}
