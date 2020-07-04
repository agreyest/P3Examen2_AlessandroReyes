#include "Matriz.h"

Matriz::Matriz(int pSize, char pId, string pNums){
	size = pSize;
	identificador = pId;
	numeros = pNums;
	
	
	int cont=0;
	matrix = new int*[pSize];
	for(int i =0; i<pSize;i++){
		matrix[i]=new int[pSize];
	} 
	
	for(int i = 0; i < pSize; i++){
		for(int j = 0; j < pSize; j++){
			string cadenaN = "";
			cadenaN += pNums[cont];
			matrix[i][j] = stoi(cadenaN);
			cont++;
		}
	}
}
		
int Matriz::getSize(){
	return size;
}
char Matriz::getId(){
	return identificador;
}
int** Matriz::getMatriz(){
	return matrix;
}
