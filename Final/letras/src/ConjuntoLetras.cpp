/**
* @file ConjuntoLetras.cpp
* @brief Implementación del TDA ConjuntoLetras
* @authors Celia Arias Martínez
*		       Lucía Salamanca López
*/
#include <iostream>
#include <fstream>
#include "BolsaLetras.h"
#include "ConjuntoLetras.h"
#include "Letra.h"


using namespace std;


ConjuntoLetras::ConjuntoLetras(set<Letra> dat){
  datos = dat;
}


istream & operator>>(istream & is,ConjuntoLetras & conj){
  Letra letra_aux;
  /*char char_letra;
  char cantidad_char;
  int cantidad;
  char puntuacion_char;
  int puntuacion;
  char basura;
  while(is.get(char_letra)){
    is.get(basura);
    is.get(cantidad_char);
    is.get(basura);
    is.get(puntuacion_char);
    //is.get(basura);
    cantidad = cantidad_char +'0';
    puntuacion = puntuacion_char +'0';
    cout << "aniadimos letra " << char_letra << endl;
    cout << "aniadimis cantidad_char " << cantidad_char << endl;
    cout << "aniadimos puntuacion_char "<< puntuacion_char << endl;
    letra_aux.setCaracter(char_letra);
    letra_aux.setCantidad(cantidad);
    letra_aux.setPuntuacion(puntuacion);
    //Letra letra_aux(char_letra, cantidad, puntuacion);
    cout << "conjuntoletra::>>::vamos a anidir " << letra_aux << endl;
    conj.datos.insert(letra_aux);
  }*/
  /*
  string linea;
  char char_letra;
  char canti;
  char punt;
  int puntuacion;
  int cantidad;
  int nivel = 0;
  string aux;
  getline(is, linea);
  while(!is.eof()){
    for (int i=0; i<linea.size(); i++){
      if(linea[i] != " "){
        aux = linea[i];
      }
      else{
        if (nivel == 0){
          char_letra = aux;
          aux.clear();
          nivel++;
        }
        else if(nivel == 1){
          canti = aux;
          aux.clear();
          nivel++;
        }
        else if (nivel == 2){
          punt = aux;
          aux.clear();
          nivel = 0;
        }
      }
    }
    cantidad = canti +'0';
    puntuacion = punt +'0';
    letra_aux.setCaracter(char_letra);
    letra_aux.setCantidad(cantidad);
    letra_aux.setPuntuacion(puntuacion);
    conj.datos.insert(letra_aux);
  }

  return is;*/
}



ostream & operator<<(ostream & os, const ConjuntoLetras &conj){
  set<Letra> ::iterator it;
  for (it = conj.datos.begin(); it != conj.datos.end(); it++)
    os << (*it) << endl;
  return os;
}

bool ConjuntoLetras::leerDeFichero(const char *fichero){
		bool cond=true;
		ifstream is;
		is.open(fichero);
		if(is){
				is >> (*this);
				is.close();
		}
		else{
				cout << "Error de apertura del fichero " << fichero << endl;
				cond=false;
        is.close();
		}
		return cond;
}

//estaria bien cogerlas con la probabilidad proporcional a la cantidad que hay (COnjunto de letras es un set ;(
//tambien tener en cuenta que los elementos de COnjunto de letras son Letras y los de bolsa char
/*  BolsaLetras bolsa;
  multiset<char> multiset_bolsa;
  return bolsa;
}
*/
typename set<Letra>::iterator ConjuntoLetras::begin(){
  return datos.begin();
}

typename set<Letra>::iterator ConjuntoLetras::end(){
  return datos.end();
}

typename set<Letra>::const_iterator ConjuntoLetras::begin() const{
  return datos.begin();
}

typename set<Letra>::const_iterator ConjuntoLetras::end() const{
  return datos.end();
}
