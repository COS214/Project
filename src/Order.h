/**
 * @file Order.h
 * @brief Contains the declaration of the Order class.
 */

#ifndef ORDER_H
#define ORDER_H

#include "State.h"
#include "Customer.h"

/**
 * @class Order
 * @brief The Order class represents the state when a customer is ready to place an order.
 */
class Order : public State {
  private:
    Customer* customer;

  public:
  /**
     * @brief Handle a state change for a customer.
     * @param c A pointer to the Customer whose state is being changed.
     */
    virtual void handleChange(Customer* c);

    /**
     * @brief Get the current state as a string.
     * @return A string representing the current state, which is "Order".
     */
    virtual std::string getState();

    /**
     * @brief Set the customer associated with the order state.
     * @param c A pointer to the Customer who is ready to place an order.
     */
    void setCustomer(Customer* c);

    /**
     * @brief Get the customer associated with the order state.
     * @return A pointer to the Customer who is ready to place an order.
     */
    Customer* getCustomer();
    
};

#endif