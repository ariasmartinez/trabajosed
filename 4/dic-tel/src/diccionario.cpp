

#include <iostream>
#include <string>
#include <list>
#include "diccionario.h"


//todas estas cosas vienen del diccionario.h que lo he separado

using namespace std;

template <class T, class U>
Diccionario<T,U>::Diccionario(){}

template <class T, class U>
Diccionario<T,U>::Diccionario(list<data<T,U> > datos){
	//datos = datos;
}

template <class T, class U>
Diccionario<T,U>::Diccionario(const Diccionario &D){
	 Copiar(D);
}

template <class T, class U>
Diccionario<T,U>::~Diccionario(){}

template <class T, class U>
Diccionario<T,U> & Diccionario<T,U>::operator=(const Diccionario<T,U> &D){
	 if (this!=&D){
		 Borrar();
		 Copiar(D);
	  }
	 return *this;
 }

template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
			  
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

template <class T, class U>
 void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
			   
	typename list<data<T,U> >::iterator it;
		     
	 if (!Esta_Clave(clave,it)){
		  data<T,U> p;
	          p.clave = clave;
	          p.info_asoci=info;
			 
	          datos.insert(it,p);
			      	 
	  }
		     
 }

template <class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
	 typename list<data<T,U> >::iterator it;
			   
	 if (!Esta_Clave(p,it)){
		 datos.insert(it,p);
	 }	    
			   
			    //Insertamos el siginificado al final
	 (*it).info_asoci.insert((*it).info_asoci.end(),s);
 }


template <class T, class U>
 list<U>  Diccionario<T,U>::getInfo_Asoc(const T & p) {
	typename list<data<T,U> >::iterator it;
			   
	if (!Esta_Clave(p,it)){
		return list<U>();
	 }
	else{
		return (*it).info_asoci;
	 }
}		

template <class T, class U>
int Diccionario<T,U>::size()const{
	return datos.size();
}


template <class T, class U>
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){
	  
	list<data<string,string> >::const_iterator it;
	  
	for (it=D.begin(); it!=D.end(); ++it){
	  
		list<string>::const_iterator it_s;
		    
		 os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		 for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			os<<(*it_s)<<endl;
		 }
		 os<<"**************************************"<<endl;
	  }
	  
	return os;
}

template <class T, class U>
istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave); 
		    
		    int ns;
		    is>>ns; 
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
			      
			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);		      
		    
	  }
	  D=Daux;
	  return is;
}

template <class T, class U>
void Diccionario<T,U>::EscribeSigni(const list<string>&l){		 
	  list<string>::const_iterator it_s;
	  
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}	
//no se si esto va así
template <class T, class U>
typename list<data<T,U> >::iterator & Diccionario<T,U>::begin(){
	return datos.begin();
}
template <class T, class U>
typename list<data<T,U> >::iterator &Diccionario<T,U>::end(){
		return datos.end();
}
template <class T, class U>		 
typename list<data<T,U> >::const_iterator & Diccionario<T,U>::begin()const{
	return datos.begin();
}
template <class T, class U>
typename list<data<T,U> >::const_iterator &Diccionario<T,U>::end()const {
	return datos.end();
}
			   

template class Diccionario<int,int>;
template class Diccionario<int, string>;
template class Diccionario<string,string>;


