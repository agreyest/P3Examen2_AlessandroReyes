#ifndef MATRIZ_H
#define MATRIZ_H

#include "Object.h"

class Matriz: public Object {
	public:
		
		void setSize();
		int getSize();
		void setId();
		int getId();
		void setMatrix();
		int getMatriz();
		
	protected:
		int size;
		char identificador;
		int** matrix;
};

#endif
