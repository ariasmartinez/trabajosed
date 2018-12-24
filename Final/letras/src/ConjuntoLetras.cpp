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

istream & operator>>(istream & is,ConjuntoLetras & conj){
  char letra;
  while(is.get(letra))
    conj.datos.insert(letra);
  return is;
}

ostream & operator<<(ostream & os, const ConjuntoLetras &conj){
  set<char> iterator:: it;
  for (it = conj.datos.begin(); it != conj.datos.end(); it++)
    os << (*it) << endl;
  return os;
}
