#ifndef __NODE__
#define __NODE__
/**
 * @file inc/Node.h
 * @author Gustavo Rivas Gervilla
 */

#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

/**
 * @class Node
 * @brief Clase que representa un nodo del arbol.
 */
class Node{
private:
  /**
   * @brief El objeto que empleamos para ordenar los nodos cuando se insertan en un Node_Set.
   */
  struct NodeComparator{
    /**
     * @brief Comparador que nos dice si un nodo va antes que otro.
     * @param node1: El primer nodo a comparar.
     * @param node2: El segundo nodo a comparar.
     * @return Un booleano indicando si el primer nodo va antes que el segundo.
     */
    bool operator()(const Node* node1, const Node* node2) const;
  };

  typedef multiset<Node*, NodeComparator> Node_Set; /**< Tipo de objeto que es un conjunto de punteros a nodos.*/

  //he cambiado string label por char label no me mates (puede salir muy mal)
  char label; /**< La etiqueta del nodo.*/
  int score; /**< La puntuación de este nodo.*/
  Node* parent; /**< El padre de esto nodo.*/
  Node_Set children; /**< Los hijos de este nodo.*/

  /**
   * @brief Funcion que actualiza un hijo del nodo.
   * @param child: El hijo a actualizar.
   */
  void update_child(Node* child);

public:
  typedef Node_Set::iterator iterator; /**< Tipo para un iterador sobre un Node_Set*/
  typedef Node_Set::const_iterator const_iterator; /**< Tipo para un iterador constante sobre un Node_Set*/

  /**
   * @brief Constructor por defecto.
   */
  Node();

  /**
   * @brief Constructor primitivo.
   * @param label: La etiqueta del nodo.
   * @param score: La puntuacion del nodo.
   */
  Node(char label, int score = 0);

  /**
   * @brief Obtener la etiqueta del nodo.
   * @return La etiqueta del nodo.
   */
  char get_label() const;

  /**
   * @brief Obtener la puntuacion del nodo.
   * @return La puntuacion del nodo.
   */
  int get_score() const;

  /**
   * @brief Devuelve el padre del nodo.
   * @return El padre del nodo.
   */
  Node* get_parent() const;

  /**
   * @brief Devuelve los hijos del nodo.
   * @return Los hijos del nodo.
   */
  Node_Set get_children() const;

  /**
   * @brief Devuelve el hijo del nodo que posee la etiqueta indica, si existe.
   * @param label: La etiqueta por la que buscar.
   * @return El hijo con dicha etiqueta si existe.
   */
  Node* child(char label);

  /**
   * @brief Anade un hijo al nodo.
   * @param child: El nodo a anadir.
   */
  void add_child(Node* child);

  /**
   * @brief Anade un padre al nodo.
   * @param parent: El padre del nodo.
   */
  void set_parent(Node* parent);

  /**
   * @brief Asigna una puntuacion al nodo.
   * @param La nueva puntuacion del nodo.
   */
  void set_score(int score);

  /**
   * @brief Devuelve el numero de hijos del nodo.
   * @return El numero de hijos del nodo.
   */
  int n_children() const;

  /**
   * @brief Nos dice si un nodo es hoja o no.
   * @return Un booleano indicando si el nodo es hoja.
   */
  bool is_leaf() const;


  /**
   * @brief Devuelve un iterador apuntando al comienzo de los hijos del nodo.
   * @return El iterador apuntando al comienzo de los hijos del nodo.
   */
  iterator begin();

  /**
   * @brief Devuelve un iterador apuntando al final de los hijos del nodo.
   * @return El iterador apuntando al final de los hijos del nodo.
   */
  iterator end();

  /**
   * @brief Devuelve un iterador constante apuntando al comienzo de los hijos del nodo.
   * @return El iterador constante apuntando al comienzo de los hijos del nodo.
   */
  const_iterator cbegin() const;

  /**
   * @brief Devuelve un iterador constante apuntando al final de los hijos del nodo.
   * @return El iterador constante apuntando al final de los hijos del nodo.
   */
  const_iterator cend() const;


  /**
   * @brief Operador de lectura.
   * @param os: Flujo donde se lee.
   * @param node: Nodo a leer.
   * @return El flujo donde se lee.
   */
  friend ostream& operator<<(ostream &os, const Node &node);

  void aniadirPalabra(string palabra);

  ostream& escribeNode(ostream &os);
};

#endif
