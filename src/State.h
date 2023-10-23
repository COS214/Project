#ifndef STATE_H
#define STATE_H

#include <string>
#include "Context.h"

class Context;

class State {
  public:
    virtual void handleChange(Context* c) = 0;
    virtual std::string getColor() = 0;
    virtual ~State();
};

#endif