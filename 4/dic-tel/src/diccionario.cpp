

#include <iostream>
#include <string>
#include <list>
#include "diccionario.h"


//todas estas cosas vienen del diccionario.h que lo he separado

using namespace std;


Diccionario::Diccionario(){}

Diccionario(lista<data<T,U> > datos){}

Diccionario::Diccionario(const Diccionario &D){
	 Copiar(D);
}

Diccionario::~Diccionario();

Diccionario<T,U> & Diccionario::operator=(const Diccionario<T,U> &D){
	 if (this!=&D){
		 Borrar();
		 Copiar(D);
	  }
	 return *this;
 }

bool Diccionario::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
			  
	 if (datos.size()>0){
				    
		typename list<data<T,U> >::iterator it;
			      
		for (it=datos.begin(); it!=datos.end() ;++it){
			if ((*it).clave==p) {
				it_out=it;
				return true;
			}
			else if ((*it).clave>p){
				it_out=it;
			        return false;
			}	  
					   
	        }
			      
		it_out=it;
		return false;
	 }
  	 else {	
		 it_out=datos.end();
		 return false;
	}	    
 }


 void Diccionario::Insertar(const T& clave,const list<U> &info){
			   
	typename list<data<T,U> >::iterator it;
		     
	 if (!Esta_Clave(clave,it)){
		  data<T,U> p;
	          p.clave = clave;
	          p.info_asoci=info;
			 
	          datos.insert(it,p);
			      	 
	  }
		     
 }


void Diccionario::AddSignificado_Palabra(const U & s ,const T &p){
	 typename list<data<T,U> >::iterator it;
			   
	 if (!Esta_Clave(p,it)){
		 datos.insert(it,p);
	 }	    
			   
			    //Insertamos el siginificado al final
	 (*it).info_asoci.insert((*it).info_asoci.end(),s);
 }



 list<U>  Diccionario::getInfo_Asoc(const T & p) {
	typename list<data<T,U> >::iterator it;
			   
	if (!Esta_Clave(p,it)){
		return list<U>();
	 }
	else{
		return (*it).info_asoci;
	 }
}		


int Diccionario::size()const{
	return datos.size();
}


//no se si esto va así

typename list<data<T,U> >::iterator & Diccionario::begin(){
	datos.begin();
}
typename list<data<T,U> >::iterator &Diccionario::end(){
		datos.end();
}
		 
typename list<data<T,U> >::const_iterator & Diccionario::begin()const{
	datos.begin();
}
typename list<data<T,U> >::const_iterator &Diccionario::end()const {
	datos.end();
}
			   
			

