/**
 * @file Waiter.h
 * @brief Contains the declaration of the Waiter class.
 */

#ifndef WAITER_H
#define WAITER_H

#include "Observer.h"
#include "State.h"
#include "Chefs.h"
#include "Table.h"
#include "Iterator.h"
#include "Bill.h"
#include "Tab.h"

/**
 * @class Waiter
 * @brief The Waiter class represents a waiter responsible for taking orders and serving customers.
 */
class Waiter : public Observer, public Iterator
{

private:
	string name;
	State *waiterState;
	State *customerState;

	// added for iterator pattern
	std::list<Table *> tables; // reference to tables
	std::list<Table *>::iterator currentTable;
	std::list<Customer *>::iterator currentCustomer;

public:
	/**
	 * @brief Default constructor for the Waiter class.
	 */
	Waiter();

	/**
	 * @brief Place an order with the chefs.
	 * @param Chefs A pointer to the Chefs class.
	 * @param order A pointer to the Command representing the order.
	 * @param cookStrategy An integer representing the chosen cooking strategy.
	 */
	void placeOrder(Chefs *Chefs, Command *order, int cookStrategy);

	/**
	 * @brief Update the waiter with a message.
	 * @param message The message to update the waiter.
	 */
	void update(string message);

	// added for iterator pattern
	/**
	 * @brief Receive an order.
	 * @param order A pointer to the Command representing the order.
	 */
	void receiveOrder(Command *order);

	/**
	 * @brief Constructor for the Waiter class with a list of tables.
	 * @param tables A list of tables to associate with the waiter.
	 */
	Waiter(std::list<Table *> tables);

	/**
	 * @brief Get the first customer in the list.
	 * @return A pointer to the first customer in the list.
	 */
	Customer *first();

	/**
	 * @brief Get the next customer in the list.
	 * @return A pointer to the next customer in the list.
	 */
	Customer *next();

	/**
	 * @brief Check if the iteration is done.
	 * @return True if the iteration is done, otherwise false.
	 */
	bool isDone();

	/**
 	 * @brief Serve customers by delivering their orders to the chefs.
 	 * @param Chefs A pointer to the Chefs class.
 	 * @param order A pointer to the Command representing the order to be served.
 	 */
	void serveCustomers(Chefs *Chefs, Command *order);

	/**
	 * @brief Destructor for the Waiter class.
	 */
	virtual ~Waiter(); // Destructor
};

#endif
