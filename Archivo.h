#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
#include <iostream>
using namespace std;
#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;

#include "Object.h"
#include "Matriz.h"

class Archivo{
	public:
		Archivo(string);
		
		bool abrirEscritura(int);
		virtual bool guardarMatriz(Matriz*);
		bool cerrarEscritura();
		
		virtual bool abrirLectura();
		virtual vector<Matriz*> leerMatrices();
		bool cerrarLectura();
		
		
		
		
	protected:
		string fileName;
		ofstream outputFile;
		int modoEscritura;
		ifstream inputFile;
};

#endif
