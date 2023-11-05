#ifndef ORDER_H
#define ORDER_H

#include "State.h"
#include "Customer.h"

class Order : public State {
  private:
    Customer* customer;
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
    void setCustomer(Customer* c);
    Customer* getCustomer();
    
};

#endif