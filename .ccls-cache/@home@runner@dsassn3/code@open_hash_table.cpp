#include "open_hash_table.h"
#include "open_hash_function.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

OpenHashTable::OpenHashTable(int table_size, OpenHashFunction *hf)
    : table_size(table_size) {
  this->hf = hf;
  this->collision = 0;
  this->longest = 0;
  table = new HashNode *[this->table_size];
  for (int i = 0; i < this->table_size; i++) {
    table[i] = NULL;
  }
  this->states = new OpenTableState[this->table_size];

  for (int i = 0; i < this->table_size; ++i) {
    this->states[i] = OPEN_EMPTY;
  }

  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

OpenHashTable::~OpenHashTable() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////

  delete[] table;
  delete[] this->states;
}

void OpenHashTable::print_result(ostream &out) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
  out << collision << " " << longest << endl;
}

void OpenHashTable::insert(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int hashed_index = hf->openhashing(key);

  if (states[hashed_index] == OPEN_EMPTY) {
    states[hashed_index] = OPEN_OCCUPIED;
    table[hashed_index] = new HashNode(key);

    if (longest == 0) {
      longest = 1;
    }
  } else {
    OpenHashTable::collision++;
    int chain = 1;
    int index = hashed_index;

    HashNode *node = table[hashed_index];
    while (true) {
      
      if (node->next == NULL) {
        break;
      }
      
      if (node->deleted == false) {
        chain++;
      }


      node = node->next;
      index++;
    }
    node->next = new HashNode(key);
    chain++;

    if (chain > longest) {
      longest = chain;
    }
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void OpenHashTable::delete_(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int hashed_index = hf->openhashing(key);
  HashNode *node = table[hashed_index];

  while (true) {
    if (node == NULL) {
      break;
    }

    if (node->key == key) {
      node->deleted = true;
      break;
    }
    node = node->next;
  }

  int new_longest = 0;
  
  for (int i = 0; i < table_size; i++) {
    int chain = 0;
    node = table[i];
    while (true) {
      if (node == NULL) {
        break;
      }
      if (node->deleted == false) {
        chain++;
      }
      node = node->next;
    }
    if (chain > new_longest) {
      new_longest = chain;
    }
  }
  longest = new_longest;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
