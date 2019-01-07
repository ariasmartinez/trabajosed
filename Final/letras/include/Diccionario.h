
/**
* @file Diccionario.h
* @brief Fichero cabecera del TDA Diccionario
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _Diccionario_h
#define _Diccionario_h
#include <set>
#include <string>
#include <vector>
#include "ConjuntoLetras.h"
#include "Letra.h"

using namespace std;

class Diccionario{
private:
set<string> datos;

public:
  /**
  @brief Construye un diccionario vacío.
  **/
  Diccionario(){}
  /**
  @brief Devuelve el numero de palabras en el diccionario
  **/
  int size() const ;
  /**
  @brief Obtiene todas las palabras en el diccionario de un longitud dada
  @param longitud: la longitud de las palabras de salida
  @return un vector con las palabras de  longitud especifica en el parametro de entrada
  **/
  vector<string> PalabrasLongitud(int longitud);
  /**
  @brief Indica si una palabra está en el diccionario o no
  @param palabra: la palabra que se quiere buscar
  @return true si la palabra esta en el diccionario. False en caso contrario
  **/
  bool Esta(string palabra);
  /**
  @brief Lee de un flujo de entrada un diccionario
  @param is:flujo de entrada
  @param D: el objeto donde se realiza la lectura.
  @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is,Diccionario  &D);
  /**
  @brief Escribe en un flujo de salida un diccionario
  @param os:flujo de salida
  @param D: el objeto diccionario que se escribe
  @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const Diccionario  &D);
  /**
  * @brief Devuelve el conjunto de las palabras válidas según unas letras determinadas
  * @param seleccionadas Letras que podemos utilizar para formar las palabras
  * @return Devuelve un set con las palabras válidas
  */
  set<string> SacarPalabras(const multiset<char> & seleccionadas);

  /**
  * @brief Calcula la cantidad de veces que aparece la letra en el diccionario
  * @param conjunto ConjuntoLetras que contiene las letras permitidas y en el que se guarda la frecuencia de cada letra. Es MODIFICADO
  */
  void buscarFrecuenciaLetras(ConjuntoLetras & conjunto)const ;

  class iterator{
  private:
    set<string>::iterator it;

  public:
    iterator ();
    iterator(set<string>::iterator itb){
      it = it;
    }
    string operator *();
    iterator & operator ++();
    bool operator ==(const iterator &i);
    bool operator !=(const iterator &i);
    friend class Diccionario;
  };

 set<string>::iterator cbegin()const {
   return datos.begin();
 }
 set<string>::iterator cend() const{
   return datos.end();
 }

 set<string>::iterator begin() {
   return datos.begin();
 }

 set<string>::iterator end() {
   return datos.end();
 }

};



#endif
