#ifndef TABLE_H
#define TABLE_H

#include <list>
#include "Customer.h"

class Table : public Customer
{
private:
    int numCustomers;
    std::list<Customer *> customers;

public:
    Table();
    ~Table();
    void addCustomer(Customer *newCustomer);
};

#endif
