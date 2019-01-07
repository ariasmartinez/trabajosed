/**
* @file BolsaLetras.h
* @brief Fichero cabecera del TDA BolsaLetras
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _BolsaLetras_h
#define _BolsaLetras_h
#include <set>
#include "ConjuntoLetras.h"


using namespace std;

class BolsaLetras{
private:
  multiset<char> datos;

public:
  /**
  * @brief Constructor por defecto
  */
  BolsaLetras(){};

  /**
  * @brief Constructor a partir de un multiset<char>
  * @param dat multiset<char> a partir del cual formamos la bolsa
  */
  BolsaLetras(multiset<char> dat);

  /**
  * @brief Devuelve el tamaño de la bolsa
  * @return Devuelve un entero con el número de letras que hay
  */
  int size(){
    return datos.size();
  }

  /**
  * @brief Crea un multiset<char> con letras aleatorias que se encuentran en la bolsa
  * @param cantidad Número de letras seleccionadas
  * @return Devuelve un multiset<chat> con las letras seleccionadas
  */
  multiset<char> seleccionaAleatorio(int cantidad);

  /**
  * @brief Constructor a partir de un ConjuntoLetras
  * @param conjun ConjuntoLetras a partir el cual se construye la BolsaLetras
  */
  BolsaLetras(const ConjuntoLetras & conjun);

  /**
  * @brief Lee de un fichero una BolsaLetras
  * @param fichero Nombre del fichero del que leemos la BolsaLetras
  * @return true si lo ha leído correctamente, false en caso contrario
  */
  bool leerDeFichero(const char *fichero);
  /**
  @brief Lee de un flujo de entrada una bolsa de letras
  @param os:flujo de entrada
  @param bolsa: el objeto BolsaLetras que se lee
  @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is,BolsaLetras & bolsa);
  /**
  @brief Escribe en un flujo de salida una bolsa de letras
  @param os:flujo de salida
  @param bolsa: el objeto BolsaLetras que se escribe
  @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const BolsaLetras &bolsa);
};

#endif
