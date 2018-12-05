#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

//he quitado using namespace std

// también pensé poner el data en un fichero aparte pero me rayé porque no se si sería .cpp o .h y lo he dejado asi 

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
// es decir, es una lista de cosas que tienen la misma clave ( la clave y las cosas pueden ser del tipo que sea) ej: clave banco, en la lista está el banco pa sentarse y el banco del dinero   (no?)
template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;
 };

template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}	   

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/


template <class T,class U>
class Diccionario{
	  private:
		    list<data<T,U> > datos;
 			

	            void Copiar(const Diccionario<T,U>& D){
			   /*typename list<data<T,U> >::const_iterator it_d;
			   typename list<data<T,U> >::iterator it=this->datos.begin();*/
			   
			   datos.assign(D.datos.begin(),D.datos.end());
			   /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				     this->datos.insert(it,*it_d);
				     
			   }*/
		    }
		    
		    void Borrar(){
			       
			      this->datos.erase(datos.begin(),datos.end());
		    }	      


 	public:

		 Diccionario();
		// estaba puesto esto Diccionario():datos(list<data<T,U> >()){}

		 Diccionario(lista<data<T,U> > datos);

		Diccionario(const Diccionario &D);

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
		
 		/* Devuelve la información (una lista) asociada a una clave p. Podrían 
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
		list<U>  getInfo_Asoc(const T & p);
	
		/*Devuelve el tamaño del diccionario*/
		int size()const;


 		/*Funciones begin y end asociadas al diccionario*/
		 typename list<data<T,U> >::iterator & begin();
		 typename list<data<T,U> >::iterator &end();
		 
		 typename list<data<T,U> >::const_iterator & begin()const;
		 typename list<data<T,U> >::const_iterator &end()const;
		 	
};

#endif
	 
			   
