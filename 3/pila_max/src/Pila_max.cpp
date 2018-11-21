/**
* @file Pila_max.cpp
* @brief Implementación del TDA Pila_max
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#include "cola.h"
#include"Pila_max.h"
#include <iostream>
using namespace std;

Pila_max::Pila_max(){

}
Pila_max::Pila_max(Cola<elemento> dat){
  datos = dat;
}

Pila_max::Pila_max(const Pila_max & otra){
  this->datos = otra.datos;
}

Pila_max::~Pila_max(){

}

Pila_max& Pila_max::operator= (const Pila_max& otra){
  if(&otra != this){
    this->datos = otra.datos;
  }

  return *this;
}

bool Pila_max::vacia() const{
  return datos.vacia();
}

elemento & Pila_max::tope(){
  return datos.frente();
}

const elemento & Pila_max::tope () const{
  return datos.frente();
}

void Pila_max::poner(const int & elem){
  int max;
  if(!this->vacia()){
  if(elem > this->datos.frente().maximo)
    max = elem;
  else
    max = this->datos.frente().maximo;
  }
  else
    max =elem;
  elemento ele_nuevo = {elem,max};

  Cola<elemento> nueva;
  nueva.poner(ele_nuevo);

  int tamanio = this->datos.num_elementos();
  elemento vector [tamanio];

  for(int i=0; i<tamanio; i++){
    vector[i] = this->datos.frente();
    this->datos.quitar();
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
  return datos.num_elementos();
}

ostream & operator<<(ostream & os,const elemento & a){
 os<<a.ele<< " Máximo: "<<a.maximo;
 return os;
}

ostream & operator<<(ostream & os, const Pila_max & pila){
  Pila_max aux = pila;
  while (!aux.vacia() ){
    elemento x = aux.tope();
    os << x << endl;
    aux.quitar();
  }
  os << endl;

  return os;
}
