#include "KitchenOrder.h"

KitchenOrder::KitchenOrder(Order* order){
	this->order = order;
}
KitchenOrder::~KitchenOrder(){
	this->order = NULL;
	this->kitchen = NULL;
	delete this->order;
	delete this->kitchen;
}
void KitchenOrder::execute(){
	this->kitchen->prepare(this->order);
}

Order* KitchenOrder::getOrder() const{
	return this->order;
}