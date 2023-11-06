/**
 * @file Floor.h
 * @brief Contains the declaration of the Floor class.
 */

#ifndef FLOOR_H
#define FLOOR_H

#include <list>
#include "Table.h"

/**
 * @class Floor
 * @brief The Floor class represents a floor in a restaurant with multiple tables.
 */
class Floor : public Table
{
private:
    std::list<Table *> tables;

public:

    /**
     * @brief Constructor for the Floor class.
     */
    Floor();

    /**
     * @brief Destructor for the Floor class.
     */
    ~Floor();

    /**
     * @brief Add a new table to the floor.
     * @param newTable A pointer to the table to be added to the floor.
     */
    void addTable(Table *newTable);

    /**
     * @brief Get the list of tables on the floor.
     * @return A list of tables on the floor.
     */
    std::list<Table *> getTables();
};

#endif
