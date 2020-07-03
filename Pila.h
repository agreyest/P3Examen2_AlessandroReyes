#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

class Pila{
	public:
		
		Pila();
        Pila(Nodo* _head);
        Nodo* pop();
        Nodo* top();
        void push(Nodo* _node);
        void delete_stack(Nodo* _node);
        ~Pila();
        
	protected:
		 Nodo* head;
};

#endif
