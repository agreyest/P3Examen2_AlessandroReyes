#ifndef OPERADOR_H
#define OPERADOR_H

#include "Object.h"

class Operador: public Object {
	public:
		Operador(char);
	protected:
		char operador;
};

#endif
