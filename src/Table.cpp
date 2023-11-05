/**
 * @file Table.cpp
 * @brief Contains the declaration of the Table class functions.
 */

#include <iostream>
#include "Table.h"
#include "Customer.h"
/**
 * @brief This method allows a new customer to be added to the table.
 *
 * @param newCustomer Pointer to the Customer object to be added.
 */
void Table::addCustomer(Customer *newCustomer)
{
    customers.push_back(newCustomer);
}
/**
 * @brief Constructor for the Table class that takes a table number as a parameter.
 *
 * @param tableNumber Integer representing the number of the table.
 */
Table::Table(int tableNumber)
{
    this->tableNumber = tableNumber;
}
/**
 * @brief Default constructor for the Table class.
 */
Table::Table()
{
}
/**
 * @brief Destructor for the Table class. Deletes all customers and the table itself.
 */
Table::~Table()
{
    for (Customer *customer : customers)
    {
        delete customer;
    }
    delete this;
    std::cout << "Deleted Table" << std::endl;
}
/**
 * @brief This method returns a list of customers at the table.
 *
 * @return A list of pointers to Customer objects.
 */
std::list<Customer *> Table::getCustomers()
{
    return this->customers;
}