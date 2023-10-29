#include "HeadChef.h"

void HeadChef::cook(std::string dish) {
        std::cout << "Head chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}