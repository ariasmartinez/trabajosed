/**
* @file ConjuntoLetras.h
* @brief Fichero cabecera del TDA ConjuntoLetras
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _ConjuntoLetras_h
#define _ConjuntoLetras_h
#include <set>
#include "Letra.h"

using namespace std;

class ConjuntoLetras {
private:
  set<Letra> datos;

public:
  /**
  * @brief Constructor por defecto
  */
  ConjuntoLetras(){}

  /**
  @brief Lee de un flujo de entrada un conjunto de letras
  @param is:flujo de entrada
  @param conj: el objeto donde se realiza la lectura.
  @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is,ConjuntoLetras & conj);
  /**
  @brief Escribe en un flujo de salida un conjunto de letras
  @param os:flujo de salida
  @param let: el objeto ConjuntoLetras que se escribe
  @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const ConjuntoLetras &conj);


};

#endif
