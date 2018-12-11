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
		    list<data<T,U> > datos;


				/**
				* @brief Copia el contenido de un diccionario en el objeto this
				* @param D diccionario a  copiar
				*/
	       void Copiar(const Diccionario<T,U>& D){


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

		/**
			@brief Sobrecarga de operador =.
			@param D: Diccionario que queremos Copiar
			@return diccionario copiado
		*/
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

		/**
			@brief borra un significado concreto de una palabra
			@param s: significado que queremos borrar
						 p: palabra que tiene ese significado
		*/
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
		friend ostream & operator<<(ostream & os, const Diccionario<string,string> & D);


		/*Operator >>. El formato de la entrada es:
		     numero de claves en la primera linea
		     clave-iésima retorno de carro
		     numero de informaciones asociadas en la siguiente linea
		     y en cada linea obviamente la informacion asociada
		*/

		friend istream & operator >>(istream & is,Diccionario<string,string> &D);

		/*
			@brief Escribe todos los significados de una palabra
			@param l: palabra cuyos significados queremos imprimir
		*/

		void EscribeSigni(const list<string>&l);

		/**
			@brief Escribe todos los significados de las palabras que empiezan por una letra determinada
			@param c: letra por la que empiezan las palabras
		*/

		void EscribeLetra( const char c);

		/**
			@brief Busca la palabra que contiene un significado
			@param palabra: significado que queremos buscar
		*/
		void buscarPorSignificado(const char *palabra);

		/**
		* @brief Carga un diccionario de un archivo
		* @param fichero Nombre del archivo desde el que se extrae el diccionario
		* @return true si se ha cargado correctamente, false en caso contrario
		*/
		bool cargarDeFichero(const char *fichero);

			//Funciones begin y end asociadas al diccionario*/
		 typename list<data<T,U> >::iterator  begin();
		 typename list<data<T,U> >::iterator end();

		 typename list<data<T,U> >::const_iterator  begin()const;
		 typename list<data<T,U> >::const_iterator end()const;


};



#endif
