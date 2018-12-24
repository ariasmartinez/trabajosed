
#include "Diccionario.h"
#include <multiset>
#include <fstream>
#include <iostream>



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

  ifstream fich_letras(argv[2]);
  if (!fich_letras){
    cout << "No se ha podido abrir el fichero " << argv[2] << endl;
    return 0;
  }
  int num_letras = argv[3];
  //¿funciona?
  char modalidad = argv[4];

  BolsaLetras bolsa;
  multiset<char> letras_seleccionadas;
  string solucion;
  char respuesta = 's';
  bolsa.leerDeFichero(fich_letras);

  while(respuesta == 's'){
    letras_seleccionadas = bolsa.seleccionaAleatorio(num_letras);
    //No se si se puede hacer ese cout
    cout << "Las letras seleccionadas son: " << letras_seleccionadas << endl;
    cout << "Dime tu solucion: " << endl;
    cin >> solucion;
    cout << solucion << endl;
    // Calcular la puntuacion (depende de la modalidad)

    //Calcular posibles soluciones y sus puntuaciones

    // Comparar si la solucion personal es correcta y comparar con la mejor, ver si ha ganado


    cout << "¿Quieres seguir jugando? (responde s para sí)" << endl;
    cin >> respuesta;
  }
}
