#ifndef __Pila_max_H__
#define __Pila_max_H__

#include "cola.h"
#include <iostream>

using namespace std;

typedef struct{
  int ele; ///<elemento a almacenar
  int maximo; ///<el máximo
}elemento;


ostream & operator<<(ostream & os,const elemento & a){
 os<<a.ele<< " Máximo: "<<a.maximo<<endl;
 return os;
}


class Pila_max{
private:
    Cola<elemento> datos;


public:
/**
* @brief: Constructor por defecto. Crea una pila_max vacía.
*/
  Pila_max();

  Pila_max(Cola<elemento> dat);

  Pila_max(const Pila_max & otra);

  ~Pila_max();

  Pila_max& operator= (const Pila_max& otra);

  bool vacia() const;

  elemento & tope();

  const elemento & tope () const;

  void poner(const int & elem);

  void quitar();

  int num_elementos() const;

  friend ostream & operator<<(ostream & os, Pila_max & pila);

};




#endif
