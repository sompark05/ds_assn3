#include "avl.h"
#include "bst.h"
#include "tree.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

AVLTree::AVLTree() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  _root = NULL;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

AVLTree::~AVLTree() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void AVLTree::insert(char letter) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  // insert element
  Node *node = findNode(_root, letter);
  int count = 0;
  if (node != NULL) {
    count = node->count;
    remove(node);
  }
  node = new Node(letter, count + 1);

  if (_root == NULL) {
    _root = node;
  } else {
    Node *current = _root;
    while (true) {
      cout << "inside loop" << endl;
      if (node->count <
          current->count) { // when node->count is smalller than current->count
        if (current->left == NULL) {
          current->left = node;
          break;
        } else {
          current = current->left;
        }
      } else if (node->count > current->count) { // when node->count is greater
                                                 // than current->count
        if (current->right == NULL) {
          current->right = node;
          break;
        } else {
          current = current->right;
        }
      } else { // node->count equals current->count

        if (node->key <
            current->key) { // when node letter is smaller than current letter
          if (current->left == NULL) {
            current->left = node;
            break;
          } else {
            current = current->left;
          }
        } else { // when node letter is greater than current letter
          if (current->right == NULL) {
            current->right = node;
            break;
          } else {
            current = current->right;
          }
        }
      }
    }
  }
  // update height
  updateHeight(_root);
  updateBF(_root);
  // check balance
  checkBalance(_root, node->count, letter);
  cout << "finished check balance" << endl;

  // if (violation != NULL) {
  //   cout << "violation: " << violation << "  " << violation->key << endl;
  // }
  // // LL RR LR RL if necessary
  // if (violation != NULL) {
  //   cout << "where" << violation->right << endl;
  //   if (violation->right == NULL) {
  //     /********** RR **********/
  //     if (violation->left->right == NULL) {
  //       cout << "RR" << endl;
  //       rotateRight(violation);
  //     }
  //     /********** LR **********/
  //     else {
  //       cout << "LR" << endl;
  //       rotateLeft(violation->left);
  //       rotateRight(violation);
  //     }
  //   }
  //   cout << "here?" << endl;
  //   if (violation->left == NULL) {
  //     /********** LL **********/
  //     if (violation->right->left == NULL) {

  //       cout << "before" << endl;
  //       rotateLeft(violation);
  //       cout << "after" << endl;
  //     }
  //     /********** RL **********/
  //     else {
  //       cout << "RL" << endl;
  //       rotateRight(violation->right);
  //       rotateLeft(violation);
  //     }
  //   }
  // }
  cout << "root: " << _root << " " << _root->key << endl;
  return;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void AVLTree::remove(Node *node) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  Node *parent = search(NULL, _root, node->count, node->key);

  if (node->left == NULL && node->right == NULL) { // node has no child
    if (parent == NULL) {
      _root = NULL;
    } else if (parent->left == node) {
      parent->left = NULL;
    } else {
      parent->right = NULL;
    }

  } else if (node->left == NULL && node->right != NULL) { // node only has right
    if (parent == NULL) {
      _root = node->right;
    } else if (parent->left == node) {
      parent->left = node->right;
    } else {
      parent->right = node->right;
    }
  } else if (node->left == NULL &&
             node->right != NULL) { // node only has left child
    if (parent == NULL) {
      _root = node->left;
    } else if (parent->left == node) {
      parent->left = node->left;
    } else {
      parent->right = node->left;
    }
  } else { // node has both children
    Node *cur_parent = node;
    Node *current = node->right;
    int cnt = 0;
    while (current->left != NULL) {
      cur_parent = current;
      current = node->left;
      cnt++;
    }

    if (cnt > 0) {
      cur_parent->left = current->right;
    }

    if (parent == NULL) {

      _root = current;
      _root->left = node->left;
      if (cnt > 0) {
        _root->right = node->right;
      }

    } else if (parent->left != NULL && parent->left == node) {
      current->left = node->left;
      parent->left = current;
      if (parent->left != node->right) {
        parent->left->right = node->right;
      }

    } else {
      current->left = node->left;
      parent->right = current;
      if (parent->right != node->right) {
        parent->right->right = node->right;
      }
    }
  }

  delete node;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void AVLTree::printInOrder(ofstream &fout) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  fout << inOrder(true) << endl;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void AVLTree::printPreOrder(ofstream &fout) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  fout << preOrder(true) << endl;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
void AVLTree::printFrequency(ofstream &fout) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  string output;
  _printFrequency(output, _root);
  if (!output.empty())
    output.pop_back();
  fout << output << endl;
  ;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
void AVLTree::_printFrequency(string &output, Node *cur) {
  if (cur == NULL)
    return;

  _printFrequency(output, cur->right);

  string letter = {(char)cur->key};
  output.append("(" + letter + ", " + to_string(cur->count) + ")");

  output.append(" ");
  _printFrequency(output, cur->left);
}

void AVLTree::updateHeight(Node *node) {
  if (node == NULL) {
    return;
  }

  node->height = findHeightOfNode(node);
  updateHeight(node->left);
  updateHeight(node->right);
}
void AVLTree::updateBF(Node *node) {
  if (node == NULL) {
    return;
  }
  int left_height, right_height;

  if (node->left == NULL) {
    left_height = -1;
  } else {
    left_height = node->left->height;
  }
  if (node->right == NULL) {
    right_height = -1;
  } else {
    right_height = node->right->height;
  }

  node->bf = left_height - right_height;
  updateBF(node->left);
  updateBF(node->right);
}

void AVLTree::restore_avl(Node *violation) {
  updateHeight(_root);
  updateBF(_root);
  cout << "updated height" << endl;

  if (violation->bf > 1) { // right or left-right rotation
    if (violation->left->bf == 1) {
      rotateRight(violation);
    } else {
      cout << "rotate left " << endl;
      rotateLeft(violation->left);
      cout << "and then rotate right" << endl;
      rotateRight(violation);
    }
  } else {
    cout << "It's a me mario" << endl;
    if (violation->right->bf == -1) {
      rotateLeft(violation);
    } else {
      cout << "here" << endl;
      rotateRight(violation->right);
      rotateLeft(violation);
      cout << "not here" << endl;
    }
  }
  updateHeight(_root);
  updateBF(_root);
}
void AVLTree::checkBalance(Node *current, int count, int letter) {
  if (current->key == letter) {
    return;
  }

  Node *target;

  // when current count is smaller than target count
  if (current->count < count) {
    checkBalance(current->right, count, letter);
  }
  // when current count is greater than target count
  else if (current->count > count) {
    checkBalance(current->left, count, letter);
  }
  // when current count equals target count
  else {
    if (current->key <
        letter) { // when current letter is smaller than target letter
      checkBalance(current->right, count, letter);
    } else if (current->key >
               letter) { // when current letter is greater than target letter
      checkBalance(current->left, count, letter);
    }
  }
  int bf, left_height, right_height;

  if (current->left == NULL) {
    left_height = -1;
  } else {
    left_height = current->left->height;
  }
  if (current->right == NULL) {
    right_height = -1;
  } else {
    right_height = current->right->height;
  }

  bf = left_height - right_height;
  cout << char(current->key) << " bf: " << bf << endl;
  if (bf > 1 || bf < -1) {
    restore_avl(current);
  }
}

// Node *AVLTree::checkBalance(Node *node, int count, int letter) {
//   if (node == NULL) {
//     return NULL;
//   }

//   int bf, left_height, right_height;

//   if (node->left == NULL) {
//     left_height = -1;
//   } else {
//     left_height = node->left->height;
//   }
//   if (node->right == NULL) {
//     right_height = -1;
//   } else {
//     right_height = node->right->height;
//   }

//   bf = left_height - right_height;
//   cout << node << " " << node->key << "  bf: " << bf << endl;
//   cout << "left_height: " << left_height << endl;
//   cout << "right_height: " << right_height << endl;
//   cout << endl;
//   if (bf < -1 || bf > 1) {
//     return node;
//   } else {
//     if (count < node->count) {
//       return checkBalance(node->left, count, letter);
//     } else if (count > node->count) {
//       return checkBalance(node->right, count, letter);
//     } else {
//       if (letter < node->key) {
//         return checkBalance(node->left, count, letter);
//       } else if (letter > node->key) {
//         return checkBalance(node->right, count, letter);
//       }
//       return NULL;
//     }
//   }
// }

void AVLTree::rotateLeft(Node *node) {

  Node *parent = search(NULL, _root, node->count, node->key);
  Node *temp = node;

  cout << "node: " << node << " " << node->key << endl;
  if (parent == NULL) {
    _root = node->right;
    node->right = node->right->left;
    _root->left = temp;
  } else {

    cout << "parent: " << parent << " " << parent->key << endl;

    if (parent->right != NULL && parent->right->key == node->key) {
      cout << "it should be here" << endl;
      parent->right = node->right;
      node->right = node->right->left;
      parent->right->left = temp;

    } else if (parent->left->key == node->key) {

      parent->left = node->right;
      node->right = node->right->left;
      parent->left->left = temp;
    }
  }
  cout << endl;
}
void AVLTree::rotateRight(Node *node) {
  Node *parent = search(NULL, _root, node->count, node->key);
  Node *temp = node;
  cout << "root: " << _root << " " << _root->key << endl;
  cout << "luigi" << endl;
  if (parent == NULL) {
    cout << "parent is null" << endl;
    _root = node->left;
    node->left = node->left->right;
    _root->right = temp;
  } else {
    if (parent->right != NULL && parent->right->key == node->key) {
      cout << "asdlfkajsdlf" << endl;
      parent->right = node->left;
      node->left = node->left->right;
      parent->right->right = temp;

    } else if (parent->left->key == node->key) {
      parent->left = node->left;
      node->left = node->left->right;
      parent->left->right = temp;
    }
  }
}

Node *AVLTree::search(Node *parent, Node *current, int count, int letter) {
  if (current == NULL) {
    return current;
  }

  if (letter == current->key) {
    return parent;
  } else if (count < current->count) {
    return search(current, current->left, count, letter);
  } else if (count > current->count) {
    return search(current, current->right, count, letter);
  } else {
    if (letter < current->key) {
      return search(current, current->left, count, letter);
    } else {
      return search(current, current->right, count, letter);
    }
  }
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////