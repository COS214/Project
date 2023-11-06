/**
 * @file Chefs.h
 * @brief Contains the declaration of the Chefs class.
 */

#ifndef CHEFS_H
#define CHEFS_H

class Waiter;

#include "Command.h"
#include "Mediator.h"
#include "Order.h"
// #include "Waiter.h"
#include <iostream>
#include "Inventory.h"	


/**
 * @class Chefs
 * @brief The Chefs class represents the base class for different chef types in the restaurant.
 */
class Chefs {
	protected:
		Chefs* nextHandler;
	
  public:
		static Inventory* inventory;
		Mediator* mediator;

		/**
		 * @brief Constructs a Chefs instance with a mediator.
		 * @param mediator A pointer to the mediator for communication.
		 */
		Chefs(Mediator* mediator) : mediator(mediator) {}

		/**
		 * @brief Cooks a specific dish based on the provided dish name.
		 * @param dish The name of the dish to be cooked.
		 */
   		virtual void cook(std::string dish) = 0;

		/**
		 * @brief Default Constructor for Chefs class.
		 */
		Chefs();
		/**
		 * @brief Default Destructor for Chefs class.
		 */
		virtual ~Chefs()=default;
		/**
		 * @brief Prepares an order for a waiter to deliver to a customer.
		 * @param order The order to be prepared.
		 * @param currWaiter A pointer to the current waiter handling the order.
		 * @param cookStrategy An integer indicating the cooking strategy to use.
		 */
		virtual void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy);

		/**
		 * @brief Sets the next chef in the chain of responsibility.
		 * @param next A pointer to the next chef to handle the request.
		 */
		void setNext(Chefs* next);

		/**
		 * @brief Sets the mediator for communication with waiters.
		 * @param mediator A pointer to the mediator for communication.
		 */
		void setMediator(Mediator* mediator);
};

#endif