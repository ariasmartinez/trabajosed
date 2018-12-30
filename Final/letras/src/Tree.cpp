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
  //jdsksdfj
}



Tree::Tree(const Diccionario &d){
  Diccionario::iterator it_dicc;
  Node root('r');

  // root children ?? //funcion it_dicc ??
  for (it_dicc = d.begin(); it_dicc != d.end(); ++it_dicc){
    root.aniadirPalabra((*it_dicc));
  }
}

  Node Tree::get_root(){
    return root;
  }


  Tree::tree_iterator::tree_iterator(){
    //inicializar pila
  }
