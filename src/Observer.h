#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

class Observer {
public:
    virtual void update(std::string message) = 0;
};

#endif
