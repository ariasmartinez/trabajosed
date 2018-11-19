#ifndef __Pila_max_H__
#define __Pila_max_H__

#include "cola.h"
typedef struct{
  int ele; ///<elemento a almacenar
  int maximo; ///<el máximo
}elemento;

/* Está puesto en pila_min_lista ¿Lo ponemos?

ostream & operator<<(ostream & os,const elemento & a){
 os<<a.ele<< " Minimo: "<<a.minimo<<endl;
 return os;
}
*/

class Pila_max{
private:
    cola<elemento> datos;
}

public:
/**
* @brief: Constructor por defecto. Crea una pila_max vacía.
*/
  Pila_max();

  Pila_max(cola<elemento> dat);

  Pila_max(const Pila_max_Cola & otra);

  ~Pila_max();

  Pila_max& operator= (const Pila_max& otra);

  bool vacia() const;

  elemento & tope();

  const elemento & tope () const;

  void poner(const int & elem);

  void quitar();

  int num_elementos() const;
