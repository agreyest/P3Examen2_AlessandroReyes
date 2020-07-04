#include "Nodo.h"
Nodo::Nodo(Object* pValue){
	data = pValue;
}

Nodo* Nodo::getNext(){
	return next_node;
}
void Nodo::setNext(Nodo* pNext){
	next_node = pNext;
}
