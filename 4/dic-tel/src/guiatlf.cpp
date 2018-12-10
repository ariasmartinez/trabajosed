#include "guiatlf.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

istream & operator>>(istream &is,pair<string,string> &d){

	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}

Guia_Tlf::Guia_Tlf(const Guia_Tlf & gt){

}

Guia_Tlf & Guia_Tlf::operator=(const Guia_Tlf & gt){

	if(&gt != this){
    this->datos = gt.datos;
  }

  return *this;

}

string & Guia_Tlf::operator[](const string &nombre) {
			      return datos[nombre];
}

string Guia_Tlf::gettelefono(const string & nombre){
  map<string,string>::iterator it=datos.find(nombre);
	if (it==datos.end())
		return string("");
	else
    return it->second;
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(string nombre, string tlf){
  pair<string,string> p (nombre,tlf);
  pair< map<string,string> ::iterator,bool> ret;

  ret=datos.insert(p);
	return ret;
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(pair<string,string> p){

  pair<map<string,string> ::iterator,bool> ret;

  ret=datos.insert(p);
  return ret;

}

void Guia_Tlf::EscribeLetra(const char c)const{
	map<string,string>::const_iterator it;
	bool fin=false, hay=false;
	for(it= datos.cbegin(); it!=datos.cend() && !fin; it++){
		if((*it).first[0]==c){
			hay = true;
			cout << (*it).first << " " << (*it).second << endl;
		}
		else if((*it).first[0]>c)
			fin = true;
	}

	if(!hay)
		cout << "No existen nombres que empiecen por la letra " << c << endl;

}

void Guia_Tlf::EscribePrefijo(const int pre)const{
	map<string,string>::const_iterator it;
	int num;

	bool hay=false;
	for(it = datos.cbegin(); it != datos.cend(); it ++){
		num =stoi((*it).second);
		num = num/1000000;
		if(num == pre){
			hay = true;
			cout << (*it).first << " " << (*it).second << endl;
		}
	}
	if(!hay){
		cout << "No existen números con dicho prefijo." << endl;
	}
}


void Guia_Tlf::borrar(const string &nombre){
  map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
  map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
  datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
  map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
  map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
  map<string,string>::iterator it;
  bool salir =false;
  for (it=itlow; it!=itupper && !salir;++it){
      if (it->second==tlf){
  		  datos.erase(it);
  			salir =true;
			}
	}

}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
  Guia_Tlf aux(*this);
  map<string,string>::const_iterator it;
  for (it=g.datos.begin();it!=g.datos.end();++it){
    aux.insert(it->first,it->second);
	}
	return aux;
}


Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string,string>::const_iterator it;
			for (it=g.datos.begin();it!=g.datos.end();++it){
			   aux.borrar(it->first,it->second);
			}
			return aux;
}

ostream & operator<<(ostream & os, Guia_Tlf & g){
  map<string,string>::iterator it;
	for (it=g.datos.begin(); it!=g.datos.end();++it){
		os<<it->first<<"\t"<<it->second<<endl;
	}
	return os;
}

istream & operator>>(istream & is, Guia_Tlf & g){
	pair<string,string> p;
	Guia_Tlf aux;

	while (is>>p){
		aux.insert(p);
	}
	g=aux;
	return is;
}
