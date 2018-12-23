/**
 * @file src/Tree.cpp
 * @author Gustavo Rivas Gervilla
 */

#include "Tree.h"

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
