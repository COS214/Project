#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "State.h"
#include <ctime>
#include <cstdlib>
#include "Subject.h"
#include "Bill.h" //added to use through waiter


class State;

class Customer : public Subject
{
private:
	std::string name;
	std::string customerID;
	int rating;
	int tableNumber; 
	double totalAmount;
public:
	Customer();
	Customer(std::string name);
	~Customer();
	void change();
  std::string getState();
	void setState(State *state);
	//added for waiter functionality
	std::string getOrder();
	std::string getName();
	std::string getCustomerID();
	int getRating();
	int getTableNumber();
	std::string GenerateCustomerID();
	void setCustomerID(std::string CID);
	double getTotalAmount(); 
private: 
    State* state;
	std::string CustomerID;	
	//added for waiter functionality
	std::string order;
};

#endif