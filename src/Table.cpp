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