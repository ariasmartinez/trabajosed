/**
* @file Diccionario.cpp
* @brief Implementación del TDA Diccionario
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include "Diccionario.h"
#include "ConjuntoLetras.h"
#include "Letra.h"
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

}

string Diccionario::iterator::operator *(){
  return (*it);
}

Diccionario::iterator & Diccionario::iterator::operator ++(){
  it++;
  return *this ;
}

bool Diccionario::iterator::operator ==(const iterator &i){
  return (i.it == it);
}

bool Diccionario::iterator::operator !=(const iterator &i){
  return i.it != it;
}

set<string> Diccionario::SacarPalabras(const multiset<char> & seleccionadas){
  set<string> resultado;
  for (set<string>::iterator it = datos.begin(); it!=datos.end(); ++it){
    if ((*it).size() <= seleccionadas.size()){
      multiset<char> aux = seleccionadas;
      bool fin = false;
      for(int i=0; i<(*it).size()&& !fin; i++){
        multiset<char>::iterator iter = aux.find((*it)[i]);
        if(iter != aux.end())
          aux.erase(iter);
        else
          fin =true;
      }

      if(!fin)
        resultado.insert((*it));
    }

}

  return resultado;
}


ConjuntoLetras Diccionario::buscarFrecuenciaLetras(ConjuntoLetras & conjunto ) const{
  int puntu_nueva = 0;
  for (set<string>:: iterator it = datos.begin(); it != datos.end(); it++){
    for (int i = 0; i < (*it).size(); i++){
      set<Letra>:: iterator it_letra;
      it_letra = conjunto.BuscarLetra((*it)[i]);
      if (it_letra != conjunto.end()){
        puntu_nueva = (*it_letra).Cantidad();
        Letra l;
        l.setCantidad(puntu_nueva);
        (*it_letra).setCantidad(puntu_nueva);
      }
    }
  }
  return conjunto;
}
