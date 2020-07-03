#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo {
	public:
		
		Nodo* getNext();
		void setNext(Nodo*);
		
	protected:
		Nodo* next_node;
		Object* data; 
};

#endif
