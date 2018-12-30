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
  set<string>::iterator it;
  for (it = D.datos.begin(); it!=D.datos.end(); it++)
    os << (*it) << endl;

  return os;
}

istream & operator>> (istream & is, Diccionario &D){
  string palabra;
  while (getline(is,palabra)){
    D.datos.insert(palabra);
  }
  return is;
}


Diccionario::iterator::iterator (){
  //Ni idea
}

string Diccionario::iterator::operator *(){
  return (*it);
}

Diccionario::iterator & Diccionario::iterator::operator ++(){
  it = it++;
  return *(this);
}

bool Diccionario::iterator::operator ==(const iterator &i){
  return (i.it == it);
}

bool Diccionario::iterator::operator !=(const iterator &i){
  return i.it != it;
}
