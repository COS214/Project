#ifndef PAY_H
#define PAY_H

#include "State.h"

class Pay : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif