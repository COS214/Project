/**
 * @file Floor.cpp
 * @brief Contains the declaration of the Floor class functions.
 */

#include <iostream>
#include "Floor.h"
#include "Table.h"
/**
 * @brief This method allows a new table to be added to the floor.
 *
 * @param newTable Pointer to the Table object to be added.
 */
void Floor::addTable(Table *newTable)
{
    this->tables.push_back(newTable);
}
/**
 * @brief Default constructor for the Floor class.
 */
Floor::Floor() {}
/**
 * @brief Destructor for the Floor class. Deletes all tables and the floor itself.
 */
Floor::~Floor()
{
    for (Table *table : tables)
    {
        delete table;
    }
    std::cout << "Deleted Floor" << std::endl;
}
/**
 * @brief This method returns a list of tables on the floor.
 *
 * @return A list of pointers to Table objects.
 */
std::list<Table *> Floor::getTables()
{
    return this->tables;
}