#pragma once
#include "open_hash_function.h"
#include <iostream>
#include <string>

using namespace std;

enum OpenTableState { OPEN_EMPTY, OPEN_OCCUPIED };

class HashNode {
public:
  int key;
  HashNode *next;
  bool deleted;
  HashNode(int key) {
    this->key = key;
    this->next = NULL;
    this->deleted = false;
  }
};

class OpenHashTable {
public:
  OpenHashTable(int table_size, OpenHashFunction *hf);
  ~OpenHashTable();

  void print_result(ostream &out);

  void insert(int key);
  void delete_(int key);

private:
  const int table_size;
  OpenHashFunction *hf;
  HashNode **table;
  OpenTableState *states;
  int collision;
  int longest;

  /////////////////////////////////////////////////////////
  //////  TODO: Add private members if required ///////////

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};
