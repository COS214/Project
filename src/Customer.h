/**
 * @file Customer.h
 * @brief Contains the declaration of the Customer class.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "State.h"
#include <ctime>
#include <cstdlib>
#include "Subject.h"
#include "Dish.h"
#include "Bill.h" //added to use through waiter

class State;

/**
 * @class Customer
 * @brief The Customer class is a concrete subject in the observer pattern.
 */
class Customer : public Subject
{
private:
	std::string name;
	std::string customerID;
	int rating;
	int tableNumber;
	double totalAmount;
	Dish *orderedDish;

public:
	/**
 	 * @brief Default constructor for the Customer class.
 	 */
	Customer();

	/**
 	 * @brief Constructor for the Customer class that takes a name and id as parameters.
 	 * @param name String representing the name of the customer.
 	 * @param id Integer representing the id of the customer.
 	 */
	Customer(std::string name, int id);

	/**
 	 * @brief Destructor for the Customer class.
 	 */
	virtual ~Customer();

	void change();

	/**
	 * @brief This method returns the current state
	 * @return String representing the current state
	*/
	std::string getState();

	/**
 	 * @brief This method sets the state of the customer.
 	 * @param state_ Pointer to the State object to be set.
 	 */
	void setState(State *state);

	/**
 	 * @brief This method sets the rating of the customer.
 	 * @param rating Integer representing the rating to be set.
 	 */
	void setRating(int rating);

	// added for waiter functionality
	/**
 	 * @brief This method returns the order of the customer.
 	 *
 	 * @return String representing the order of the customer.
 	 */
	std::string getOrder();

	/**
 	 * @brief This method return the name of the customer.
 	 * @param order String representing the name  of the customer.
 	 */
	std::string getName();

	/**
 	 * @brief This method return the id of the customer.
 	 * @param order String representing the id  of the customer.
 	 */
	std::string getCustomerID();

	/**
 	 * @brief This method return the rating of the customer.
 	 * @param order String representing the rating  of the customer.
 	 */
	int getRating();

	/**
 	 * @brief This method generates a customer ID for the customer.
 	 * @return String representing the generated customer ID.
 	 */
	std::string generateCustomerID();

	/**
 	 * @brief This method sets the customer ID of the customer.
 	 * @param cID String representing the customer ID to be set.
 	 */
	void setCustomerID(std::string cID);

	/**
 	 * @brief This method returns the total amount of the customer.
 	 * @return Double representing the total amount of the customer.
 	 */
	double getTotalAmount();

	/**
	 * @brief This method sets the dish of the customer.
 	 * @param d Pointer to the Dish object to be set.
 	 */
	void setDish(Dish *d);

	/**
 	 * @brief This method returns the dish of the customer.
 	 * @return Pointer to the Dish object of the customer.
 	 */
	Dish *getDish();

private:
	State *state;
	std::string CustomerID;
	// added for waiter functionality
	std::string order;
};

#endif