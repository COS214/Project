#ifndef SEATED_H
#define SEATED_H

#include "State.h"

class Seated : public State {
  public:
    virtual void handleChange(Customer* c);
    virtual std::string getState();
};

#endif