/**
 * @file Order.cpp
 * @brief Contains the declaration of the Order class functions.
 */

#include "Order.h"
#include "Rate.h"
/**
 * @brief This method changes the state of the customer to "Rate".
 *
 * @param c Pointer to the Customer object whose state is to be changed.
 */
void Order::handleChange(Customer *c)
{
    c->setState(new Rate());
}
/**
 * @brief This method returns the state of the Order object.
 *
 * @return String representing the state of the Order object.
 */
std::string Order::getState()
{
    return "Order";
}
/**
 * @brief This method sets the customer for the Order object.
 *
 * @param c Pointer to the Customer object to be set.
 */
void Order::setCustomer(Customer *c)
{
    this->customer = c;
}
/**
 * @brief This method returns the customer of the Order object.
 *
 * @return Pointer to the Customer object of the Order.
 */
Customer *Order::getCustomer()
{
    return this->customer;
}