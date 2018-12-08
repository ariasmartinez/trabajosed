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
* @brief struct data
*/
struct data{
    T clave; ///<clave que identifica al elemento
    list<U> info_asoci; ///<información asociada al elemento


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
