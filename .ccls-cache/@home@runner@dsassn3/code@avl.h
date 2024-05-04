#pragma once
#include "bst.h"

using namespace std;

class AVLTree : public BinarySearchTree {
public:
  AVLTree();
  ~AVLTree();

  void insert(char letter);
  void remove(Node *node);

  void printInOrder(ofstream &fout);
  void printPreOrder(ofstream &fout);
  void printFrequency(ofstream &fout);

private:
  /////////////////////////////////////////////////////////
  //////  TODO: Add private members if required ///////////
  void updateHeight(Node *node);
  void updateBF(Node *node);
  void checkBalance(Node *node, int count, int letter);
  void rotateLeft(Node *node);
  void rotateRight(Node *node);
  Node *search(Node *parent, Node *current, int count, int letter);
  void _printFrequency(string &output, Node *cur);
  void restore_avl(Node *violation);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};