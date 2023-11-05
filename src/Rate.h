/**
 * @file Rate.h
 * @brief Contains the declaration of the Rate class.
 */

#ifndef RATE_H
#define RATE_H

#include "State.h"

/**
 * @class Rate
 * @brief The Rate class represents the state when a customer is ready to rate their dining experience.
 */
class Rate : public State {
  public:
    /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state, which is "Rate".
     */
    virtual std::string getState();
};

#endif