/**
 * @file src/Tree.cpp
 * @author Gustavo Rivas Gervilla
 */

#include "Tree.h"
#include "Node.h"
#include "Diccionario.h"

using namespace std;

void Tree::print(ostream &os, const Node* node, int level) const{
  string separator = string(level, '\t');
  os << separator << node->get_label() << "|" << node->get_score() << endl;

  Node::const_iterator it;

  for (it = node->cbegin(); it != node->cend(); it++)
    print(os, *it, level + 1);
}


ostream& operator<<(ostream &os, const Tree &tree){
  tree.print(os, &tree.root, 0);

  return os;
}


Tree::Tree(){
  // no habría que ponerlo no?
}


// Este no lo veo
Tree::Tree(const Diccionario &d){
  Diccionario::iterator it_dicc;
  Node root('r'); // la r xq?

  // root children ?? //funcion it_dicc ??
  for (it_dicc = d.begin(); it_dicc != d.end(); ++it_dicc){
    root.aniadirPalabra((*it_dicc));
  }
}

  Node Tree::get_root(){
    return root;
  }

// Le metemos siempre primero un NULL para saber cuando llega al final?
  Tree::tree_iterator::tree_iterator(){
    node_stack.clear();
    node_stack.push(NULL);
  }

  bool Tree::tree_iterator::operator==(const tree_iterator &it){
    return (this->node_stack.top() == it.node_stack.top());
  }

  bool Tree::tree_iterator::operator!=(const tree_iterator &it){
    return(this->node_stack.top() != it.node_stack.top());
  }

  // no se si los iteradores habrá que ponerlos constantes, no los voy a poner si da problemas es aquí
  tree_iterator& Tree::tree_iterator::operator=(const tree_iterator &i){
    // Pensaba hacerlo con el constructor del nodo pero es que no se que coño hay que hacer la verdad
    Node * nodo = i.top();

  }

  Node* Tree::tree_iterator::operator*(){

  }

  tree_iterator& Tree::tree_iterator::operator++(){

  }

  tree_iterator& Tree::tree_iterator::operator--(){

  }

  tree_iterator Tree::begin(){

  }

  tree_iterator Tree::end(){

  }
