/**
 * @file Pay.h
 * @brief Contains the declaration of the Pay class.
 */

#ifndef PAY_H
#define PAY_H

#include "State.h"

/**
 * @class Pay
 * @brief The Pay class represents the state when a customer is ready to pay the bill.
 */
class Pay : public State {
  public:
    /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state, which is "Pay".
     */
    virtual std::string getState();
};

#endif