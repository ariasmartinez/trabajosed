/**
* @file BolsaLetras.h
* @brief Fichero cabecera del TDA BolsaLetras
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _BolsaLetras_h
#define _BolsaLetras_h
#include <set>


using namespace std;

class BolsaLetras{
private:
  multiset<char> datos;

public:
  BolsaLetras(){};

  BolsaLetras(multiset<char> dat);

  int size(){
    return datos.size();
  }

//  multiset<char> seleccionaAleatorio(int cantidad);

  // tambien habia pensado ponerlo como constructor
  bool leerDeFichero(const char *fichero);

  friend istream & operator>>(istream & is,BolsaLetras & bolsa);

  friend ostream & operator<<(ostream & os, const BolsaLetras &bolsa);
};

#endif
