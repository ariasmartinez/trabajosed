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

	string a;

	cout<<"Introduce una palabra"<<endl;
	cin>>a;

	list<string>l=D.getInfo_Asoc(a);

	if (l.size()>0){}
		  //EscribeSigni(l);

}
