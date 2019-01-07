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
  double punt; ///< Puntuación de la letra

public:
  /**
  @brief Constructor por defecto
  **/
  Letra();
  /**
  * @brief Constructor a partir de un char, un int y un double
  * @param caracter char para el carac
  * @param cantidad entero para cant
  * @param puntuacion double para punt
  */
  Letra(char caracter, int cantidad, double puntuacion);
  /**
  * @brief Devuelve el carácter de la Letra
  * @return carácter del objeto
  */
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
  double Puntuacion()const{
    return punt;
  }
  /**
  * @brief Modifica el caracter la letra
  * @param caract Nuevo char para carac
  */
  void setCaracter(char caract){
    carac = caract;
  }
  /**
  * @brief Modifica la cantidad de la letra
  * @param caract Nuevo entero para cant
  */
  void setCantidad(int canti){
    cant = canti;
  }
  /**
  * @brief Modifica la puntuación de la letra
  * @param caract Nuevo double para punt
  */
  void setPuntuacion(double puntu){
    punt = puntu;
  }
  /**
  * @brief Operador de menor igual
  * @param letra_b Letra a comparar con this
  * return true si this <= letra_b, false en caso contrario
  */
  bool operator<=(const Letra & letra_b) const;
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
