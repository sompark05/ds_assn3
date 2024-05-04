#pragma once
#include <string>

using namespace std;

class Node {
public:
  Node(int key, int count = 1, int bf = 0)
      : key(key), height(0), count(count), bf(bf), left(NULL), right(NULL) {}
  int key;
  int height;
  int count;
  int bf;
  Node *left;
  Node *right;
  /////////////////////////////////////////////////////////
  //////  TODO: Add public members if required ///////////

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////

  string print_key() { return to_string(key); };
};

class BinaryTree {
public:
  BinaryTree() { _root = NULL; };
  ~BinaryTree() {
    delete[] _root;
    _root = NULL;
  };
  string preOrder(bool alpha = false);
  string inOrder(bool alpha = false);

protected:
  Node *_root;
  int findHeightOfNode(Node *node);
  Node *findNode(Node *node, int key);

private:
  void _inOrder(string &output, Node *cur, bool alpha = false);
  void _preOrder(string &output, Node *cur, bool alpha = false);
};
