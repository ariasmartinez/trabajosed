/**
* @file data.cpp
* @authors Celia Arias Martínez
*          Lucía Salamanca López
*/

#include<list>
#include <string>
#include"data.h"

using namespace std;


template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}

template struct data<string, string>;
