#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

string BinaryTree::inOrder(bool alpha) {
  string output;
  _inOrder(output, _root, alpha);
  if (!output.empty())
    output.pop_back();
  return output;
}

string BinaryTree::preOrder(bool alpha) {
  string output;
  _preOrder(output, _root, alpha);
  if (!output.empty())
    output.pop_back();
  return output;
}

void BinaryTree::_inOrder(string &output, Node *cur, bool alpha) {
  if (cur == NULL)
    return;

  _inOrder(output, cur->left, alpha);
  if (alpha) {
    string letter = {(char)cur->key};
    output.append("(" + letter + ", " + to_string(cur->count) + ")");
  } else {
    output.append(cur->print_key());
  }
  output.append(" ");
  _inOrder(output, cur->right, alpha);
}

void BinaryTree::_preOrder(string &output, Node *cur, bool alpha) {
  if (cur == NULL)
    return;

  if (alpha) {
    string letter = {(char)cur->key};
    output.append("(" + letter + ", " + to_string(cur->count) + ")");
  } else {
    output.append(cur->print_key());
  }
  output.append(" ");
  _preOrder(output, cur->left, alpha);
  _preOrder(output, cur->right, alpha);
}

int BinaryTree::findHeightOfNode(Node *node) {
  if (node == NULL) {
    return 0;
  }
  if (node->left == NULL && node->right == NULL) {
    return 0;
  }

  int left_height = findHeightOfNode(node->left);
  int right_height = findHeightOfNode(node->right);

  return 1 + max(left_height, right_height);
}

// method to find the node with the given value
Node *BinaryTree::findNode(Node *node, int key) {

  if (node == NULL) {
    return NULL;
  }
  if (node->key == key) {
    return node;
  }

  Node *left_child = findNode(node->left, key);
  if (left_child != NULL) {
    return left_child;
  }
  return findNode(node->right, key);
}
