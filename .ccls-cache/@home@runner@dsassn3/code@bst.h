#pragma once
#include "tree.h"

using namespace std;

class BinarySearchTree : public BinaryTree {
public:
  BinarySearchTree(){};
  ~BinarySearchTree(){};

  int insertion(int key);
  int deletion(int key, Node *node);
  int sum(int key, Node *node);

  Node *get_root() { return _root; }

private:
  /////////////////////////////////////////////////////////
  //////  TODO: Add private members if required ///////////
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
protected:
  Node *search(Node *parent, Node *current, int key);
};