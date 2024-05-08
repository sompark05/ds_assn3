#include "closed_hash_table.h"
#include "closed_hash_function.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

ClosedHashTable::ClosedHashTable(int table_size, int k, int d1,
                                 ClosedHashFunction *hf)
    : table_size(table_size), k(k), d1(d1) {
  this->hf = hf;
  this->table = new int[this->table_size];
  this->states = new ClosedTableState[this->table_size - 1];
  random_per = new int[this->table_size];
  failed = false;
  shift_register(random_per, k, d1);
  for (int i = 0; i < this->table_size; ++i) {
    this->states[i] = CLOSED_EMPTY;
  }

  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

ClosedHashTable::~ClosedHashTable() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////

  delete[] this->table;
  delete[] this->states;
}

void ClosedHashTable::print_table(ostream &out) {
  for (int i = 0; i < this->table_size; i++) {
    out << i << ": ";
    if (this->states[i] == CLOSED_EMPTY)
      out << "EMPTY" << endl;
    else if (this->states[i] == CLOSED_OCCUPIED)
      out << this->table[i] << endl;
    else
      out << "UNKNOWN" << endl;
  }
  if (failed) {
    out << "FAIL";
  }
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  /*  Write your codes if you need  */

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void ClosedHashTable::insert(int key) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (failed) {
    return;
  }

  int collision = 0;
  int hashed_index = hf->closedhashing1(key, 0);
  if (states[hashed_index] == CLOSED_EMPTY) {
    table[hashed_index] = key;
    states[hashed_index] = CLOSED_OCCUPIED;
  } else {
    int new_hashed_index = hashed_index;
    int number = 0;
    while (states[new_hashed_index] == CLOSED_OCCUPIED) {
      new_hashed_index = hf->closedhashing1(key, random_per[collision]);

      if (new_hashed_index == hashed_index) {
        failed = true;
        break;
      }
      if (number > table_size) {
        failed = true;
        break;
      }
      number++;
      collision++;
      if (states[new_hashed_index] == CLOSED_EMPTY) {
        table[new_hashed_index] = key;
        states[new_hashed_index] = CLOSED_OCCUPIED;
        break;
      }
    }
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

void ClosedHashTable::shift_register(int *random_per, int k, int d1) {
  int cur_d = d1;
  for (int i = 0; i < table_size - 1; i++) {
    random_per[i] = cur_d;
    cur_d *= 2;
    if (cur_d >= table_size) {
      cur_d -= table_size;
      cur_d = cur_d ^ k;
    }
  }
}