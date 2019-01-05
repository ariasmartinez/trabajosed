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

istream & operator >> (istream & is, ConjuntoLetras & conj){
	Letra let;

	while(is){
    is >> let;
    conj.datos.insert(let);
  }

  return is;
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

		}
    is.close();
		return cond;
}

//estaria bien cogerlas con la probabilidad proporcional a la cantidad que hay (COnjunto de letras es un set ;(
//tambien tener en cuenta que los elementos de COnjunto de letras son Letras y los de bolsa char
/*  BolsaLetras bolsa;
  multiset<char> multiset_bolsa;
  return bolsa;
}
*/

int ConjuntoLetras::Puntuacion(string palabra){
  int puntuacion=0;
  for(int i=0; i<palabra.size(); i++){
    set<Letra>::iterator it =BuscarLetra(palabra[i]);
    if(it!=end()){
      puntuacion+= (*it).Puntuacion();
    }
    else
      return 0;
  }
  return puntuacion;

}

set<Letra>::iterator ConjuntoLetras::BuscarLetra(char letra) const{
  for(set<Letra>::iterator it = begin(); it!= end() && (*it).Caracter() <= letra ; it ++){
    if((*it).Caracter()==letra)
      return it;
  }
  //Esto no se si puede ser la verdad supongo que si
  return end();
}

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

pair<int,set<string> > ConjuntoLetras::MejoresPalabras (const set<string> & palabras, char modo){
  pair<int, set<string> > resultado;
  resultado.first = 0;
  if (modo=='P'){
    for(set<string>::iterator it= palabras.begin(); it!=palabras.end(); it++){
      if (Puntuacion(*it)>resultado.first){
        resultado.second.clear();
        resultado.second.insert((*it));
        resultado.first=Puntuacion(*it);
      }
      else if(Puntuacion(*it)==resultado.first)
        resultado.second.insert((*it));
    }
  }
  else {
    for(set<string>::iterator it= palabras.begin(); it!=palabras.end(); it++){
      if ((*it).size()>resultado.first){
        resultado.second.clear();
        resultado.second.insert((*it));
        resultado.first=(*it).size();
      }
      else if((*it).size()==resultado.first)
        resultado.second.insert((*it));
    }
  }

  return resultado;
}


  bool ConjuntoLetras::salvarFrecuenciasAFichero(const char *fichero){
       bool cond = true;
       ofstream os;
       os.open(fichero);
       if (os){
           os << (*this);
           if (!os){
               cout << "Error cargando los datos al fichero" << fichero << endl;
               cond=false;
           }
           os.close();
       }
       else {
           cout << "Error de apertura del fichero " << fichero << endl;
           cond =false;
       }
       os.close();
       return cond;
  }

  void ConjuntoLetras::CalcularPorcentaje(){
    int total = 0;
    int porcentaje;
    for (set<Letra>:: iterator it = datos.begin(); it != datos.end(); it++){
      total = total + (*it).Cantidad();
    }
    for (set<Letra>:: iterator itb = datos.begin(); itb != datos.end(); itb++){
      porcentaje = ((*itb).Cantidad()/total)*100;
      (*itb).setPuntuacion(porcentaje);
    }
  }
