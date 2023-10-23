#ifndef STATE_H
#define STATE_H

#include <string>
#include "Customer.h"

class Customer;

class State {
  public:
    virtual void handleChange(Customer* c) = 0;
    virtual std::string getState() = 0;
    virtual ~State();
};

#endif