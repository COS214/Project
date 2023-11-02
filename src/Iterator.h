#ifndef ITERATOR_H
#define ITERATOR_H

class Customer;  // Forward declaration of Customer class because of abstraction

class Iterator {
public:
    virtual Customer* first() = 0;
    virtual Customer* next() = 0;
    virtual bool isDone() const = 0;
};

#endif  
