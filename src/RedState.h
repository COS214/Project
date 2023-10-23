#ifndef REDSTATE_H
#define REDSTATE_H

#include "State.h"

class RedState : public State {
  public:
    virtual void handleChange(Context* c);
    virtual std::string getColor();
};

#endif