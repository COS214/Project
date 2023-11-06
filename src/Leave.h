/**
 * @file Leave.h
 * @brief Contains the declaration of the Leave class.
 */

#ifndef LEAVE_H
#define LEAVE_H

/**
 * @class Leave
 * @brief The Leave class represents the state when a customer is ready to leave the restaurant.
 */
#include "State.h"

class Leave : public State {
  public:
    /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state, which is "Leave".
     */
    virtual std::string getState();
};

#endif