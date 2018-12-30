/**
 * @file src/Node.cpp
 * @author Gustavo Rivas Gervilla
 */

#include "Node.h"

using namespace std;
//PRIVATE METHODS


bool Node::NodeComparator::operator()(const Node* node1, const Node* node2) const{
  return node1->score > node2->score;
}

void Node::update_child(Node* child){
  Node::Node_Set::const_iterator it;
  int new_score = child->score;

  for (it = children.begin(); it != children.end(); it++) //TODO mejorar el Nodo para que esta busqueda sea O(1) (uso de un unordered_set que funciona con una tabla hash).
    if ((*it)->label == child->label)
      break;

  children.erase(it);
  children.insert(child);

  if (new_score > score)
    set_score(new_score);
}


Node::Node(){
  label = 'a'; //puede que de problemas
  score = 0;
  parent = NULL;
  //children = NULL; //?¿
}

Node::Node(char label, int score){
  label = label;
  parent = NULL;
  score = score;
  //children = NULL //?¿
}

char Node::get_label() const{
  return label;
}

int Node::get_score() const{
  return score;
}

Node* Node::get_parent() const{
  return parent;
}


Node::Node_Set Node::get_children() const{
  return children;
}

/**
 * @brief Devuelve el hijo del nodo que posee la etiqueta indica, si existe.
 * @param label: La etiqueta por la que buscar.
 * @return El hijo con dicha etiqueta si existe.
 */
Node* Node::child(char label){

  /*Node nod_aux;
  nod_aux.label = label;

  return children.find(nod_aux);*/
  Node:: iterator itb;
  for (itb = children.begin(); itb != children.end(); itb++){
    if((**itb).label == label)
      return *itb;
  }
  return NULL;
}



/**
 * @brief Anade un hijo al nodo.
 * @param child: El nodo a anadir.
 */
void Node::add_child(Node* child){
  children.insert(child);
  child->parent = this; // no se si iria con * o sin el
}

/**
 * @brief Anade un padre al nodo.
 * @param parent: El padre del nodo.
 */
void Node::set_parent(Node* parent){
  parent = parent;
  //hay que hacer que padre apunte a hijo ?
  //parent.children.insert(this);
//  parent->children = (*this); //¿?
}

/**
 * @brief Asigna una puntuacion al nodo.
 * @param La nueva puntuacion del nodo.
 */
void Node::set_score(int score){
  score = score;
}

/**
 * @brief Devuelve el numero de hijos del nodo.
 * @return El numero de hijos del nodo.
 */
int Node::n_children() const{
  return children.size();
}

/**
   * @brief Nos dice si un nodo es hoja o no.
   * @return Un booleano indicando si el nodo es hoja.
   */
  bool Node::is_leaf() const{
    if (children.size() > 0)
      return false;
    return true;
  }

  /**
 * @brief Devuelve un iterador apuntando al comienzo de los hijos del nodo.
 * @return El iterador apuntando al comienzo de los hijos del nodo.
 */
Node::iterator Node::begin(){
  return children.begin();  // funcionara?
}

/**
 * @brief Devuelve un iterador apuntando al final de los hijos del nodo.
 * @return El iterador apuntando al final de los hijos del nodo.
 */
Node::iterator Node::end(){
  return children.end();
}
/**
   * @brief Devuelve un iterador constante apuntando al comienzo de los hijos del nodo.
   * @return El iterador constante apuntando al comienzo de los hijos del nodo.
   */
Node::const_iterator Node::cbegin() const{
  return children.begin(); //o .cbegin() ??
}

/**
 * @brief Devuelve un iterador constante apuntando al final de los hijos del nodo.
 * @return El iterador constante apuntando al final de los hijos del nodo.
 */
Node::const_iterator Node::cend() const{
  return children.end(); //?¿
}


/*ostream& Node::escribeNode(ostream &os){
  os << label;
  for (iterator it = children.begin(); it != children.end(); it++ ){
    (*(*it)).escribeNode(os);
  }
  return os;
}*/
// weuuuu
ostream& operator<<(ostream &os, const Node &node){
  os << node.label << endl;
  return os;
  //¿hay que sacar los hijos tambn?
  //return node.escribeNode(os); //puede petar :)
}



void Node::aniadirPalabra(string palabra){
  Node *hijo = NULL;

  if ((hijo = child(palabra[0])) != NULL){
    palabra = palabra.substr(1, palabra.size());
    (*hijo).aniadirPalabra(palabra);
  }
  else{
    if (palabra.size() > 1){
      Node* nod_aux;
      (*nod_aux).label = palabra[0];
      (*nod_aux).parent = this;
      children.insert(nod_aux);
      palabra = palabra.substr(1, palabra.size());
      (*child(palabra[0])).aniadirPalabra(palabra);
    }
    else{
      Node* nod_aux2;
      (*nod_aux2).label = palabra[0];
      (*nod_aux2).parent = this;
      children.insert(nod_aux2);
    }
  }
}
