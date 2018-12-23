/**
* @file Letra.cpp
* @brief Implementación del TDA Letra
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include "Letra.h"

using namespace std;

Letra::Letra(){
  carac = '';
  cant = 0;
  punt = 0;
}

Letra::Letra(char caracter, int cantidad, int puntuacion){
  carac = caracter;
  cant = cantidad;
  punt = puntuacion;
}

istream & operator>>(istream & is, Letra & let){
  char carac;
  int cantidad, puntuacion;
  is >> caracter;
  is >> cantidad;
  is >> puntuacion;
  //no se si esto funciona asi
  let.carac = caracter;
  let.punt = puntuacion;
  let.cant = cantidad;
}

ostream & operator<<(ostream & os, const Letra &let){
  os << let.carac << " " << let.cant << " " << let.punt << endl;
  return os;
}
