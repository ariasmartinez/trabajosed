#include<fstream>
#include <iostream>
#include "Diccionario.h"
#include "ConjuntoLetras"

int main(int narg, char * argv[]){
  if (narg != 4){
    cout << "Has introducido mal los parámetros." << endl;
    exit(-1);
  }

  ifstream fich_diccionario(argv[1]);
  if (!fich_diccionario){
    cout<<"No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }
  Diccionario D;
  cout << "Cargando diccionario...." << endl;
  fich_diccionario >> D;
  cout << "Leido el diccionario..."<< endl;
  cout << D;

  ifstream fich_letras_permitidas(argv[2]);
  if (!fich_letras_permitidas){
    cout<<"No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }
  ifstream fich_letras_frecuencia;

  ConjuntoLetras conjunto;

  // no se como crear el fichero con las letras permitidas ¿tenemos que hacerlo con alguna funcion?
  // (se le puede pasar un diccionario a leerdeFichero y creo que como esta implementado el metodo lo haria, tambien habria que
// hacer que cree o devuelva un fichero)
//o sea esto ahora mismo solo serviria pa que lo que tenemos en un fichero lo convirtamos en el tipo de dato COnjuntoletras
  conjunto.leerDeFichero(fich_letras_permitidas);

  //ahora habria que ir recorriendo el diccionario y sumando la frecuencia de cada letra (¿se puede hacer en ek mismo COnjuntoLetras?)
//(esto hay que convertirlo en un fichero)


  //asignar puntuaciones (estaria bien tambn convertirlo en un fichero pporque luego hace falta pa letras.cpp)


}
