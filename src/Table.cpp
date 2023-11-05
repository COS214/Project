/**
 * @file Table.cpp
 * @brief Contains the declaration of the Table class functions.
 */

#include <iostream>
#include "Table.h"
#include "Customer.h"

void Table::addCustomer(Customer *newCustomer)
{
    customers.push_back(newCustomer);
}

Table::Table(int tableNumber)
{
    this->tableNumber = tableNumber;
}

Table::Table()
{
}

Table::~Table()
{
    for (Customer *customer : customers)
    {
        delete customer;
    }
    delete this;
    std::cout << "Deleted Table" << std::endl;
}

std::list<Customer *> Table::getCustomers()
{
    return this->customers;
}