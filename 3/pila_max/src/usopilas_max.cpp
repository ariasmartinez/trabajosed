/*
  @file usopilas_max.cpp
  @brief main para probar la clase Pila_max
  @authors Lucía Salamanca López
           Celia Arias Martínez
*/

#include <iostream>
#include "Pila_max.h"

using namespace std;

int main(){
  Pila_max p;
  int i=2;
  cout << "Introduce elementos para aniadir a la pila, hasta aniadir el elemento cero:" << endl;
  while(i!=0){
    cin >> i ;
    p.poner(i);
    cout << p;
  }


  return 0;
}
