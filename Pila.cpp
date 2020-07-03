#include "Pila.h"

Pila::Pila(){
    head = nullptr;
}
Pila::Pila(Nodo* _head){
    head = _head;
}
Nodo* Pila::pop(){
    Nodo* temp_head = head;
    head = head->getNext();
    return temp_head;
}
Nodo* Pila::top(){
    return head;
}
void Pila::push(Nodo* _node){
    _node->setNext(head);
    head = _node;
}
void Pila::delete_stack(Nodo* _node){
    if (_node->getNext() != nullptr){
        delete_stack(_node->getNext());
    }            
    delete _node;
}
Pila::~Pila(){
    delete_stack(head);
}

