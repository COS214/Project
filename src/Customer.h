#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "State.h"
#include <ctime>
#include <cstdlib>
#include "Subject.h"


class State;

class Customer : public Subject {
public:
    Customer();
	~Customer();
	void change();
  	std::string getState();
	void setState(State* state);
	std::string GenerateCustomerID();
	void setCustomerID(std::string CID);
	std::string getCustomerID();
  private: 
    State* state;
	std::string CustomerID;	
};

#endif