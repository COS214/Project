/**
 * @file Arrived.cpp
 * @brief Contains the implementation of the Arrived class.
 */

#include "Arrived.h"
#include "Waiting.h"
/**
 * @brief  Handles the state change of a customer.
 * @param  c The customer whose state is to be changed.
 */
void Arrived::handleChange(Customer *c)
{
    c->setState(new Waiting());
}
/**
 * @brief  Gets the state of the customer.
 * @return The state of the customer.
 */
std::string Arrived::getState()
{
    return "Arrived";
}