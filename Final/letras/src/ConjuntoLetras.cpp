/**
* @file ConjuntoLetras.cpp
* @brief Implementación del TDA ConjuntoLetras
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include "ConjuntoLetras.h"

using namespace std;


ConjuntoLetras::ConjuntoLetras(set<Letra> dat){
  datos = dat;
}

/// ¿¿?? lo he puesto pa que deje meter una letra pero estoy como pasando de la frecuencia y eso xd
istream & operator>>(istream & is,ConjuntoLetras & conj){
  Letra letra_aux;
  char char_letra;
  while(is.get(char_letra)){
    letra_aux(char_letra, 1, 1);
    conj.datos.insert(letra_aux);
  }
  return is;
}

ostream & operator<<(ostream & os, const ConjuntoLetras &conj){
  set<char> iterator:: it;
  for (it = conj.datos.begin(); it != conj.datos.end(); it++)
    os << (*it) << endl;
  return os;
}

bool ConjuntoLetras::leerDeFichero(const char *fichero){
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
