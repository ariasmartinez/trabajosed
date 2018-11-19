// #include "cola.h" ¿si está añadido en el .h hace falta ponerlo?
#include"Pila_max.h"

using namespace std;

Pila_max::Pila_max(){

}
Pila_max::Pila_max(cola<elemento> dat){
  datos = dat;
}

Pila_max::Pila_max(const Pila_max & otra){
  this->datos = otra.datos;
}

Pila_max::~Pila_max(){

}

Pila_max& Pila_max::operator= (const Pila_max& otra){

}

bool Pila_max::vacia() const{
  return(datos.vacia());
}

elemento & Pila_max::tope(){
  return(datos.frente());
}

const elemento & Pila_max::tope () const{
  return(datos.frente());
}

void Pila_max::poner(const int & elem){
  int max;
  if(elem > this->datos.frente().maximo)
    max = elem;
  else
    max = this->datos.frente().maximo;

  elemento ele_nuevo = {elem,max};

  cola<elemento> nueva;
  nueva.poner(ele_nuevo);

  int tamanio = this->datos.num_elementos();
  elemento vector [tamanio];

  for(int i=0; i<tamanio; i++){
    vector[i] = this->datos.frente();
    this->datos.quitar()
  }
  for(int i=0; i<tamanio; i++){
    nueva.poner(vector[i]);
  }
  this->datos = nueva;
}

void Pila_max::quitar(){
  this->datos.quitar();
}

int Pila_max::num_elementos() const{
  return(datos.num_elementos());
}
