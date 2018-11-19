#ifndef __Pila_max_Cola_H__
#define __Pila_max_Cola_H__

typedef struct{
  int ele; ///<elemento a almacenar
  int minimo; ///<el minimo
}elemento;

/* Está puesto en pila_min_lista ¿Lo ponemos?

ostream & operator<<(ostream & os,const elemento & a){
 os<<a.ele<< " Minimo: "<<a.minimo<<endl;
 return os;
}
*/

class Pila_max_Cola{
private:
    Cola<elemento> datos;
}

public:

  Pila_max_Cola();

  Pila_max_Cola(Cola<elementos> dat);

  Pila_max_Cola(const Pila_max_Cola & otra);

  ~Pila_max_Cola();

  Pila_max_Cola& operator= (const Pila_max_Cola& otra);

  bool vacia() const;

  elemento & tope();

  const elemento & tope () const;

  void poner(const int & elem);

  void quitar();

  int num_elementos() const;
