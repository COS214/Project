#ifndef AMBERSTATE_H
#define AMBERSTATE_H

#include "State.h"

class AmberState : public State {
  public:
    virtual void handleChange(Context* c);
    virtual std::string getColor();
};

#endif