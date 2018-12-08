/**
* @file diccionario.h
* @brief Fichero cabecera del TDA Diccionario
* @authors Celia Arias Martínez
*          Lucía Salamanca López
*/
#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>
#include "data.h"

using namespace std;


/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
// es decir, es una lista de cosas que tienen la misma clave ( la clave y las cosas pueden ser del tipo que sea) ej: clave banco, en la lista está el banco pa sentarse y el banco del dinero   (no?)



/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/

/**
* @class Diccionario
* @brief Representa un diccionario
*/
template <class T,class U>
class Diccionario{
	  private:
		    list<data<T,U> > datos; ///<Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave de tipo T. El diccionario está ordenado de menor a mayor clave.


				/**
				* @brief Copia el contenido de un diccionario en el objeto this
				* @param D diccionario a  copiar
				*/
	       void Copiar(const Diccionario<T,U>& D){

					//
			   /*typename list<data<T,U> >::const_iterator it_d;
			   typename list<data<T,U> >::iterator it=this->datos.begin();*/

			      datos.assign(D.datos.begin(),D.datos.end());
			   /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				     this->datos.insert(it,*it_d);

			   }*/
		     }
				/**
				* @brief Borra los elementos del diccionario
				*/
		    void Borrar(){
			      datos.erase(datos.begin(),datos.end());
		    }


 	public:
		/**
		* @brief Constructor por defecto, crea un diccionario vacío
		*/
		Diccionario();
		// estaba puesto esto Diccionario():datos(list<data<T,U> >()){}
		/**
		* @brief Constructor a partir de una lista de datos
		* @param dat lista de datos a partir de la cual se crea el diccionario
		*/
		Diccionario(list<data<T,U> > dat);
		/**
		* @brief Constructor de copia
		* @param D objeto de la clase que se quiere copiar
		*/
		Diccionario(const Diccionario &D);
		/**
		* @brief Destructor de la clase
		*/
 		~Diccionario();

		Diccionario<T,U> & operator=(const Diccionario<T,U> &D);

		/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
		bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out);

		 /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
		 e inserta la lista con toda la información asociada a esa clave. Si el
		 diccionario no estuviera ordenado habría que usar la función sort()
		 */
		void Insertar(const T& clave,const list<U> &info);

		/*Añade una nueva informacion asocida a una clave que está en el diccionario.
		 la nueva información se inserta al final de la lista de información.
                  Si no esta la clave la inserta y añade la informacion asociada.
		 */
		void AddSignificado_Palabra(const U & s ,const T &p);

		void borrarSignificadoPalabra (const U &s, const T &p);

 		/* Devuelve la información (una lista) asociada a una clave p. Podrían
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
		list<U>  getInfo_Asoc(const T & p);

		/*Devuelve el tamaño del diccionario*/
		int size()const;


		/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
		listas de listas y otro sobre listas
		*/
		//lo ponemos friend?
		friend ostream & operator<<(ostream & os, const Diccionario<string,string> & D);


		/*Operator >>. El formato de la entrada es:
		     numero de claves en la primera linea
		     clave-iésima retorno de carro
		     numero de informaciones asociadas en la siguiente linea
		     y en cada linea obviamente la informacion asociada
		*/

		friend istream & operator >>(istream & is,Diccionario<string,string> &D);


		/*Recorre la lista de información asociada a una clave y la imprime*/
		void EscribeSigni(const list<string>&l);

		/* Imprime la informacion asociada a claves que empiezan por esa letra*/
		void EscribeLetra( const char c);
 		//Funciones begin y end asociadas al diccionario*/
		 typename list<data<T,U> >::iterator  begin();
		 typename list<data<T,U> >::iterator end();

		 typename list<data<T,U> >::const_iterator  begin()const;
		 typename list<data<T,U> >::const_iterator end()const;

};


/*
	 TRABAJO: añadir 3 metodos más.
	 RESUMEN de las cosas que sabemos hacer (no sabemos si están bien implementadas):
		Copiar diccionarios
		Borrar diccionarios
		Crear diccionarios
		Buscar una clave en el diccionario (y devolver un iterador a esa clave)
		Insertar un nuevo registro en el diccionario (clave)
		Insertar un nuevo elemento a la lista de alguna clave (add_significado_palabra)
		Devolver la lista asociada a una clave
		Tamaño de diccionario
		Iterador al principio y final del diccionario
		>> (leer de un fichero)
		<< (escribir en fichero)
		Escribir la lista asociada a una clave

	AÑADIDOS por nosotras (o en proceso):
		sort ( para  ordenar el diccionario)
		borrarSignificadoPalabra (para borrar una entrada de una clave)
		buscarPorPalabra (poner una palabra y que te diga las claves en las que está)

		etc
*/

#endif
