#ifndef FLOOR_H
#define FLOOR_H

#include <list>
#include "Table.h"

class Floor : public Table
{
private:
    std::list<Table *> tables;

public:
    Floor();
    ~Floor();
    void addTable(Table *newTable);
};

#endif
