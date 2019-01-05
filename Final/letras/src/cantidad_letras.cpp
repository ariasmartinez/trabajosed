#include<fstream>
#include <iostream>
#include "Diccionario.h"
#include "ConjuntoLetras"


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
  cout << D;

  ifstream fich_letras_permitidas(argv[2]);
  if (!fich_letras_permitidas){
    cout<<"No puedo abrir el fichero " << argv[2] << endl;
    return 0;
  }

  ifstream fich_salida(argv[3]);
  if (!fich_salida){
    cout<<"No puedo abrir el fichero " << argv[3] << endl;
    return 0;
  }

  ConjuntoLetras conjunto;
  conjunto.leerDeFichero(fich_letras_permitidas);
  ConjuntoLetras:: iterator it;
  for (it = conjunto.begin(); it != conjunto.end(); it++){
    (*it).setCantidad(0);
  }

  D.buscarFrecuenciaLetras(conjunto);
  conjunto.CalcularPorcentaje();
  conjunto.salvarFrecuenciasAFichero(fich_salida);

  
}
