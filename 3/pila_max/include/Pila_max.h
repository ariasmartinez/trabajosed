/**
* @file Pila_max.h
* @brief Fichero cabecera del TDA Pila_max
* @authors Celia Arias Martínez
	   Lucía Salamanca López
*/

#ifndef __Pila_max_H__
#define __Pila_max_H__

#include "cola.h"
#include <iostream>
#include "elemento.h"


using namespace std;
/**
* @brief Salida de un elemento a ostream
* @param os stream de salida
* @param a elemento a escribir
* @post Se obtiene un elemento con formato elem Máximo: maximo
*/
ostream & operator<<(ostream & os,const elemento & a);

/**
* @class Pila_max
* @brief Representa una pila en la que cada elemento tiene el máximo de los anteriores
*/
class Pila_max{
private:
    Cola<elemento> datos;


public:
/**
* @brief Constructor por defecto. Crea una pila_max vacía.
*/
  Pila_max();

/**
* @brief Constructor de la clase 
* @param dat Cola de elementos 
*/
  Pila_max(Cola<elemento> dat);

/**
* @brief Constructor de copia de la clase
* @param otra objeto de la clase que se quiere copiar
*/
  Pila_max(const Pila_max & otra);

/**
* @brief Destructor de la clase
*/
  ~Pila_max();

/**
* @brief Operador de asignación
* @param otra Pila_max que queremos asignarle a this
* @return Devuelve la referencia de nuestra Pila_max
*/
  Pila_max& operator= (const Pila_max& otra);

/**
* @brief Devuelve si la Pila_max está vacía
* @return true si está vacía, false en otro caso
*/
  bool vacia() const;

/**
* @brief Devuelve el elemento que está en el tope de la pila
* @return Devuelve la referencia al elemento de la pila que está en el tope
*/
  elemento & tope();

/**
* @brief Devuelve el elemento que está en el tope de la pila
* @return Devuelve la referencia constante al elemento de la pila que está en el tope
*/
  const elemento & tope () const;

/**
* @brief Añade un elemento en el tope de la pila
* @param elem Elemento que vamos a añadir 
*/
  void poner(const int & elem);

/**
* @brief Elimina el elemento del tope de la pila
*/
  void quitar();

/**
* @brief Devuelve el número de elementos que tiene la pila
* @return Tamaño de la pila
*/
  int num_elementos() const;


/**
* @brief Salida de un elemento a ostream
* @param os stream de salida
* @param pila Pila_max a escribir
* @post Se obtiene un elemento con formato elemento tope \n elemento tope-1 \n .... elemento 0
*/
  friend ostream & operator<<(ostream & os, const Pila_max & pila);

};




#endif
