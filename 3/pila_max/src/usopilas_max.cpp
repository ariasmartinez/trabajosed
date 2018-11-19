#include <iostream>
#include "Pila_max.h"

using namespace std;

int main(){
  Pila_max p;
  int i=1;
  //for(i=10; i>=0; i--){
  //  p.poner(i);
  //}
  while(i!=0){
    cin >> i ;
    p.poner(i);
    cout << p;
  }
  /*p.poner(2);
  p.poner(6);
  p.poner(1);
  */
  cout << p;

  return 0;
}
