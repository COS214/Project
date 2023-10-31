#include <iostream>
#include "Table.h"
#include "Customer.h"

void Table::addCustomer(Customer *newCustomer)
{
    customers.push_back(newCustomer);
}

Table::Table()
{
}

Table::~Table()
{
    delete this;
    std::cout << "Deleted Table" << std::endl;
}