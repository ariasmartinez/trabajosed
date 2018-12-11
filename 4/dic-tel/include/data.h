/**
* @file data.h
* @brief fichero cabecera del struct data
* @authors Celia Arias Martínez
*          Lucía Salamanca López
*/
#include<list>
#ifndef _DATA_H
#define _DATA_H
using namespace std;
template <class T,class U>

/**
Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
struct data{
    T clave;
    list<U> info_asoci;
 };
template <class T, class U>
/**
* @brief Operador de menor
* @param d1 primer elemento de la clase data que se quiere comparar
* @param d2 segundo elemento de la clase data que se quiere comparar
* @return true si el primer elemento es menor que el segundo, false en otro caso
*/
bool operator< (const data<T,U> &d1, const data<T,U> &d2);
#endif
