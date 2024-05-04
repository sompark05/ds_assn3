#include "bst.h"
#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
Node *BinarySearchTree::search(Node *parent, Node *current, int key) {
  if (current == NULL) {
    return current;
  }

  if (key == current->key) {
    return parent;
  } else if (key < current->key) {
    return search(current, current->left, key);
  } else {
    return search(current, current->right, key);
  }
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

int BinarySearchTree::insertion(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int status;

  Node *node = new Node(key);
  if (_root == NULL) {
    _root = node;
    status = 0;
  } else {
    Node *current = _root;
    while (true) {
      if (key == current->key) {
        status = -1;
        break;
      } else if (key < current->key) {
        if (current->left == NULL) {
          current->left = node;
          status = 0;
          break;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == NULL) {
          current->right = node;
          status = 0;
          break;
        } else {
          current = current->right;
        }
      }
    }
  }

  return status;
  ///////////      End of Implementation      /////////////
  ///////////////////////////////////////////////////////
}

int BinarySearchTree::deletion(int key, Node *node) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int status;

  if (node == NULL) {
    return -1;
  }

  if (key == node->key) { // if key equals node's key

    if (node->left == NULL) { // if node has right child or no child
      Node *parent = search(NULL, _root, key);

      if (parent == NULL) { // if node is root node
        _root = node->right;
      } else { // else
        if (parent->left == node) {
          parent->left = node->right;
        } else if (parent->right == node) {
          parent->right = node->right;
        }
      }
      delete node;
      return 0;
    } else if (node->right == NULL) { // if node has left child
      Node *parent = search(NULL, _root, key);

      if (parent == NULL) { // if node is root node
        _root = NULL;
      } else { // else
        if (parent->left == node) {
          parent->left = node->left;
        } else if (parent->right == node) {
          parent->right = node->left;
        }
        delete node;
      }
      return 0;
    } else { // if node has both children
      Node *parent = node;
      Node *current = node->right;
      while (true) {
        if (current->left == NULL) {
          break;
        }
        parent = current;
        current = current->left;
      }
      node->key = current->key;
      parent->left = current->right;
      delete current;
      return 0;
    }
  } else if (key < node->key) { // when key is smaller than node's key
    status = deletion(key, node->left);

  } else { // when key is larger than node's key
    status = deletion(key, node->right);
  }
  return status;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int BinarySearchTree::sum(int key, Node *node) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  if (node == NULL) {
    return 0;
  }

  if (key > node->key) {
    return sum(key, node->right);
  } else if (key < node->key) {
    return sum(key, node->left) + sum(key, node->right) + node->key;
  } else {
    return 0;
  }
  ///////////      End of Implementation      /////////////
  ///////////////////////////////////////////////////////
}