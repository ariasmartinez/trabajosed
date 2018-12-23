/**
* @file Diccionario.cpp
* @brief Implementación del TDA Diccionario
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include "Diccionario.h"
// #include <set> ¿Hay que ponerlo?
//#include <string> ¿Hay que ponerlo?
// #include <vector> ¿Hay que ponerlo?

using namespace std;

int Diccionario::size() const{
  return datos.size();
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
  vector<string> salida;
  for (set<string>::iterator it=datos.begin(); it!=datos.end(); it++){
    if(((*it).size()) == longitud)
      salida.push_back((*it));
  }
  return salida;
}

bool Diccionario::Esta(string palabra){
  bool esta = false;
  if ((datos.count(palabra))==1)
    esta = true;

  return esta;
}

ostream & operator<< (ostream & os, const Diccionario &D){

  /*for (set<string>::iterator it=datos.begin(); it!=datos.end(); it++)*/
  iterator it;
  for (iterator it = datos.begin(); it!=datos.end(); it++)
    os << (*it) << endl;

  return os;
}

ostream & operator>> (ostream & is, Diccionario &D){
  string palabra;
  if (getline(is, palabra)){
    D.datos.insert(palabra);
  }
  return is;
}
