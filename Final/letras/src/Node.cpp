/**
 * @file src/Node.cpp
 * @author Gustavo Rivas Gervilla
 */

#include "Node.h"

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
