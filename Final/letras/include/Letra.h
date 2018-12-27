/**
* @file Letra.h
* @brief Fichero cabecera del TDA Letra
* @authors Celia Arias Martínez
           Lucía Salamanca López
*/
#ifndef _Letra_h
#define _Letra_h

using namespace std;

class Letra{
private:
  char carac; ///< Carácter de la propia letra
  int cant;  ///< Cantidad de veces que puede aparecer
  int punt; ///< Puntuación de la letra

public:
  /**
  @brief Constructor por defecto
  **/
  Letra();
  /**
  * @brief Devuelve el carácter de la Letra
  * @return carácter del objeto
  */
  Letra(char caracter, int cantidad, int puntuacion);

  char Caracter()const{
    return carac;
  }
  /**
  * @brief Devuelve la cantidad de veces que aparece la letra
  * @return cantidad de veces que aparece la letra
  */
  int Cantidad()const{
    return cant;
  }

  /**
  * @brief Devuelve la puntuación de la letra
  * @return puntuación de la letra
  */
  int Puntuacion()const{
    return punt;
  }

  void setCaracter(char caract){
    carac = caract;
  }

  void setCantidad(int canti){
    cant = canti;
  }

  void setPuntuacion(int puntu){
    punt = puntu;
  }

  bool operator<(const Letra & letra_b) const;
  /**
  @brief Lee de un flujo de entrada un diccionario
  @param is:flujo de entrada
  @param let: el objeto donde se realiza la lectura.
  @return el flujo de entrada
  **/
  friend istream & operator>>(istream & is, Letra & let);
  /**
  @brief Escribe en un flujo de salida un diccionario
  @param os:flujo de salida
  @param let: el objeto letra que se escribe
  @return el flujo de salida
  **/
  friend ostream & operator<<(ostream & os, const Letra &let);

};

#endif
