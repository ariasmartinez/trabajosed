/**
* @file cantidad_letras.cpp
* @brief Implementación de la función principal del programa cantidad_letras
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#include<fstream>
#include <iostream>
#include "Diccionario.h"
#include "ConjuntoLetras.h"


// diccionario      letras.txt(fichero con las letras permitidas    fich_salida  )
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



  ConjuntoLetras conjunto;
  conjunto.leerDeFichero(argv[2]);
  ConjuntoLetras auxiliar;
  for (set<Letra>::iterator it = conjunto.begin(); it != conjunto.end(); it++){
    Letra aux((*it).Caracter(),0,0);
    auxiliar.insert(aux);
  }
  conjunto=auxiliar;

  D.buscarFrecuenciaLetras(conjunto);
  conjunto.CalcularPorcentaje();
  conjunto.salvarFrecuenciasAFichero(argv[3]);


}
