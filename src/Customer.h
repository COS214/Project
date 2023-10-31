#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "State.h"
#include "Subject.h"

class State;

class Customer : public Subject
{
private:
	std::string name;

public:
	Customer();
	Customer(std::string name);
	~Customer();
	void change();
	std::string getState();
	void setState(State *state);

private:
	State *state;
};

#endif