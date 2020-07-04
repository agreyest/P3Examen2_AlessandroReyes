#include "Archivo.h"
#include <sstream>
using std::stringstream;

Archivo::Archivo(string pFileName){
	fileName = pFileName;
}

bool Archivo::abrirEscritura(int modo){
	modoEscritura = modo;
	if(modoEscritura == 1)
		outputFile.open(fileName.c_str(), std::ios::app);
	else
			outputFile.open(fileName.c_str());
			
	return outputFile.is_open();
}

bool Archivo::guardarMatriz(Matriz* matriz){
	if(outputFile.is_open()){
		outputFile << matriz->identificador
					<<','<< matriz->numeros
					<<','<< matriz->size<<','<<'\n';
		return true;
	}else
		return false; 
}

bool Archivo::cerrarEscritura(){
	outputFile.close();
	return !outputFile.is_open();
}



bool Archivo::abrirLectura(){
	inputFile.open(fileName.c_str());
	return inputFile.is_open();
}

vector<Matriz*> Archivo::leerMatrices(){
	vector<Matriz*> retval;
			
	if(inputFile.is_open()){
		string numeros;
		int size;
		string id1;
		//buffer para leer del archivo
		string buffer;
			
		while( getline(inputFile,buffer) ){
			
			//string stream 
			stringstream myStream;
			myStream << buffer;
					
			//buffer temporal para la edad 
			string sizeBuffer;
					
	
			//cargar todos campos en variables temporales
			//id
			getline(myStream,id1,',');
			//numeros
			getline(myStream,numeros,',');
			//size
			getline(myStream,sizeBuffer,',');
	
					
			//convertir de string a int
			//insertar al stream la edad en texto
			myStream << sizeBuffer;
			//sacarlo como int 
			myStream >> size;
			
			char id = id1[0];
			retval.push_back(new Matriz(size,id,numeros));	
//			cout<<retval.size()<<endl;
				
		}//end while
//		int** prueba;
//		for(int i = 0; i < retval.size(); i++){
//			cout<<retval[i]->getId()<<endl;
//			cout<<retval[i]->getSize()<<endl;
//			
//			prueba =retval[i]->getMatriz();
//			for(int j = 0; j < retval[i]->getSize(); j++){
//				cout<<"|";
//				for(int k = 0; k < retval[i]->getSize(); k++){
//					cout<<" "<<prueba[j][k]<<" ";
//				}
//				cout<<"|"<<endl;
//			}
//		}
		 
		return retval;
	}//end if
	else 
		return retval;
}

//cerrar archivo
bool Archivo::cerrarLectura(){
	inputFile.close();
	return !inputFile.is_open();
}


