/**
* @file BolsaLetras.cpp
* @brief Implementación del TDA BolsaLetras
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "BolsaLetras.h"
#include "ConjuntoLetras.h"


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

multiset<char> BolsaLetras::seleccionaAleatorio(int cantidad){
	srand(time(NULL));
	int num;
	multiset<char>  resultado;
	set<int> numeros;
	for (int i=0; i<cantidad; i++){
		num = rand()%(datos.size());
		multiset<char>::iterator it = datos.begin();
		if (numeros.count(num)==0){
			for (int i=0; i<num; i++)
				it ++;
			resultado.insert((*it));
			numeros.insert(num);
		}
		else
			i--;

	}

	return resultado;
}


BolsaLetras::BolsaLetras(const ConjuntoLetras & conjun){
	for (set<Letra>::iterator it = conjun.begin(); it != conjun.end(); it ++){
		for (int i=0; i<((*it).Cantidad()); i++){
			datos.insert((*it).Caracter());
		}
	}
}

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
  for (it = bolsa.datos.begin(); it != bolsa.datos.end(); it++){
    os << (*it) << endl;
	}
  return os;
}

istream & operator>>(istream & is, BolsaLetras & bolsa){
  char letra;
  while(is.get(letra))
    bolsa.datos.insert(letra);
  return is;
}
