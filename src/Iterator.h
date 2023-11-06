/**
 * @file Iterator.h
 * @brief Contains the declaration of the Iterator class.
 */

#ifndef ITERATOR_H
#define ITERATOR_H

class Customer; // Forward declaration of Customer class because of abstraction


/**
 * @class Iterator
 * @brief The Iterator class defines an abstract interface for iterating over a collection of objects.
 */
class Iterator
{
public:
    /**
     * @brief Get the first element in the collection.
     * @return A pointer to the first element in the collection.
     */
    virtual Customer *first() = 0;

    /**
     * @brief Get the next element in the collection.
     * @return A pointer to the next element in the collection.
     */
    virtual Customer *next() = 0;

    /**
     * @brief Check if the iteration is complete.
     * @return True if the iteration is complete, false otherwise.
     */
    virtual bool isDone() = 0;
};

#endif
