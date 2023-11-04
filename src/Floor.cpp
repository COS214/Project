#include <iostream>
#include "Floor.h"
#include "Table.h"

void Floor::addTable(Table *newTable)
{
    this->tables.push_back(newTable);
}

Floor::Floor() {}

Floor::~Floor()
{
    for (Table *table : tables)
    {
        delete table;
    }
    delete this;
    std::cout << "Deleted Floor" << std::endl;
}

std::list<Table *> Floor::getTables()
{
    return this->tables;
}