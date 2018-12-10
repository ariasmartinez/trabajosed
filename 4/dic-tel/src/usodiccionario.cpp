#include <iostream>
#include "diccionario.h"
#include <string>
#include <list>
using namespace std;


/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(){
	Diccionario<string,string> D;

	cin>>D;
	cout<<D;

	cout << "Menu de diccionario: " << endl;
	cout << "		1.Introduce 1 para buscar una palabra en el diccionario." << endl;
	cout << "		2.Introduce 2 para aniadir una nueva palabra al diccionario. "<< endl;
	cout << "		3.Introduce 3 para aniadir un significado a una palabra." << endl;
	cout << "		4.Introduce 4 para borrar un significado de una palabra." << endl;
	cout << "		5.Introduce 5 para buscar todas las palabras que empiecen por una letra." << endl;
	cout << "		6.Introduce 6 para buscar una palabra por su significado." << endl;

	int opcion=3;
	while(opcion!=0){
		cin >> opcion;
		switch (opcion) {
			case 1:
			  {
					string palabra;
					cout << "Introduce una palabra para ver si está en el diccionario"<< endl;
					cin >> palabra;
					cout << "Palabra introducida: " << palabra << endl;

					bool esta_palabra;
					list<data<string,string> > :: iterator it;
					esta_palabra = D.Esta_Clave(palabra, it);
					if (esta_palabra){
						list<string> lista_palabra;
						lista_palabra = D.getInfo_Asoc(palabra);
						D.EscribeSigni(lista_palabra);
					}
					else{
						cout << "La palabra " << palabra << " no se encuentra en el diccionario." << endl;
					}
			  }
				break;
			case 2:
				{
					string palabra_nueva;
					char sig_palabra[500] ;
					list<string> lista_nueva;
					cout << "Dime la palabra que quieres introducir: " << endl;
					cin >> palabra_nueva;
					cout << "Dime ahora el significado de la palabra: " << endl;
					cin.ignore();
					cin.getline(sig_palabra, 500);
					cout << sig_palabra << endl;

					lista_nueva.push_back(sig_palabra);


					D.Insertar(palabra_nueva, lista_nueva);
					cout << "La palabra insertada es " << palabra_nueva << " y el diccionario nuevo es: " << endl;
					cout << D;
				}
				break;
			case 3:
				{
					string palabra_nueva2;
					char sig_palabra2[500];
					cout << "Dime la palabra sobre la cual quieres aniadir un significado: " << endl;
					cin >> palabra_nueva2;
					cout << "Dime el significado de esa palabra: "<< endl;
					cin.ignore();
					cin.getline(sig_palabra2, 500);
					D.AddSignificado_Palabra(sig_palabra2, palabra_nueva2);
					cout << "El nuevo diccionario es: " << endl;
					cout << D;
				}
				break;
			case 4:
				{
					string palabra_delete;
					char sig_delete[500];
					cout << "Introduce la palabra que quieres borrar: " << endl;
					cin >> palabra_delete;
					cout << "Introduce el significado que quieres borrar: " << endl;
					cin.ignore();
					cin.getline(sig_delete, 500);
					D.borrarSignificadoPalabra(sig_delete, palabra_delete);
					cout << D;
				}
				break;
			case 5:
				{
					char letra;
					cout << "Introduce la letra por la que quieres buscar:" << endl;
					cin >> letra;
					D.EscribeLetra(letra);
				}
				break;
			case 6:
				{
					char significado[500];
					cout << "Introduce el significado: " << endl;
					cin.ignore();
					cin.getline(significado, 500);
					D.buscarPorSignificado(significado);
				}
				break;
		}
}






/*	string a;

	cout<<"Introduce una palabra"<<endl;
	cin>>a;

	list<string>l=D.getInfo_Asoc(a);

	if (l.size()>0){}
		  D.EscribeSigni(l);
*/
}
