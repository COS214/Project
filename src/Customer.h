#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include "State.h"

class State;

class Customer {
public:
    Customer();
	~Customer();
	void change();
  	std::string getState();
	void setState(State* state);
  private: 
    State* state;
};

#endif