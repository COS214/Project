#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>
#include <iostream>
#include "State.h"

class State;

class Context {
public:
    Context();
	~Context();
	void change();
  	std::string getColor();
	void setState(State* state);
  private: 
    State* state;
};

#endif