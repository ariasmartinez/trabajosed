/**
* @file Letra.cpp
* @brief Implementación del TDA Letra
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include "Letra.h"

using namespace std;

//pongo a porque '' daba error
Letra::Letra(){
  carac = 'a';
  cant = 0;
  punt = 0;
}

Letra::Letra(char caracter, int cantidad, int puntuacion){
  carac = caracter;
  cant = cantidad;
  punt = puntuacion;
}

bool Letra::operator<(const Letra & letra_b) const{
  if (carac <= letra_b.carac)
    return true;
  else
    return false;
}

istream & operator>>(istream & is, Letra & let){
  char caracter;
  int cantidad, puntuacion;
  is >> caracter;
  is >> cantidad;
  is >> puntuacion;
  //no se si esto funciona asi
  let.carac = caracter;
  let.punt = puntuacion;
  let.cant = cantidad;

  return is;
}

ostream & operator<<(ostream & os, const Letra &let){
  os << let.carac << " " << let.cant << " " << let.punt << endl;
  return os;
}
