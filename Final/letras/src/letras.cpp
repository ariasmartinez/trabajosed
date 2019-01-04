
#include "Diccionario.h"
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"
#include <set>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
// No nos van a contratar en google eso lo tenemos claro
//parametros :  fich_diccionario     letras.txt(letras con la cantidad y los puntos)     nºletras     modalidad del juego(L o P)

bool EstaSeleccionados(const multiset<char> & seleccionados, string solucion);

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
  fich_diccionario >> D;



  int num_letras = atoi(argv[3]);
  string mod = argv[4];
  char modalidad = mod[0];

  if(modalidad != 'L' && modalidad != 'P'){
    cerr << "Error en la modalidad" << endl;
    return -1;
  }


  ConjuntoLetras conj_letras;
  string solucion;
  char respuesta = 's';

  if (conj_letras.leerDeFichero(argv[2]) != true){
    cout << "Error cargando los datos de " << argv[2] << " en ConjuntoLetras." << endl;
    exit(-1);
  }

  multiset<char> seleccionadas;
  BolsaLetras bolsa (conj_letras);


  while(respuesta == 's'){

    seleccionadas = bolsa.seleccionaAleatorio(num_letras);

    cout << "Las letras seleccionadas son: " ;
    for(multiset<char>::iterator it=seleccionadas.begin(); it!=seleccionadas.end(); it++){
      cout << (*it) << " ";
    }
    cout << endl;
    cout << "Dime tu solucion: " << endl;
    cin >> solucion;
    cout << "Tu solución es: " << solucion << endl;

    if(!EstaSeleccionados(seleccionadas,solucion))
      cout << "Esa palabra no se puede formar con las letras seleccionadas" << endl;
    else if(!D.Esta(solucion))
      cout << "Dicha palabra no se encuentra en el diccionario" << endl;
    else if(modalidad == 'L')
      cout << "Tu puntuación es de: " << solucion.size() << " puntos" << endl;
    else
      cout << "Tu puntuación es de: " << conj_letras.Puntuacion(solucion) << " puntos" << endl;


    cout << endl << "¡Ahora me toca a mi! :)" << endl;
    cout << "Mis soluciones son: " << endl;
    pair<int, set<string> > soluciones = conj_letras.MejoresPalabras(D.SacarPalabras(seleccionadas), modalidad);
    for (set<string>::iterator it= soluciones.second.begin(); it != soluciones.second.end(); it++){
      cout << (*it) << endl;
    }

    cout << "Con una puntuación de: " << soluciones.first << endl;



    cout << "¿Quieres seguir jugando? (responde s para sí)" << endl;
    cin >> respuesta;
  }
  fich_diccionario.close();
  return 0;
}



bool EstaSeleccionados(const multiset<char> & seleccionadas, string solucion){
    bool esta = true;
    if (solucion.size() <= seleccionadas.size()){
      multiset<char> aux = seleccionadas;
      for(int i=0; i<solucion.size()&& esta; i++){
        multiset<char>::iterator iter = aux.find(solucion[i]);
        if(iter != aux.end())
          aux.erase(iter);
        else
          esta =false;
      }
    }
    else esta = false;

      return esta;

}
