#ifndef GREENSTATE_H
#define GREENSTATE_H

#include "State.h"

class GreenState : public State {
  public:
    virtual void handleChange(Context* c);
    virtual std::string getColor();
};

#endif