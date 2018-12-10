#include "guiatlf.h"
#include <iostream>

using namespace std;

void Menu(){
  cout << " 1.Introduce 1 para mostrar la guia de telefonos." << endl;
  cout << " 2.Introduce 2 para guardar la guia en un fichero llamado ./data/salida.txt" << endl;
  cout << " Introduce 0 para salir." << endl;
}
int main(int narg, char* argv[]){
  Guia_Tlf g;


  /* Aqui nuestro main */
  bool cargado;
  bool salvado;
  const char* fichero_salida = "./data/salida.txt";
  cargado = g.cargarDeFichero(argv[1]);
  if (!cargado){
    cout << "Error al cargar la primera guia." << endl;
    exit(-1);
  }


  int opcion = 3;
  while(opcion !=0){
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
   }
 }





/*
 //cout<<"La guia insertada "<<g<<endl;
 cin.clear();
// cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;
/* while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }
 cin.clear();
 cout<<"Dime el nombre que quieres borrar"<<endl;

 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }

 cout<<"Dime el nombre que quieres borrar"<<endl;

 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }
 */
 /*
 cin.clear();
 Guia_Tlf otraguia;
 cout<<"Introduce otra guia"<<endl;

 cin>>otraguia; cin.clear();
 Guia_Tlf un = g+otraguia;
 Guia_Tlf dif = g-otraguia;

 cout<<"La union de las dos guias: "<<endl <<un<<endl;

 cout<<"La diferencia de las dos guias:"<<endl <<dif<<endl;

 */

}
