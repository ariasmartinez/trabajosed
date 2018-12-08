/**
* @file guiatlf.h
* @brief Fichero cabecera del TDA Guia_Tlf
* @authors Celia Arias Martí­nez
*		Lucía Salamanca López
*/
#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;
/**
	@brief Lectura de un objeto pair<string, string>
	@param is: flujo de entrada. ES MODIFICADO
	@param d: objeto pair. ES MODIFICADO
	@return el flujo de entrada
*/
istream & operator>>(istream &is,pair<string,string> &d);

/**
* @class Guia_Tlf
* @brief Una guiaTelf es un contenedor de tipo map formado por una clave de tipo string que representa el nombre del usuario del teléfono y es única para cada uno, y otro string que representa el número de teléfono. Al ser única la clave podemos acceder a cada número de teléfono sabiendo solo el nombre de la persona
*/
class Guia_Tlf{
	  private:
		    map<string,string> datos; //si admites que haya nombres repetidos tendrï¿½as que usar un
					     //multimap

	  public:
			 /**
			  	@brief Constructor por defecto. Crea una guÃ­a de telÃ©fonos vacÃ­a
			 */
		    Guia_Tlf(){}
				/**
				*	@brief Constructor de copia
				* @param gt objeto de la clase que se quiere copiar
				*/
		    Guia_Tlf(const Guia_Tlf & gt);
				/**
				* @brief Destructor de la clase
				*/
		    ~Guia_Tlf(){}
		    Guia_Tlf & operator=(const Guia_Tlf & gt);
		    /**
		      @brief Acceso a un elemento
		      @param nombre: nombre del elemento  elemento acceder
		      @return devuelve el valor asociado a un nombre, es decir el telÃ©fono
		    */
		    string & operator[](const string &nombre) ;

		    /**
				*	@brief Devuelve el telÃ©fono de una persona dada por el nombre
				* @param nombre Nombre de la persona de la que se quiere obtener el telÃ©fono
				* @return devuelve el valor asociado al nombre, es decir el telÃ©fono
				*/
		    string  gettelefono(const string & nombre);

		    /**
		     @brief Insert un nuevo telefono
		     @param nombre: nombre clave del nuevo telefono
		     @param tlf: numero de telefono
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);

		    /**
		     @brief Insert un nuevo telefono
		     @param p: pair con el nombre y el telefono asociado

		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);


		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar
		      @note: en caso de que fuese un multimap borraria todos con ese nombre
		    */
		    void borrar(const string &nombre);

		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar y telefono asociado
		      @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		    */
		    //con map siempre hay uno con multimap puede existir mas de uno
		    void borrar(const string &nombre,const string &tlf);
		    /**
		      @brief  Numero de telefonos
		      @return el numero de telefonos asociados
		     */
		    int size()const{
			      return datos.size();
		    }
		    /**
		      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		      @param nombre: nombre sobre el que queremos consultar
		      @return numero de telefonos asociados a un nombre

		     */
		    //al ser un map debe de ser 0 o 1. Si fuese un multimap podrï¿½amos tener mas de uno
		    unsigned int contabiliza(const string &nombre){
			      return datos.count(nombre);
		    }

		    /**
		      @brief Limpia la guia
		     */
		    void clear(){
			      datos.clear();
		    }
		    /**
		      @brief Union de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de unir el objeto al que apunta this y g
		    */
		    Guia_Tlf operator+(const Guia_Tlf & g);

		    /**
		      @brief Diferencia de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		    */
		    Guia_Tlf operator-(const Guia_Tlf & g);

		    /**
		      @brief Escritura de la guia de telefonos
		      @param os: flujo de salida. Es MODIFICADO
		      @param g: guia de telefonos que se escribe
		      @return el flujo de salida
		     */


		    friend ostream & operator<<(ostream & os, Guia_Tlf & g);

		    /**
		      @brief Lectura de  la guia de telefonos
		      @param is: flujo de entrada. ES MODIFICADO
		      @param g: guia de telefonos. ES MODIFICADO
		      @return el flujo de entrada
		    */

		    friend istream & operator>>(istream & is, Guia_Tlf & g);




};
#endif
