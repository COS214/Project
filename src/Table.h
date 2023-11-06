/**
 * @file Table.h
 * @brief Contains the declaration of the Table class.
 */

#ifndef TABLE_H
#define TABLE_H

#include <list>
#include "Customer.h"

/**
 * @class Table
 * @brief The Table class represents a dining table in the restaurant.
 */
class Table : public Customer
{
private:
    int tableNumber;
    std::list<Customer *> customers;

public:
    /**
     * @brief Default constructor for the Table class.
     */
    Table();

    /**
     * @brief Constructor for the Table class with a specified table number.
     * @param tableNumber An integer representing the table number.
     */
    Table(int tableNumber);

    /**
     * @brief Destructor for the Table class.
     */
    ~Table();

    /**
     * @brief Get the table number.
     * @return An integer representing the table number.
     */
    int getTableNumber() { return this->tableNumber; }

    /**
     * @brief Add a customer to the table.
     * @param newCustomer A pointer to the Customer to be added to the table.
     */
    void addCustomer(Customer *newCustomer);

    /**
     * @brief Get the list of customers seated at the table.
     * @return A list of Customer pointers representing the customers at the table.
     */
    std::list<Customer *> getCustomers();
};

#endif
