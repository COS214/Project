/**
 * @file Seated.h
 * @brief Contains the declaration of the Seated class.
 */

#ifndef SEATED_H
#define SEATED_H

#include "State.h"

/**
 * @class Seated  
 * @brief The Seated class represents the state when a customer is seated at a table.
 */
class Seated : public State {
  public:
    /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state, which is "Seated".
     */
    virtual std::string getState();
};

#endif