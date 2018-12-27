/**
* @file BolsaLetras.cpp
* @brief Implementación del TDA BolsaLetras
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>

#include <fstream>
#include "BolsaLetras.h"

using namespace std;

/* Si conseguimos hacer el de conjuntoletras no hace falta este
multiset<char> BolsaLetras::seleccionaAleatorio(int cantidad){
  srand(time(NULL));
  multiset<char> aleat;
  for (int i=0; i < cantidad; i++){
    aleat.insert(datos.at())
    datos.insert(rand()%(datos.size()-1));
  }
}
*/

bool BolsaLetras::leerDeFichero(const char *fichero){
		bool cond=true;
		ifstream is;
		is.open(fichero);
		if(is){
				is >> (*this);
				is.close();
		}
		else{
				cout << "Error de apertura del fichero " << fichero << endl;
				cond=false;
        is.close();
		}
		return cond;
}

ostream & operator<<(ostream & os, const BolsaLetras &bolsa){
  multiset<char> ::iterator it;
  for (it = bolsa.datos.begin(); it != bolsa.datos.end(); it++)
    os << (*it) << endl;
  return os;
}

istream & operator>>(istream & is, BolsaLetras & bolsa){
  char letra;
  while(is.get(letra))
    bolsa.datos.insert(letra);
  return is;
}
