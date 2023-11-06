/**
 * @file Arrived.h
 * @brief Contains the declaration of the Arrived class.
 */

#ifndef ARRIVED_H
#define ARRIVED_H

#include "State.h"

/**
 * @class Arrived
 * @brief The Arrived class represents the state when a customer just arrived.
 */
class Arrived : public State {
  public:
    /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state, which is "Arrived".
     */    
    virtual std::string getState();
};

#endif