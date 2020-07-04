#include <iostream>
#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
#include <bits/stdc++.h>
using namespace std;

#include "Object.h"

class Matriz: public Object {
	public:
		Matriz(int, char, string);
		
		int getSize();
		char getId();
		int** getMatriz();
		
	protected:
		int size;
		char identificador;
		int** matrix;
		string numeros;
		
    friend class Archivo;
};

#endif
