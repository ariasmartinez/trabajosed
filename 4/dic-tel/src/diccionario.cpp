/**
* @file diccionario.cpp
* @brief Implementación del TDA diccionario
* @authors Celia Arias Martínez
*          Lucía Salamanca López
*/

#include <iostream>
#include <string>
#include <list>
#include "diccionario.h"
#include <stdio.h>
#include <string.h>
#include <fstream>


using namespace std;

template <class T, class U>
Diccionario<T,U>::Diccionario(){}

template <class T, class U>
Diccionario<T,U>::Diccionario(list<data<T,U> > dat){
	datos.assign(datos.begin(), datos.end());
}

template <class T, class U>
Diccionario<T,U>::Diccionario(const Diccionario &D){
	 Copiar(D);
}

template <class T, class U>
Diccionario<T,U>::~Diccionario(){
	datos.clear();
}

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

		 data<T,U> dat;
		 dat.clave = p;
		 dat.info_asoci.clear();
		 dat.info_asoci.push_back(s);
	   datos.insert(it,dat);

	 }
	 else {
		 (*it).info_asoci.push_back(s);
	 }
}

template <class T, class U>
void Diccionario<T,U>::borrarSignificadoPalabra(const U &s, const T &p){
	typename list<data<T,U> >::iterator it;
	if (Esta_Clave(p,it)){
		bool esta = false;
		for(typename list<U>::iterator it2 = (*it).info_asoci.begin(); it2!=(*it).info_asoci.end() && !esta; it2++){
			if((*it2) == s){
				if((*it).info_asoci.size()>1)
					(*it).info_asoci.erase(it2);
				else
					datos.erase(it);
				esta = true;
			}
		}
		if (!esta){
			cout << "No existe dicho significado" << endl;
		}
	}
	else
		cout << "No existe dicha palabra" << endl;
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

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave);

		    int ns;
		    is>>ns;
		    is.ignore();
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
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

template <class T, class U>
void Diccionario<T,U>::EscribeLetra(const char c){
	if (datos.size()>0){
	 bool fin =false;
	 bool escrito=false;
	 typename list<data<T,U> >::iterator it;

	 for (it=datos.begin(); it!=datos.end() && !fin ;++it){
			 if ((*it).clave[0]==c) {
				 cout << (*it).clave << ":"<< endl;
				 EscribeSigni((*it).info_asoci);
				 escrito = true;
			}
			 else if ((*it).clave[0]>c){
					fin =true;
			 }
	 }

	 if (!escrito){
		 cout << "No hay ninguna entrada que empiece por esa letra" << endl;
	 }

}
}

template <class T, class U>
void Diccionario<T,U>::buscarPorSignificado(const char* sig_palabra){
	typename list<data<T,U> >:: iterator it_dic;
	bool encontrada = false;
	for (it_dic = datos.begin(); it_dic != datos.end(); it_dic++){
		typename list<U> :: iterator it_sig;
		for (it_sig = (*it_dic).info_asoci.begin(); it_sig != (*it_dic).info_asoci.end(); it_sig++){
			const char * sig_prov = (*it_sig).c_str();
			if (strcmp(sig_palabra, sig_prov) == 0){
				encontrada = true;
				cout << (*it_dic).clave << endl;
			}
		}
	}
	if (!encontrada)
		cout << "No existen palabras con ese significado." << endl;
}
template <class T, class U>
bool Diccionario<T,U>::cargarDeFichero(const char *fichero){
    bool cond=true;
    ifstream is;
    is.open(fichero);
    if(is){
        is >> (*this);
        is.close();
    }
    else{
        cout << "Error de apertura del fichero " << fichero << endl;
        cond=false;
    }
    return cond;
}

template <class T, class U>
typename list<data<T,U> >::iterator  Diccionario<T,U>::begin(){
	return datos.begin();
}
template <class T, class U>
typename list<data<T,U> >::iterator Diccionario<T,U>::end(){
		return datos.end();
}
template <class T, class U>
typename list<data<T,U> >::const_iterator  Diccionario<T,U>::begin()const{
	return datos.begin();
}
template <class T, class U>
typename list<data<T,U> >::const_iterator Diccionario<T,U>::end()const {
	return datos.end();
}


template class Diccionario<string,string>;
