#ifndef ARRIVED_H
#define ARRIVED_H

#include "State.h"

class Arrived : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif