#ifndef __Pila_max_H__
#define __Pila_max_H__

#include "cola.h"
#include <iostream>
#include "elemento.h"


using namespace std;


ostream & operator<<(ostream & os,const elemento & a);

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

  friend ostream & operator<<(ostream & os, const Pila_max & pila);

};




#endif
