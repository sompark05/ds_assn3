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

int ClosedHashFunction::closedhashing(int key, int attempt) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  return -1;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int ClosedHashFunction::closedhashing1(int key, int d) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int sum = 0;
  string str_key = to_string(key);

  for (int i = 0; i < str_key.length(); i++) {
    sum += str_key[i] - '0';
  }

  return ((sum % this->index_size) + d) % this->index_size;
  ;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int ClosedHashFunction::closedhashing2(int attempt) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  return -1;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}