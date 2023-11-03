#ifndef LEAVE_H
#define LEAVE_H

#include "State.h"

class Leave : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif