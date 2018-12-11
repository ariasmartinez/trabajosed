/**
* @file usoguia.cpp
* @authors Celia Arias Martinez
*		Lucia Salamanca Lopez
*/

#include "guiatlf.h"
#include <iostream>
#include<string>
#include <stdio.h>
using namespace std;

void Menu(){
  cout << " 1.Introduce 1 para mostrar la guia de telefonos." << endl;
  cout << " 2.Introduce 2 para guardar la guia en un fichero llamado ./data/salida.txt" << endl;
  cout << " 3.Introduce 3 para obtener el numero de una persona." << endl;
  cout << " 4.Introduce 4 para insertar un nuevo telefono en la guia." << endl;
  cout << " 5.Introduce 5 para devolver todos los numeros de telefono que empiecen por una letra." << endl;
  cout << " 6.Introduce 6 para devolver todos los numeros de telefono que empiecen por un prefijo." << endl;
  cout << " 7.Introduce 7 para borrar un numero de telefono." << endl;
  cout << " 8.Introduce 8 para hacer la suma de dos guias (solo si hemos pasado las dos como parametros)." << endl;
  cout << " 9.Introduce 9 para hacer la diferencia de dos guias (solo si hemos pasado las dos como parametros)." << endl;
  cout << " Introduce 0 para salir." << endl;
}
int main(int narg, char* argv[]){
  Guia_Tlf g;


  /* Aqui nuestro main. Para ejecutarlo debemos pasarle el fichero por parametros al main. */
  bool cargado;
  bool salvado;
  const char* fichero_salida = "./data/salida.txt";
  cargado = g.cargarDeFichero(argv[1]);
  if (!cargado){
    cout << "Error al cargar la primera guia." << endl;
    exit(-1);
  }
  cout << g;
  cout << endl;

  bool cargado2;
  Guia_Tlf g2;
  if(narg > 2){
    cargado2 = g2.cargarDeFichero(argv[2]);
    if (!cargado2){
      cout << "Error al cargar la segunda guia." << endl;
      exit(-1);
    }
  }

  int opcion = 3;
  while(opcion !=0){
    Menu();
    cin >> opcion;
    switch(opcion){
      case 1:
      {
        cout << g;
      }
      break;
      case 2:
      {
        salvado = g.salvarAFichero(fichero_salida);
        if (!salvado)
          cout << "Error al salvar la guia." << endl;
      }
      break;
      case 3:
      {
        char nombre[500];
        string telefono;
        cout << "Introduce el nombre de la persona que quieres buscar:" << endl;
        cin.ignore();
				cin.getline(nombre, 500);
        telefono = g.gettelefono(nombre);
        if (telefono == "")
          cout << "No existe esa persona en la guia."<< endl;
        else
          cout << "El telefono de " << nombre << " es " << telefono << endl;
      }
      break;
      case 4:
      {
        char nombre[500];
        string numero;
        cout << "Dime el nombre de la persona:" << endl;
        cin.ignore();
				cin.getline(nombre, 500);
        cout << "Dime el numero de telefono:" << endl;
        cin >> numero;
        g.insert(nombre, numero);
      }
      break;
      case 5:
      {
        char letra;
        cout <<"Dime la letra que quieres buscar:" << endl;
        cin >> letra;
        g.EscribeLetra(letra);
      }
      break;
      case 6:
      {
        int prefijo;
        cout << "Dime el prefijo que quieres buscar: " << endl;
        cin >> prefijo;
        g.EscribePrefijo(prefijo);
      }
      break;
      case 7:
      {
        char nombre[500];
        cout << "Dime el nombre de la persona:" << endl;
        cin.ignore();
				cin.getline(nombre, 500);
        g.borrar(nombre);
      }
      break;
      case 8:
        if (narg > 2){
          Guia_Tlf guia_suma;
          guia_suma= g+g2;
          cout << guia_suma;
        }
      break;
      case 9:
        if (narg > 2){
          Guia_Tlf guia_resta;
          guia_resta= g-g2;
          cout << guia_resta;
        }
      break;
      case 0:
        exit(0);
        break;
      default:
        break;
   }
 }
}
