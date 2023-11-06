/**
 * @file Mediator.h
 * @brief Contains the declaration of the Mediator class.
 */

#ifndef WAITING_H
#define WAITING_H

#include "State.h"

/**
 * @class Waiting
 * @brief The Waiting class represents a specific state of a Customer.
 */

class Waiting : public State {
  public:
    /**
     * @brief Handle a state change for a Customer.
     * @param c Pointer to the Customer whose state is changing.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the name of the current state.
     * @return A string representing the name of the state.
     */
    virtual std::string getState();
};

#endif