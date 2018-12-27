/**
* @file ConjuntoLetras.cpp
* @brief Implementación del TDA ConjuntoLetras
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include <fstream>
#include "BolsaLetras.h"
#include "ConjuntoLetras.h"
#include "Letra.h"


using namespace std;


ConjuntoLetras::ConjuntoLetras(set<Letra> dat){
  datos = dat;
}


istream & operator>>(istream & is,ConjuntoLetras & conj){
  Letra letra_aux;
  char char_letra;
  char cantidad_char;
  int cantidad;
  char puntuacion_char;
  int puntuacion;
  while(is.get(char_letra)){
    //se puede hacer get de int ??
    is.get(cantidad_char);
    is.get(puntuacion_char);
    cantidad = cantidad_char +'0';
    puntuacion = puntuacion_char +'0';
    letra_aux.setCaracter(char_letra);
    letra_aux.setCantidad(cantidad);
    letra_aux.setPuntuacion(puntuacion);
    //Letra letra_aux(char_letra, cantidad, puntuacion);

    conj.datos.insert(letra_aux);
  }
  return is;
}



ostream & operator<<(ostream & os, const ConjuntoLetras &conj){
  set<Letra> ::iterator it;
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

//estaria bien cogerlas con la probabilidad proporcional a la cantidad que hay (COnjunto de letras es un set ;(
//tambien tener en cuenta que los elementos de COnjunto de letras son Letras y los de bolsa char
BolsaLetras ConjuntoLetras::seleccionaAleatorio(int numero){
  BolsaLetras bolsa;
  multiset<char> multiset_bolsa;
  return bolsa;
}
