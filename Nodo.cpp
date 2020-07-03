#include "Nodo.h"


Nodo* Nodo::getNext(){
	return next_node;
}
void Nodo::setNext(Nodo* pNext){
	next_node = pNext;
}
