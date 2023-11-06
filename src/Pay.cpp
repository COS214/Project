/**
 * @file Pay.cpp
 * @brief Contains the declaration of the Pay class functions.
 */

#include "Pay.h"
#include "Leave.h"
/**
 * @brief This method changes the state of the customer to "Leave".
 *
 * @param c Pointer to the Customer object whose state is to be changed.
 */
void Pay::handleChange(Customer *c)
{
    c->setState(new Leave());
}
/**
 * @brief This method returns the state of the Pay object.
 *
 * @return String representing the state of the Pay object.
 */
std::string Pay::getState()
{
    return "Pay";
}