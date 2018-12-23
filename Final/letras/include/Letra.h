/**
* @file Letra.h
* @brief Fichero cabecera del TDA Letra
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _Letra_h
#define _Letra_h

using namespace std;

class Letra{
private:
  char caracter; ///< Carácter de la propia letra
  double cant;  ///< Cantidad de veces que puede aparecer
  int punt; ///< Puntuación de la letra

public:
  /**
  @brief Constructor
  **/
  Letra(char car= '\n', double cant=0; punt=0);

  /**
  @brief Lee de un flujo de entrada un diccionario
  @param is:flujo de entrada
  @param let: el objeto donde se realiza la lectura.
  @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is, Letra & let);
  /**
  @brief Escribe en un flujo de salida un diccionario
  @param os:flujo de salida
  @param let: el objeto letra que se escribe
  @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const Letra &let);

};

#endif
