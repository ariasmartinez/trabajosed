#include<list>
#ifndef _DATA_H
#define _DATA_H
using namespace std;
template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;

    
 };
template <class T, class U>
bool operator< (const data<T,U> &d1, const data<T,U> &d2);
#endif
