#ifndef TABLE_H
#define TABLE_H

#include <list>
#include "Customer.h"

class Table : public Customer
{
private:
    int tableNumber;
    std::list<Customer *> customers;

public:
    Table();
    Table(int tableNumber);
    ~Table();
    void addCustomer(Customer *newCustomer);
};

#endif
