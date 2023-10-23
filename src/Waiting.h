#ifndef WAITING_H
#define WAITING_H

#include "State.h"

class Waiting : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif