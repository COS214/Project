#ifndef RATE_H
#define RATE_H

#include "State.h"

class Rate : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif