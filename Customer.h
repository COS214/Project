#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "State.h"
#include "Subject.h"

class State;

class Customer : public Subject {
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