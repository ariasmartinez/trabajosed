
#include "Diccionario.h"
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"
#include <set>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

//parametros :  fich_diccionario     letras.txt(letras con la cantidad y los puntos)     nºletras     modalidad del juego(L o P)


int main(int narg, char * argv[]){
  if (narg != 5){
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

  /* ¿no sirve no?
  ifstream fich_letras(argv[2]);
  if (!fich_letras){
    cout << "No se ha podido abrir el fichero " << argv[2] << endl;
    return 0;
  }
  */
  int num_letras = atoi(argv[3]);
  //¿funciona?
  char modalidad = atoi(argv[4]);


  /*
  BolsaLetras bolsa;
  multiset<char> letras_seleccionadas;
  string solucion;
  char respuesta = 's';
  bolsa.leerDeFichero(fich_letras);
  */

  ConjuntoLetras conj_letras;
  string solucion;
  char respuesta = 's';
  //mirar metodo leerdefichero porque puede fallar
  if (conj_letras.leerDeFichero(argv[2]) != true){
    cout << "Error cargando los datos de " << argv[2] << " en ConjuntoLetras." << endl;
    exit(-1);
  }
  multiset<char> seleccionadas;
  BolsaLetras bolsa (conj_letras);

  while(respuesta == 's'){
    /*
    letras_seleccionadas = bolsa.seleccionaAleatorio(num_letras);
    */
    // lo hemos hecho en bolsa
    seleccionadas = bolsa.seleccionaAleatorio(num_letras);

    cout << "Las letras seleccionadas son: " ;
    for(multiset<char>::iterator it=seleccionadas.begin(); it!=seleccionadas.end(); it++){
      cout << (*it) << " ";
    }
    cout << endl;
    cout << "Dime tu solucion: " << endl;
    cin >> solucion;
    cout << solucion << endl;
    // Calcular la puntuacion (depende de la modalidad)

    if (modalidad == 'L'){
      // cargar los datos de diccionario en un arbol segun la longitud
    }
    else if (modalidad == 'P'){
      // cargar los datos de diccionario en un arbol segun la puntuacion (hay que tener en cuenta ConjuntoLetras)
    }
    else {
      cout << "Has introducido mal la modalidad, los valores son L o P." << endl;
      exit(0);
    }
    //Calcular posibles soluciones y sus puntuaciones

    // Comparar si la solucion personal es correcta y comparar con la mejor, ver si ha ganado


    cout << "¿Quieres seguir jugando? (responde s para sí)" << endl;
    cin >> respuesta;
  }
}
