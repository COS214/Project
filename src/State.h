/**
 * @file State.h
 * @brief Contains the declaration of the State class.
 */

#ifndef STATE_H
#define STATE_H

#include <string>
#include "Customer.h"

class Customer;

/**
 * @class State
 * @brief The State class represents the base class for customer states in a restaurant.
 */
class State {
  public:
  /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c) = 0;

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state.
     */
    virtual std::string getState() = 0;

    /**
     * @brief Destructor for the State class.
     */
    virtual ~State();
};

#endif