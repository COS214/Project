#ifndef ORDER_H
#define ORDER_H

#include "State.h"

class Order : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif