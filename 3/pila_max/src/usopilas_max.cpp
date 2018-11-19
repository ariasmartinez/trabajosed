#include <iostream>
#include "Pila_max.h"

using namespace std;

int main(){
  Pila_max p;
  int i;
  for(i=10; i>=0; i--){
    p.poner(i);
  }
  cout << p;

  return 0;
}
