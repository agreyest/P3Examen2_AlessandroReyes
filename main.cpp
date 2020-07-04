#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#include <cmath>
using std::sqrt;


#include "Nodo.h"
#include "Pila.h"
#include "Object.h"
#include "Matriz.h"
#include "Operador.h"
#include "Archivo.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Nodo* operacion(Object*, Object*, Object*);//operador, matriz, matriz

int main(int argc, char** argv) {
	Archivo* Amatrices = new Archivo("Matrices.txt");
	
	Pila* lista;
	Matriz* matris;
	
	vector<Matriz*> matrices;
	Amatrices->abrirLectura();
	matrices = Amatrices->leerMatrices();
	Amatrices->cerrarLectura();
//	cout<<"matrices size: "<<matrices.size()<<endl;
	
	string ans = "";
	while(ans != "exit"){
		cout<<">>";
		cin>>ans;
		
		if(ans[1]== '=' ){//esta ingresando una matriz
			string numMatriz;
			for(int i = 0; i < ans.size(); i++){
				if(i > 0 && ans[i]!= ',' && ans[i]!= '[' && ans[i]!= ']'&& ans[i]!= '='){
					numMatriz += ans[i];
				}
			}
//			cout<<"numMatriz: "<<numMatriz<<endl;
			int raiz = sqrt(numMatriz.size());
//			cout<<"Raiz= "<<raiz<<endl;
//			cout<<"numMatriz.size()= "<<numMatriz.size()<<endl;
			if( (raiz * raiz) == (numMatriz.size()) ){
//				cout<<"Entra if"<<endl;
				matris = new Matriz(raiz, ans[0], numMatriz);
//				cout<<"antes pushback"<<endl;
				matrices.push_back( matris );
//				cout<<"despues pushback"<<endl;
				Amatrices->abrirEscritura(1);
				Amatrices->guardarMatriz(matris);
				Amatrices->cerrarEscritura(); //buffer flush
				
				int** matrix = matris->getMatriz();
				for(int i = 0; i < raiz; i++){
					cout<<"|";
					for(int j = 0; j < raiz; j++){
						cout<<" "<<matrix[i][j];
		            }
					cout<<"|"<<endl;		
	            }
				
			}else{
				cout<<"error, solo puede ingresar matrices cuadradas"<<endl;
			}
		}else{//es una operacion,
			for(int i = ans.size()-1; i>=0;i--){
				for(int j = 0; j < matrices.size(); j++){
					if( ans[i]==matrices[j]->getId() ){
						lista->push( new Nodo(matrices[j]) );
					}else if( ans[i]=='-' || ans[i]=='*' || ans[i]=='+' ){
						Operador* ope = new Operador( ans[i] );
						lista->push( new Nodo(ope) );
					}
				}
				
			}//fin for para push a la pila
			
			Nodo* operando1 = lista->pop();
			Nodo* operador = lista->pop();
			Nodo* operando2 = lista->pop();
			
		}//fin else
	}//fin while
	return 0;
}

Nodo* operacion(Object* pOperador, Object* pOperando1 , Object* oOperando2){//operador, matriz, matriz
	if( pOperador == new Operador('+') ){
		int** mat1 =pOperando1->getMatriz();
	}else if( pOperador == new Operador('-') ){
		
	}else if( pOperador == new Operador('*') ){
		
	}
}
