
/**
 * @file inc/Tree.h
 * @author Gustavo Rivas Gervilla
 */

#ifndef TREE_H
#define TREE_H

#include <stack>
#include <string>
#include <vector>

#include "Node.h"
#include "Diccionario.h"

using namespace std;

/**
 * @class Tree
 * @brief Clase que modela un arbol generico de busqueda.
 */
class Tree{
private:
  Node root; /**< La raiz del arbol.*/

  /**
   * @brief Metodo que imprime el subarbol que cuelga de un nodo del arbol.
   * @param os: El flujo donde se imprime.
   * @param node: El nodo del que cuelga el subarbol.
   * @param level: El nivel en el que se encuentra el nodo en el subarbol.
   */
  void print(ostream &os, const Node* node, int level) const;

public:
  /**
   * @brief Constructor por defecto.
   */
  Tree();

  /**
   * @brief Constructor primitivo. Construye un arbol a partir de la informacion contenida en un Diccionario.
   * @param d: Diccionario que contiene la informacion con la que vamos a construir el arbol.
   */
  Tree(const Diccionario &d);

  /**
   * @brief Devuelve el nodo raiz del nodo.
   * @return Nodo raiz del arbol.
   */
  Node get_root();

  /**
   * @brief Iterador sobre el arbol.
   */
  class tree_iterator{
  private:
    /**
     * @brief Pila donde se almacenan los nodos por recorrer.
     */
    stack<Node*> node_stack;

    /**
     * @brief Constructor primitivo.
     * @param node: Nodo donde empezamos a iterar.
     */
    tree_iterator(Node);

    friend class Tree;
  public:
    /**
     * @brief Constructor por defecto.
     */
    tree_iterator();

    /**
     * @brief Operador de igualdad.
     * @param it: El iterador con el que comparar.
     * @return Un booleano indicando si los iteradores son equivalentes.
     */
    bool operator==(const tree_iterator &it);

    /**
     * @brief Operador de desigualdad.
     * @param it: El iterador con el que comparar.
     * @return Un booleano indicando si los iteradores no son equivalentes.
     */
    bool operator!=(const tree_iterator &it);

    /**
     * @brief Operador de asignacion.
     * @param it: El iterador a asignar.
     * @return El iterador a asignar.
     */
    tree_iterator& operator=(const tree_iterator &i);

    /**
     * @brief Operador *.
     * @return El nodo al que apunta el iterador.
     */
    Node* operator*();

    /**
     * @brief Operador ++.
     * @return El iterador.
     */
    tree_iterator& operator++();

    /**
     * @brief Operador --;
     * @return El iterador.
     */
    tree_iterator& operator--();
  };

  /**
   * @brief Devuelve un iterador apuntando a la raiz del arbol.
   * @return El iterador apuntando a la raiz del arbol.
   */
  tree_iterator begin();

  /**
   * @brief Devuelve un iterador apuntando al final del arbol.
   * @return El iterador apuntando al final del arbol.
   */
  tree_iterator end();

  /**
   * @brief Operador de lectura.
   * @param os: Flujo donde se lee.
   * @param tree: Arbol a leer.
   * @return El flujo donde se lee.
   */
  friend ostream& operator<<(ostream &os, const Tree &tree);

  void meterHijosBuenos();



};

#endif
