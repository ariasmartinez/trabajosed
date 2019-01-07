/**
* @file ConjuntoLetras.h
* @brief Fichero cabecera del TDA ConjuntoLetras
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _ConjuntoLetras_h
#define _ConjuntoLetras_h
#include <set>
#include <string>
#include "Letra.h"
#include <utility>


using namespace std;

class ConjuntoLetras {
private:
  set<Letra> datos;

public:
  /**
  * @brief Constructor por defecto
  */
  ConjuntoLetras(){}
  /**
  * @brief Constructor a partir de un set<Letra>
  * @param dat set<Letra> a partir del cual se forma el ConjuntoLetras
  */
  ConjuntoLetras(set<Letra> dat);
  /**
  * @brief Devuelve el tamaño del conjunto
  * @return Devuelve un entero con el número de objetos Letra que hay
  */
  int size(){
    return datos.size();
  }
  /**
  * @brief lee el ConjuntoLetras de un fichero
  * @param fichero nombre del fichero que queremos leer
  */
  bool leerDeFichero(const char *fichero);
  /**
  * @brief Guarda el ConjuntoLetras en un Fichero
  * @param fichero nombre del fichero
  * @return true si se ha guardado correctamente, false en caso contrario
  */
  bool salvarFrecuenciasAFichero(const char *fichero);

  /**
  @brief Lee de un flujo de entrada un conjunto de letras
  @param is:flujo de entrada
  @param conj: el objeto donde se realiza la lectura.
  @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is,ConjuntoLetras & conj);
  /**
  @brief Escribe en un flujo de salida un conjunto de letras
  @param os:flujo de salida
  @param let: el objeto ConjuntoLetras que se escribe
  @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const ConjuntoLetras &conj);
  /**
  * @brief Devuelve un iterador apuntando a la letra cuyo caracter es la letra pasada por argumento
  * @param letra char cuya Letra queremos buscar
  * @return Un iterador a la Letra con el caracter letra o end() si no existe dicha letra
  */
  set<Letra>::iterator BuscarLetra(char letra) const;
  /**
  * @brief Borra una letra del conjunto
  * @param let Letra a borrar
  */
  void erase(set<Letra>::iterator it){
    datos.erase(it);
  }
  /**
  * @brief Inserta una letra en el conjunto
  * @param let Letra a insertar
  */
  void insert(const Letra & let){
    datos.insert(let);
  }
  /**
  * @brief Operador de asignación
  * @param conj ConjuntoLetras al que queremos igualar this
  * @return referencia al objeto de la clase
  */
  ConjuntoLetras & operator=(const ConjuntoLetras & conj){
    datos= conj.datos;
    return *this;
  }
  /**
  * @brief Devuelve la puntuación de la palabra pasada por argumento
  * @param palabra string del cual se quiere obtener la puntuación
  * @return El número de la puntuación. Si es 0 significa que ha habido un error
  */
  int Puntuacion(string palabra);
  typename set<Letra>::iterator begin();
  typename set<Letra>::iterator end();
  typename set<Letra>::const_iterator cbegin() const;
  typename set<Letra>::const_iterator cend() const;

  /**
  * @brief Devuelve la/s palabra/s con mayor puntuación y la puntuación
  * @param palabras Palabras de las cuales se sacan las que tienen mayor puntuación
  * @param modo L o P dependiendo si es por longitud o por puntuación
  * @pre modo debe ser L o P
  * @return Devuelve un pair formado por un entero con la puntuación y un set<string> con las palabras seleccionadas
  */
  pair<int,set<string> > MejoresPalabras (const set<string> & palabras, char modo);

  /**
  * @brief Calcula la frecuencia relativa de cada char del conjunto
  * @post Guarda cada frecuencia relativa en la Puntuacion de la letra
  */
  void CalcularPorcentaje();

};

#endif
