/**
* @file elemento.h
* @brief Fichero cabecera del struct elemento
* @authors Celia Arias Martínez
	   Lucía Salamanca López
*/
/**
 *  @brief T.D.A. elemento
 *
 *  El tipo de dato elemento está compuesto por un entero llamado ele, que identifica al elemento que queremos almacenar, y otro entero llamado máximo, que indicará el elemento máximo de la pila en el momento en el que el tipo de dato elemento es añadido a ella.
*/
typedef struct{
  int ele; ///<elemento a almacenar
  int maximo; ///<el máximo
}elemento;
