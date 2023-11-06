/**
 * @file Chefs.cpp
 * @brief Contains the implementation of the Chefs class.
 */

#include "Chefs.h"

Inventory *Chefs::inventory = nullptr;

Chefs::Chefs()
{
        this->nextHandler = nullptr;
}
/**
 * @brief This method allows the Chefs to prepare an order.
 *
 * @param order Pointer to the Command object representing the customer's order.
 * @param currWaiter Pointer to the Waiter object who is currently serving.
 * @param cookStrategy Integer representing the cooking strategy to be used.
 */
void Chefs::prepareOrder(Command *order, Waiter *currWaiter, int cookStrategy)
{
        if (nextHandler)
        {
                nextHandler->prepareOrder(order, currWaiter, cookStrategy);
        }
}
/**
 * @brief This method sets the next handler for the Chefs object.
 *
 * @param next Pointer to the Chefs object to be set as the next handler.
 */
void Chefs::setNext(Chefs *next)
{
        this->nextHandler = next;
}
/**
 * @brief This method allows the Chefs to cook a specific dish.
 *
 * @param dish String representing the name of the dish to be cooked.
 */
/**
 * @brief This method sets the mediator for the Chefs object.
 *
 * @param mediator Pointer to the Mediator object to be set.
 */
void Chefs::setMediator(Mediator *mediator)
{
        this->mediator = mediator;
}